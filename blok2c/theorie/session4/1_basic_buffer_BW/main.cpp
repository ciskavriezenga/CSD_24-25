#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#define W 4
#define H 3

using namespace cv;

void logValues(uchar* &m, uint wStart, uint hStart, uint wEnd, uint hEnd) {
  std::cout << "\n________________ Values in matrix _________________\n";
  // iterate through array and log values
  for(uint j = hStart; j < hEnd; j++) {
    int yOffset = j * W;
    for(uint i = wStart; i < wEnd; i++) {
      std::cout << (int) m[i + yOffset] << ", ";
    }
    std::cout << "\n";
  }
  std::cout << "\n___________________________________________________\n";
}


void logValues(Mat &m, uint wStart, uint hStart, uint wEnd, uint hEnd) {
  std::cout << "\n________________ Values in matrix _________________\n";
  // iterate through array and log values
  for(uint j = hStart; j < hEnd; j++) {
    const uchar* row = m.ptr<uchar>(j);
    for(uint i = wStart; i < wEnd; i++) {
      // using the pointer is more efficient then using m.at<uint>(i, j)
      std::cout << (int) row[i] << ", ";
    }
    std::cout << "\n";
  }

  std::cout << "\n___________________________________________________\n";
}



int main( int argc, char **argv ){
  // create array to store pixels, set all pixels to 0
  uchar* buffer = new uchar[H * W];
  memset(buffer, 0, sizeof(uchar) * H * W );

  logValues(buffer, 0, 0, W, H);

  #if 0
  buffer[0] = (uchar)255;

  #else
    // loop through bytes
    for(int j = 0; j < H; j++) {
      int yOffset = j * W;
      std::cout << "\n";
      for(int i = 0; i < W; i++) {
        //percentages in range [0,1]
        float yPercentage = (float)(j + 1) / H;
        float xPercentage =  (float)(i + 1) / W;
        buffer[i + yOffset] = (uchar)(255.0f * yPercentage  * xPercentage);
      }
    }
  #endif

  logValues(buffer, 0, 0, W, H);

  // CV_8UC4
  // format: CV_<bit-depth>{U|S|F}C(<number_of_channels>)
  // CV_8UC4 results in: 8-bit unsigned integer matrix/image with 4 channels
  // NOTE: opencv first place rows, then columns
  Mat img = Mat( H, W, CV_8UC1, buffer);

  // log first 10x10 values in matrix --> all 0
  logValues(img, 0, 0, W, H);


  // ==========  show result ==========
  // scale image
  float scaleFactor = 100.0f;
  cv::resize(img, img, Size(), scaleFactor, scaleFactor, INTER_NEAREST);

  // create window and image matrix
  char window[] = "Drawing 2D";
  namedWindow( window, WINDOW_AUTOSIZE );
  imshow(window, img);
  waitKey( 0 );
  return 0;
}
