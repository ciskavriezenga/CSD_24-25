#ifndef _BACKGROUND_MODEL_H_
#define _BACKGROUND_MODEL_H_
#include "opencv2/core/core.hpp"
#include <opencv2/imgproc.hpp>
#include "opencv2/opencv.hpp"
#include <opencv2/highgui.hpp>
#include <iostream>


enum BGModelType : int {
  Average, // normal avarage and predefined threshold
  RunningAverage, // running average and predifened threshold
  Ffaad, // frame to frame average absolute differences --> mean and standard deviation of the image pixels
  GaussianModel, // mean and variance
  SDModel // mean and sd
};
using namespace cv;

class BGModelCreator {
public:
  /*
   * BackgroundModel constructor
   * captRefrnc: the opened VideoCapture
   * numberOfFrames: the number of frames to fetch from the presented video
   * modelType: the type of backgroundModel to create.
   * - Average: average pixel value and predefined threshold
   * - RunningAverage: the running average pixel value and predefined threshold
   * - Ffaad: average & frame to frame average absolute differences
   * - GaussianModel: average & variance
   * - SDModel: average & sd
   * outputImagePrefix: prefix for output image
   * runningAvAlpha: alpha value for the RunningAverage when using corresponding model type
   */
  BGModelCreator(cv::VideoCapture &captRefrnc, int numberOfFrames = 10,
    BGModelType modelType = BGModelType::Average,
    std::string outputPath = "", double runningAvAlpha = 0.5);


  // ===== public methods =====
  // getter method that allows you to grab the mean and sd Mat objects
  Mat getAverageModel();
  Mat getVarianceModel();

private:
  // ===== private methods =====
  /*
   * methods to calculate and finalize the background model
   */
  void processFrame(cv::Mat& frame, BGModelType modelType);
  void finalizeModel(BGModelType modelType, std::string outputPath);
  void addText(cv::Mat img, std::string text, cv::Point position, double fontScale = 1);
  /*
   * methods to calculate the different types of background models with
   */
  // basic calculation of sum
  void calcSum(cv::Mat& frame);
  // calculates the running average, stored to Mat object mean
  void calcRunningAverage(cv::Mat& frame);
  // calculates the Sum of the frame-to-frame average absolute difference
  void calcSumFfaad(cv::Mat& frame);
  // calculate the sum of the variance, used for the Gausian background model
  void calcSumVariance(cv::Mat& frame);
  // based on sum --> calculates the mean
  void calcMean();
  // based on ffaadSum --> calculates the ffaad
  void calcFfaad();
  // based on squareSum and regular sum --> calculates the variance
  void calcVariance();

  // writeResult: writes the passed result Mat object to an image file
  void writeResult(cv::Mat& result, std::string filePath);

  // default set to true, set to false after processing first frame
  bool firstFrame = true;

  /*
   * the Mat objects to store the sum, mean, tmp, ffaad, variance values
   */
  cv::Mat sum;
  cv::Mat mean;
  // ffaad Mat objects
  cv::Mat ffaad; // frame to frame average absolute differences
  cv::Mat ffaadSum;
  cv::Mat tempFrame; // used in Ffaad model type calculation
  cv::Mat absDiff;
  cv::Mat prevFrame;
  // variance used to calculate variance
  cv::Mat squareSum;
  cv::Mat variance;
  // sd
  cv::Mat sd;

  // the total analysed num frames
  int frameCount = 0;

  // output image prefix, used when storing the resulting model to image file(s)
  std::string outputImagePrefix;

  // running average alpha value
  double runningAvAlpha;

  // store background model type
  BGModelType modelType;
};

#endif
