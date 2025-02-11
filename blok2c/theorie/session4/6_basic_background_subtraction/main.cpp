#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/opencv.hpp"
#include <opencv2/highgui.hpp>
// include custom files
#include "bgSubtractorAverage.h"
#include "bgSubtractorSD.h"
#include "BGModelCreator.h"

#define AVERAGE_BG_SUBTRACTION 1
#define NUM_BG_FRAMES 3

using namespace cv;

typedef unsigned int uint;


int main( int argc, char **argv ){
  // ==========  read image ==========
  // Open a camera for video capturing (webcam at index 0, which is the internal camera or the only camera in the computer.)
  VideoCapture captRefrnc(0);
  //frames per second - limit
  const int fps = 30;
  char prevKeyPress = ' ';
  // check if the binding was successful
  if ( !captRefrnc.isOpened())
  {
    std::cout << "Could not retrieve a video capture reference\n";
    return -1;
  }



  // Allocate BGSubtractor base class pointer (two subclass options)
  BGSubtractor* bgSubstractor;

#if AVERAGE_BG_SUBTRACTION
  Mat bgAverage;
  std::string averageImgPath = "AverageBG.png";
  // load average background image
  bgAverage = imread(averageImgPath, IMREAD_COLOR);
  // create model
  if(!bgAverage.data) {
    std::cout << "\n****** no model exists, you need to create one ******\n";
    BGModelCreator bgModelCreator(captRefrnc, 10, BGModelType::Average);
    bgAverage = imread(averageImgPath, IMREAD_COLOR);
  }

  // 80 40 50 as thresholds for the H S V gave the based result
  bgSubstractor = new BGSubtractorAverage(200, 150, 150, averageImgPath);

#else
  Mat bgAverage, bgVariance;
  std::string averageImgPath = "AverageBG.png";
  std::string varianceImgPath = "VarianceBG.png";
  // load background images
  bgAverage = imread(averageImgPath, IMREAD_COLOR);
  bgVariance = imread(varianceImgPath, IMREAD_COLOR);
  // create model
  if(!bgAverage.data || !bgVariance.data) {
    BGModelCreator bgModelCreator(captRefrnc, 10, BGModelType::GaussianModel);
    bgAverage = bgModelCreator.getAverageModel();
    bgVariance = bgModelCreator.getVarianceModel();
  }
  /*
   * NOTE: using the variance image for the SD subtractor,
   * it is translated to SD in the subtractor object, see comments in
   * "bgSubtractorSD.h" file.
   */
  bgSubstractor = new BGSubtractorSD(100, averageImgPath, varianceImgPath,  Scalar(1.0, 1.0, 1.0));



#endif

  // allocate frame to store the webcame frame
  Mat frame, frame32, frameHSV, frameSubtracted, frameMasked;
  /*
   * Apply background subtraction
   */
  for(;;) // infinite loop
  {
    // quit if q key is pressedz
    if((int)prevKeyPress == 113) return 0;
    // retrieve input frame
    captRefrnc >> frame;

    // transform src to float values
    frame.convertTo(frame32, CV_32FC3);
    // transform to hsv
    cvtColor(frame32, frameHSV, COLOR_BGR2HSV);
    bgSubstractor->process(frameHSV, frameSubtracted);

    // retrieve original frame masked by binary background subtraction result
    frameMasked = Mat::zeros(frame.size(), CV_8UC(frame.channels()));
    frameSubtracted.convertTo(frameSubtracted,CV_8U);

    frame.copyTo(frameMasked, frameSubtracted);
    // display the image
    imshow("frame", frame);
    imshow("frameSubtracted", frameSubtracted);
    imshow("frameMasked", frameMasked);
    //get keyboard input
    prevKeyPress = waitKey(1000 / fps);

  }

  return 0;
}
