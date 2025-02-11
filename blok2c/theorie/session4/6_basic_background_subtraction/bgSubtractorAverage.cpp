#include "bgSubtractorAverage.h"

BGSubtractorAverage::BGSubtractorAverage(float thresholdH, float thresholdS,
                                         float thresholdV, std::string averageBgImgPath) : BGSubtractor(),
                                                                                           rangeLowChan(4), rangeHighChan(4)
/*
   * NOTE: 4 range channels instead of 3 (HSV=3) --> also using "third color threshold"
   * to allow a smaller change in color, but in combination with alteration in saturation
   * (also see comments in substractBG method)
   */
{
  std::vector<float> threshold(4);
  std::cout << "\nthresholdH: " << thresholdH << "\n";
  threshold[0] = thresholdH;
  threshold[1] = thresholdS;
  threshold[2] = thresholdV;

  retrieveBGModel(averageBgImgPath, threshold);
}

void BGSubtractorAverage::retrieveBGModel(std::string averageImgPath, std::vector<float> threshold)
{
  // Mat objects to temporarily store average background to
  Mat averageBgImg;
  // retrieve avarage background image in HSV
  loadAvarageBGImgHSV(averageImgPath, averageBgImg);
  // Mat vector to store average background image to in separate HSV channels
  std::vector<Mat> averageBgImgChan(3);
  // split average background image
  split(averageBgImg, averageBgImgChan);
  // retrieve low and high range;
  for (int i = 0; i < 3; i++)
  {
    float thresholdValue = threshold[i] / 2.0f;
    rangeLowChan[i] = averageBgImgChan[i] - thresholdValue;
    rangeHighChan[i] = averageBgImgChan[i] + thresholdValue;
  }

  float thresholdValue = threshold[0] / 6.0f;
  rangeLowChan[3] = averageBgImgChan[0] - thresholdValue;
  rangeHighChan[3] = averageBgImgChan[0] + thresholdValue;
}

void BGSubtractorAverage::loadAvarageBGImgHSV(std::string averageImgPath, Mat &averageBgImg)
{
  // temp Mat objects to store average background image to
  Mat bgAverage, bgAverage32;
  // load average background image
  bgAverage = imread(averageImgPath, IMREAD_COLOR);
  // check if we loaded the images succesfully
  if (!bgAverage.data)
  {
    std::cout << "No image data found for " << averageImgPath << "\n ";
    exit(1);
  }
  // transform to floats
  bgAverage.convertTo(bgAverage32, CV_32FC3);
  //transform to HSV
  cvtColor(bgAverage32, averageBgImg, COLOR_BGR2HSV);
}

void BGSubtractorAverage::substractBG(std::vector<Mat> &frameChannels, Mat &dst)
{
  Mat inRangeH, inRangeHThird, inRangeS, inRangeV, result, resultBrightness;
  /*
   * For each channel check if the input frame channel is in range of
   * [average - threshold, average + threshold]
   * results into 255 if in range --> if all, then --> background
   * (also see the next step)
   */
  inRange(frameChannels[0], rangeLowChan[0], rangeHighChan[0], inRangeH);
  inRange(frameChannels[1], rangeLowChan[1], rangeHighChan[1], inRangeS);
  inRange(frameChannels[2], rangeLowChan[2], rangeHighChan[2], inRangeV);
  // also check for a third color range, see comments below
  inRange(frameChannels[0], rangeLowChan[3], rangeHighChan[3], inRangeHThird);

  /*
   * There are multiple options for considering an object as foreground.
   * - When there is a large enough change in color.
   * - When there is a large enough change in saturation, resulting into 'more color'.
   *   However, we should then also consider the color, cause otherwise it
   *   could just be a shadow (shadows desaturate colors).
   * - When brightness changes a lot, this could correspond to changes in
   *   lightning / shadow, however, it could also be a foreground object in a
   *   similar color but of a different brightness.
   *
   * The thoughts above result into the following ruleset, a pixel is
   * considered to be part of the foreground if there is:
   * 1. Only a change in color
   * 2. Saturation change + (smaller) change in color (for now: third color range)
   * 3. Large enough brightness change with a smaller color change.
   *
   * NOTE regarding the ranges, from the opencv documentation:
   * "HSV, Hue range is [0,179], Saturation range is [0,255] and Value range is [0,255]." "
   */

  // check for situation 2. (saturation & color)
  // (max --> both low --> result = low (foreground after inversion), else high)
  max(inRangeHThird, inRangeS, result);
  // either situation 1 (color change) or 2.
  min(result, inRangeH, result);
  // check for situation 3. (brightness & color)
  max(inRangeHThird, inRangeV, resultBrightness);
  // either situation 1, 2, 3.
  min(result, resultBrightness, result);

  // inverse the result
  dst = 255 - result;
}

void BGSubtractorAverage::reduceNoise(Mat &src, Mat &dst)
{
  // TODO - implement
  Point anchorPoint = Point(-1, -1);
  Mat structureElement = getStructuringElement(MORPH_RECT, Size(3, 3), anchorPoint);

  Mat closed, eroded, dilated;
  //cv::morphologyEx(src, dst, MORPH_OPEN, structureElement, anchorPoint, 3);
  /*
   * apply closing with 2 iterations of 3x3 structure element
   * 1 iteration --> still contains holees
   * 2 iterations give best solution
   * 3 iterations or higher --> details of outer contour are lost
   */
  cv::morphologyEx(src, closed, MORPH_CLOSE, structureElement, anchorPoint, 2);

  /*
   * Apply opening by reconstruction of erosion
   * first apply erode to original src, to remove small structures
   * then reconstruct by applying dilation with a control image
   * as control image we use the results of the closing step above
   *
   * Eroded settings:
   * 1 iteration --> still contains noise
   * 2 iterations --> Arms partly disappear, noise is gone --> the one to use!
   * 3 iterations --> All noise is gone, but even more disapear
   */
  cv::erode(src, eroded, structureElement, anchorPoint, 2);
  cv::dilate(eroded, dilated, structureElement, anchorPoint,30);
  cv::bitwise_and(dilated, closed, dst);
}
