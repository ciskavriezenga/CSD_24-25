#include "BGModelCreator.h"

using namespace cv;

// helper function to add text on camera for camera calibration
void BGModelCreator::addText(cv::Mat img, std::string text, cv::Point position, double fontScale) {
  putText(img, text, position, cv::FONT_HERSHEY_COMPLEX, fontScale,
     cv::Scalar(255, 255, 255), 2, cv::LINE_AA);
}
// ===== Constructor =====
BGModelCreator::BGModelCreator(cv::VideoCapture &captRefrnc, int captureNumFrames,
  BGModelType modelType, std::string outputPath, double runningAvAlpha) : runningAvAlpha(runningAvAlpha),
  modelType(modelType)
{
  // be sure that video capture is opened
  if ( !captRefrnc.isOpened())
  {
    std::cout << "Could not retrieve a video capture reference\n";
    return;
  }

  // allocate Mat objects to store the current frame to
  Mat frame, frameWithText, frame32, frameHsv;

  std::cout << "\nStarting background model generation.";
  // 'iterate' through the video
  for(int i = 0; i < captureNumFrames; i++) {
    // retrieve input frame
    captRefrnc >> frameWithText;
    // add text to image, to tell user to press a key to take new img
    addText(frameWithText, "CREATING MEAN BACKGROUND IMAGE", Point(100,100));
    addText(frameWithText, "Press a key to take a new picture.", Point(100,175));
    addText(frameWithText, std::to_string(captureNumFrames - i) + " number of frames to go", Point(100,250));
    // display the image
    imshow("frame", frameWithText);
    // freeze. wait for user to press a key
    waitKey(0);
    captRefrnc >> frame;
    // transform frame to float values
    frame.convertTo(frame32, CV_32FC3);
    // transform to hsv
    cvtColor(frame32, frameHsv, COLOR_BGR2HSV);
    // calculation step for model calculation
    processFrame(frameHsv, modelType);
  }
  // finalize the background model
  finalizeModel(modelType, outputPath);
  // retrieve input frame
  captRefrnc >> frame;
  // add text to image, to tell user to press a key to take new img
  addText(frame, "CREATING MEAN BACKGROUND IMAGE", Point(100,100));
  addText(frame, "Background model creation succeeded.", Point(100,175));
  addText(frame, "Press a key to continue.", Point(100,250));
  // display the image
  imshow("frame", frame);
  // freeze. wait for user to press a key
  waitKey(0);
}


// ===== public methods =====
Mat BGModelCreator::getAverageModel() {
  return mean;
}

Mat BGModelCreator::getVarianceModel() {
  // be sure the current modeltype is the Gaussian model, otherwise --> error message and exit
  if(modelType != BGModelType::GaussianModel) {
    std::cout << "\nYou are trying to retrieve the variance model, but this is "
    << "not created with the current model type, you need to instantiate the "
    << "BGModelCreator with the GaussianModel type."
    << "Therefore this data is not available, exiting now.\n";
    exit(1);
  }
  return variance;
}

// ===== private methods =====
void BGModelCreator::processFrame(Mat& frame, BGModelType modelType)
{
  // depending on modelType, process the passed frame accordingly
  switch(modelType) {
    case(BGModelType::Average): {
      calcSum(frame);
    }
    break;
    case(BGModelType::RunningAverage): {
      calcRunningAverage(frame);
    }
    break;
    case(BGModelType::Ffaad): {
      calcSumFfaad(frame);
    }
    break;
    case(BGModelType::GaussianModel): {
      calcSumVariance(frame);
    }
    break;
    case(BGModelType::SDModel): {
      calcSumVariance(frame);
    }
    break;
  }
}

void BGModelCreator::finalizeModel(BGModelType modelType, std::string outputPath)
{
  // depending on modelType, finalize accordingly
  switch(modelType) {
    case(BGModelType::Average): {
      // based on the sum values, calculate the mean value
      calcMean();
      // store result to file
      writeResult(mean, outputPath + "AverageBG.png");
    }
    break;

    case(BGModelType::RunningAverage): {
      // NOTE:  calcRunningAverage immediately calculates mean
      // so no separate call to calcMean necessary

      // store result to file
      writeResult(mean, outputPath + "RunningAverageBG.png");
    }
    break;

    case(BGModelType::Ffaad): {
      calcMean();
      calcFfaad();
      // store results to file
      writeResult(mean, outputPath + "AverageBG.png");
      writeResult(ffaad, outputPath + "FfaadBG.png");
    }
    break;
    case(BGModelType::GaussianModel): {
      calcMean();
      calcVariance();
      // store results to file
      writeResult(mean, outputPath + "AverageBG.png");
      writeResult(variance, outputPath + "VarianceBG.png");
    }
    break;

    case(BGModelType::SDModel): {
      Mat sd; // to store square root of variance to
      calcMean();
      calcVariance();
      // take the square root of the variance --> sd
      sqrt(variance, sd);
      // store results to file
      writeResult(mean, outputPath + "AverageBG.png");
      writeResult(sd, outputPath + "SDBG.png");

    }
    break;
  }
}

void BGModelCreator::calcSum(Mat& frame)
{
  // if Mat object sum is empty, assign new mat object
  if(sum.empty()) {
    sum = Mat::zeros(frame.size(), CV_32FC(frame.channels()));
  }
  accumulate(frame, sum);
  frameCount++;
}


void BGModelCreator::calcRunningAverage(Mat& frame)
{

  // if Mat object mean is empty, take first frame as starting point
  if(mean.empty()) {
    frame.convertTo(mean, CV_32F);
  }
  accumulateWeighted(frame, mean, runningAvAlpha);
}


void BGModelCreator::calcSumFfaad(Mat& frame)
{
  // if Mat object sum is empty, assign new mat object to sum and ffaad
  if(sum.empty()) {
    sum = Mat::zeros(frame.size(), CV_32FC(frame.channels()));
    ffaadSum = Mat::zeros(frame.size(), CV_32FC(frame.channels()));
  }
  frame.convertTo(tempFrame, CV_32F);
  if(!firstFrame){
    sum += tempFrame;
    absdiff(tempFrame, prevFrame, absDiff);
    ffaadSum += absDiff;
    frameCount++;
  }
  firstFrame = false;
  prevFrame = tempFrame;
}


void BGModelCreator::calcSumVariance(Mat& frame)
{
  // if Mat object sum is empty, assign new mat object to sum and squareSum
  if(sum.empty()) {
    sum = Mat::zeros(frame.size(), CV_32FC(frame.channels()));
    squareSum = Mat::zeros(frame.size(), CV_32FC(frame.channels()));
  }
  accumulate(frame, sum);
  accumulateSquare(frame, squareSum);
  frameCount++;
}


void BGModelCreator::calcMean()
{
  std::cout << "\nFramecount: " << frameCount << "\n";
  mean = sum / (float)frameCount;
}


void BGModelCreator::calcFfaad()
{
  ffaad = ffaadSum / frameCount;
}


void BGModelCreator::calcVariance()
{
  // cache 1 / frameCount
  double oneByFrameCount = 1.0 / frameCount;
  variance = oneByFrameCount * squareSum;
  variance = variance - (oneByFrameCount * oneByFrameCount) * sum.mul(sum);
}


void BGModelCreator::writeResult(Mat& result, std::string filePath) {
  // object to store the result as BGR
  Mat temp;
  // transform the mean back to BGR and store to file
  cvtColor(result, temp, COLOR_HSV2BGR);
  imwrite(filePath, temp);
}
