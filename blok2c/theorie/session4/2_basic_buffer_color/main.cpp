#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#define W 400
#define H 300


using namespace cv;

typedef unsigned int uint;

void logValues(uint* &m, uint wStart, uint hStart, uint wEnd, uint hEnd) {
  std::cout << "\n________________ Values in matrix _________________\n";
  for(int i = hStart; i < hEnd; i++) {
    int yOffset = i * W;
    for(int j = wStart; j < wEnd; j++) {
      // using the pointer is more efficient then using m.at<uint>(i, j)
      std::cout << m[j + yOffset] << ", ";
    }
    std::cout << "\n";
  }
  std::cout << "\n___________________________________________________\n";
}


void logValues(Mat &m, uint wStart, uint hStart, uint wEnd, uint hEnd) {
  std::cout << "\n________________ Values in matrix _________________\n";
  for(int i = hStart; i < hEnd; i++) {
    const uint* row = m.ptr<uint>(i);
    for(int j = wStart; j < wEnd; j++) {
      // using the pointer is more efficient then using m.at<uint>(i, j)
      std::cout << row[j] << ", ";
    }
    std::cout << "\n";
  }
  std::cout << "\n___________________________________________________\n";
}



int main( int argc, char **argv ){
  // create array to store pixels
  uint* buffer = new uint[H * W];

  #if 0
  // loop through pixels and set color
  uint red = 255;
  uint green = 0;
  uint blue = 255;

  for(int i = 0; i < H; i++) {
    int yOffset = i * W;
    for(int j = 0; j < W; j++) {
      //uint --> a R G B
      buffer[j + yOffset] = (red << 16) + (green << 8) + blue;
    }
  }
  #elif 0
  // loop through pixels and set color
  uint red = 255;
  uint green = 0;
  uint blue = 255;

  for(int i = 0; i < H; i++) {
    int yOffset = i * W;
    for(int j = 0; j < W; j++) {
      uint r = (uint)(red * (float)(i + 1)/ H * (float)(j + 1) / W);
      uint g = (uint)(green * (float)(i + 1)/ H * (float)(j + 1) / W);
      uint b = (uint)(blue * (float)(i + 1)/ H * (float)(j + 1) / W);
      buffer[j + yOffset] = (r << 16) + (g << 8) + b;
    }
  }
  #elif 1
  // loop through separate bytes (uchar)
  uchar* bufferUchar = (uchar*)buffer;
  int w4 = W * 4;
  for(int i = 0; i < H; i++) {
    int yOffset = i * w4;
    for(int j = 0; j < w4; j+=4) {
      bufferUchar[j + yOffset] = (uchar)255;
    }
  }
  #endif

  logValues(buffer, W - 10, H - 10, W, H);



  // CV_8UC4
  // format: CV_<bit-depth>{U|S|F}C(<number_of_channels>)
  // CV_8UC4 results in: 8-bit unsigned integer matrix/image with 4 channels
  // NOTE: opencv first place rows, then columns
  Mat img = Mat( H, W, CV_8UC4, (uchar*)buffer);

  // log first 10x10 values in matrix --> all 0
  logValues(img, W - 10, H - 10, W, H);



  // ==========  show result ==========
  // create window and image matrix
  char window[] = "Drawing 2D";
  imshow(window, img);
  waitKey( 0 );
  return 0;
}
