#ifndef _BACKGROUND_SUBTRACTOR_VARIANCE_H_
#define _BACKGROUND_SUBTRACTOR_VARIANCE_H_

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

// include custom clasess
#include "bgSubtractor.h"


/*
 * BGSubtractorSD is a subclass of the BGSubstractor class
 * It loads an mean and sd image (created with the BackgroundModel class in the
 * calibrate directory).
 * Inside the substractBG method, the following formula is applied to each frame channel:
 * channelScore[i] = (mean[i] - frame[i]) / sd[i]
 * Then a 'zScore'-like value is calculated as follow:
 * zScore = sqrt(channelScore[0]^2 + channelScore[1]^2 + channelScore[2]^2)
 * Next, the zScore is compared to the zThreshold (passed to the constructor).
 * If the calculated zScore is high enough a pixel is marked as foreground.
 */
class BGSubtractorSD : public BGSubtractor{
public:

  /*
   * BGSubtractorSD constructor
   * zTrheshold:  the zThreshold used to check if a pixel belongs to the
   *              foreground or background.
   * meanImgPath: the filepath to the mean image
   * varImagePath:the filepath to the variance image
   * sdThreshold: the threshold to apply to all sd values, to prevent a to sensitive
   *              background substraction process.
   *
   * NOTE: we use the variance image instead of the sd image. We then calculate
   * the sd values in this class itself. This is because of precission reduction
   * due to storing the background model as an image.
   * Because we clip all values below 1 to 1, the loss of precision in really low
   * values is less important. But by using the variance image instead of the
   * sd image we get a higher precision for the values above 1.
   */
  BGSubtractorSD(float zThreshold, std::string meanImgPath,
    std::string varianceImgPath, Scalar sdThreshold = Scalar(1.0, 1.0, 1.0));

protected:
  /*
   * retrieveBGModel: used by the constructor, to load the background model
   * meanImgPath: the filepath to the mean image
   * varImagePath:the filepath to the variance image
   * sdThreshold: the threshold to apply to all sd values, to prevent a to sensitive
   *              background substraction process.
   */
  void retrieveBGModel(std::string meanImgPath, std::string varianceImgPath, Scalar sdThreshold);

  /*
   * loadModelImages: loads the model images (mean and variance (transformed to sd))
   * this method is called by the retrieveBGModel method
   */
  void loadModelImages(std::string meanImgPath, std::string varianceImgPath, Mat& mean, Mat& sd);
  /*
   * substractBG: substracts the background, resulting in an binary image
   * with foreground pixels set to 255.
   * frameChannels: the image to apply the background substraction to
   * dst: the Mat object to store the resulting binary image to
   * NOTE: This method is called by the base class BGSubtractor::process method.
   * This base class process method will call the reduceNoise method afterwards,
   * which is not overridden by this BGSubstractorSD subclass, so the reduceNoise
   * of the base class will be used.
   */
  void substractBG(std::vector<Mat>& frameChannels, Mat& dst) override;

  /*
   * reduceNoise: applies morphology filters to reduce the noise.
   * (called by the base class process method).
   */
  void reduceNoise(Mat& src, Mat& dst) override;

  // the threshold to use inside the substractBG method
  float zThreshold;

  // channels of Mat objects to store the mean and sd values to
  std::vector<Mat> meanChannels;
  std::vector<Mat> sdChannels;
};

#endif
