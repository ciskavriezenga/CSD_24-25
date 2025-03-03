#ifndef _BACKGROUND_SUBTRACTOR_AVERAGE_H_
#define _BACKGROUND_SUBTRACTOR_AVERAGE_H_

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

// include custom clasess
#include "bgSubtractor.h"

/*
 * BGSubtractorSD is a subclass of the BGSubstractor class
 * It loads an average image (created with the BackgroundModel class in the
 * calibrate directory). This average image is used in the substractBG method
 * to substract the background from the passed frame channels (called by the
 * base class process method). Next, the reduceNoise method is called to apply
 * morphology filters to reduce the noise.
 */
class BGSubtractorAverage : public BGSubtractor{
public:

  /*
   * Constructor of the BGSubtractorAverage class
   * thresholdH, thresholdS, thresholdV: threshold values for the three channels (HSV)
   * averageImgPath: the filepath to the average image, used together with the
   * thresholds to substract the background.
   */
  BGSubtractorAverage(float thresholdH, float thresholdS, float thresholdV, std::string averageImgPath);

protected:
  /*
   * retrieveBGModel: The mean image values together with the threshold values
   * are transformed into low and high range values, to allow usage of the
   * cv::inRange function.
   * averageImgPath: the filepath to the average image
   * threshold: the a threshold vector, one threshold for each channel (HSV)
   */
  void retrieveBGModel(std::string averageImgPath, std::vector<float> threshold);

  /*
   * loadAvarageBGImgHSV: loads the image at the passed path as hsv image
   * averageImgPath: the filepath to the average image
   * averageBgImg: the dst Mat object for the average background image
   */
  void loadAvarageBGImgHSV(std::string averageImgPath, Mat& averageBgImg);

  /*
   * substractBG: substracts the background from the passed frame channels
   * (called by the base class process method).
   */
  void substractBG(std::vector<Mat>& frameChannels, Mat& dst) override;

  /*
   * reduceNoise: applies morphology filters to reduce the noise.
   * (called by the base class process method).
   */
  void reduceNoise(Mat& src, Mat& dst) override;

  /*
   * low and high range values, based on mean values and threshold,
   * used with the cv::inRange function.
   */
  // rangeLowC: range - low values in separate HSV channels
  std::vector<Mat> rangeLowChan;
  // rangeLowC: range - high values in separate HSV channels
  std::vector<Mat> rangeHighChan;
};

#endif
