#ifndef _BACKGROUND_SUBTRACTOR_H_
#define _BACKGROUND_SUBTRACTOR_H_

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;

/*
 * abstract BGSubtractor class
 * subclasses: BGSubtractorAverage and BGSubtractorVariance, sharing the same reductNoise method
 */
class BGSubtractor {
public:
  // ===== Constructor and destructor =====
  BGSubtractor();
  virtual ~BGSubtractor();

  // ===== public methods =====
  /*
   * process, substract background model and reduces noise from src:
   * - calls the substractBG (abstract method overridden by subclasses)
   * - calls the reduceNoise method.
   * results are set to dst parameter.
   */
  void process(cv::Mat& src, cv::Mat& dst);

protected:
  // ===== protected methods =====
  /*
   * substractBG: subtracts the background from the foreground, results in a
   * binary image.
   * pure virtual function: needs to be implemented by the subclass
   */
  virtual void substractBG(std::vector<cv::Mat>& frameChannels, cv::Mat& dst) = 0;

  /*
   * reduceNoise: called by the process method after subtracting the background
   * to reduce the noise in the binary foreground/background image.
   * virtual function: can be overridden by the subclass
   */
  virtual void reduceNoise(cv::Mat& src, cv::Mat& dst);

};

#endif
