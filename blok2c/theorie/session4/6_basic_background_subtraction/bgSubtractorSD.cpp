#include "bgSubtractorSD.h"

BGSubtractorSD::BGSubtractorSD(float zThreshold, std::string meanImgPath,
                               std::string sdImgPath, Scalar sdThreshold) : BGSubtractor(),
                                                                            zThreshold(zThreshold), meanChannels(3), sdChannels(3)
{
  retrieveBGModel(meanImgPath, sdImgPath, sdThreshold);
}

void BGSubtractorSD::retrieveBGModel(std::string meanImgPath, std::string sdImgPath, Scalar sdThreshold)
{
  // load bg mean and sd image
  Mat mean, sd;
  loadModelImages(meanImgPath, sdImgPath, mean, sd);

  // split background model mean and sd in separate channels
  split(mean, meanChannels);
  split(sd, sdChannels);

  /*
   * Threshold the sd values in the sd channels to prevend too low sd values,
   * because sd values < 0 can result in a too noisy foreground.
   */
  Mat threshold(sd.size(), CV_32FC(sd.channels()), sdThreshold);
  std::vector<Mat> thresholdChannels;
  split(threshold, thresholdChannels);
  // threshold the sd values: apply max to sdChannels with sd threshold values
  for (int i = 0; i < 3; i++)
  {
    max(sdChannels[i], thresholdChannels[i], sdChannels[i]);
  }
}

void BGSubtractorSD::loadModelImages(std::string meanImgPath, std::string sdImgPath, Mat &mean, Mat &sd)
{
  mean = imread(meanImgPath, IMREAD_COLOR);
  sd = imread(sdImgPath, IMREAD_COLOR);
  // check if we loaded the images succesfully
  if (!mean.data || !sd.data)
  {
    std::cout << " No image data found for " << meanImgPath
              << " or " << sdImgPath << "\n ";
    exit(1);
  }
  // transform to floats
  mean.convertTo(mean, CV_32FC3);
  sd.convertTo(sd, CV_32FC3);
  //transform to HSV
  cvtColor(mean, mean, COLOR_BGR2HSV);
  cvtColor(sd, sd, COLOR_BGR2HSV);
}

void BGSubtractorSD::substractBG(std::vector<Mat> &frameChannels, Mat &dst)
{
  // calculate (mean - frame) / sd for all channels (HSV)
  Mat hDiff, sDiff, vDiff, hScore, sScore, vScore, zScore;
  absdiff(frameChannels[0], meanChannels[0], hDiff);
  absdiff(frameChannels[1], meanChannels[1], sDiff);
  absdiff(frameChannels[2], meanChannels[2], vDiff);
  hScore = hDiff / sdChannels[0];
  sScore = sDiff / sdChannels[1];
  vScore = vDiff / sdChannels[2];

  sqrt(hScore.mul(hScore) + sScore.mul(sScore) + vScore.mul(vScore), zScore);
  threshold(zScore, dst, zThreshold, 255, THRESH_BINARY);
}


void BGSubtractorSD::reduceNoise(Mat &src, Mat &dst)
{

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
  cv::morphologyEx(src, closed, MORPH_CLOSE, structureElement, anchorPoint, 3);

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
  cv::dilate(eroded, dilated, structureElement, anchorPoint,10);
  cv::bitwise_and(dilated, closed, dst);
}
