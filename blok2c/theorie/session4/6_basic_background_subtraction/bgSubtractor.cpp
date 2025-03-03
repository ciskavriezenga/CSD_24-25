#include "bgSubtractor.h"


// ===== Constructor and destructor =====
BGSubtractor::BGSubtractor() {}
BGSubtractor::~BGSubtractor() {}


// ===== public methods =====
void BGSubtractor::process(Mat& src, Mat& dst)
{
  // split src Mat object to separate channels
  std::vector<cv::Mat> frameChannels(3);
  split(src, frameChannels);
  // first substract the background from the src
  substractBG(frameChannels, dst);
  // next, reduce noise
  reduceNoise(dst, dst);
}

// ===== protected methods =====
void BGSubtractor::reduceNoise(Mat& src, Mat& dst)
{
  Point anchorPoint = Point(-1, -1);
  // get structure element
  Mat structureElement = getStructuringElement(MORPH_RECT, Size(3, 3), anchorPoint);

  Mat closed;
  /*
   * apply closing with 2 iterations of 3x3 structure element
   * 1 iteration --> still contains holees
   * 2 iterations give best solution
   * 3 iterations or higher --> details of outer contour are lost
   */
  cv::morphologyEx(src, closed, MORPH_CLOSE, structureElement, anchorPoint, 2);
  cv::morphologyEx(closed, dst, MORPH_OPEN, structureElement, anchorPoint, 3);
}
