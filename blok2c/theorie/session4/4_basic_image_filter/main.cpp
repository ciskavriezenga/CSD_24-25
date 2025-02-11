#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#define REDMASK	(0xff0000)
#define GREENMASK (0x00ff00)
#define BLUEMASK (0x0000ff)



using namespace cv;

typedef unsigned int uint;


void logValues(Mat &m, float wStart, float hStart, float wEnd, float hEnd) {
  std::cout << "\n________________ Values in matrix _________________\n";
  // iterate through array and log values
  for(int i = hStart; i < hEnd; i++) {
    const float* row = m.ptr<float>(i);
    for(int j = wStart; j < wEnd; j++) {
      // using the pointer is more efficient then using m.at<float>(i, j)
      std::cout <<  row[j] << ", ";
    }
    std::cout << "\n";
  }
  std::cout << "\n___________________________________________________\n";
}

// float Matrix
void applyKernel(Mat &src, Mat &dst, float kernel[][3]) {
  int w = src.size().width;
  int h = src.size().height;
  int wEnd = w - 1;
  int hEnd = h - 1;

  // apply kernel
  for(int i = 1; i < hEnd; i++) {
    const float* rowSrc = src.ptr<float>(i);
    float* rowDst= dst.ptr<float>(i);
    for(int j = 1; j < wEnd; j++) {
      float result = 0;
      for(int v = 0; v < 3; v++) {
        for(int u = 0; u < 3; u++) {
          // using the pointer is more efficient then using m.at<float>(i, j)
          result += rowSrc[j + (v - 1) * w + u] * kernel[v][u];
        }
      } // end u v for loops
      rowDst[j]  = result;
    }
  }
}

void addImages(Mat &src1, Mat &src2, Mat &dst) {
  // NOTE - no check for same size --> error prone
  int w = src1.size().width;
  int h = src1.size().height;

  for(int i = 0; i < h; i++) {
    const float* rowSrc1 = src1.ptr<float>(i);
    const float* rowSrc2 = src2.ptr<float>(i);
    float* rowDst = dst.ptr<float>(i);
    for(int j = 0; j < w; j++) {
      rowDst[j]  = rowSrc1[j] + rowSrc2[j];
    }
  }
}

void toBinary(Mat &src, Mat &dst, float threshold) {
  // ==========  transform to binary image ==========
  // get height and width matrix
  int w = src.size().width;
  int h = src.size().height;

  for(int i = 0; i < h; i++) {
    const float* rowSrc = src.ptr<float>(i);
    float* rowDst = dst.ptr<float>(i);
    for(int j = 0; j < w; j++) {
      rowSrc[j] > threshold ? rowDst[j] = 1.0f : rowDst[j] = 0.0f;
    }
  }
}


int main( int argc, char **argv ){
  if(argv[1] == NULL) {
    std::cout << "\nPlease add a path to an image when running this program!\n\n";
    return 0;
  }
  char* imageName = argv[1];

  Mat image, grayImg, imgBlurred, lineDetectionX, lineDetectionY,
    lineDetectionXY, lineDetectionXYBinary;
  // read image
  image = imread( imageName, IMREAD_COLOR );
  if( argc != 2 || !image.data )
  {
   printf( " No image data \n " );
   return -1;
  }

  cvtColor( image, grayImg, COLOR_BGR2GRAY);

  // convert from uchar [0, 255] to float values [0,1]
  // because imshow opencv function expects [0.0f, 1.0f] if data is in floats
  grayImg.convertTo(grayImg,CV_32F);
  // multiplication with reciprocal is more efficient
  grayImg = grayImg * (1.0f/255.0f);
  imgBlurred = Mat(grayImg.size(), grayImg.type());
  lineDetectionX = Mat(grayImg.size(), grayImg.type());
  lineDetectionY = Mat(grayImg.size(), grayImg.type());
  lineDetectionXY = Mat(grayImg.size(), grayImg.type());
  lineDetectionXYBinary = Mat(grayImg.size(), grayImg.type());
  // ==========  apply filter result ==========

  // allocate gaussian filter kernel of 3 x 3


  // TODO 2025 - create slides.
  //  The kernel is applied to a set of pixels 3 x 3
  // the result of the multiplication of the 3x3 kernel and the neigbor pixels
  // is written in the new matrix at the 'center spot'
  float gaussianKernel[3][3] =
  {
    { 0.0625f, 0.125f + 0.0625f,  0.0625f},
    { 0.125f + 0.0625f,  0.0f,   0.125f + 0.0625f},
    { 0.0625f, 0.125f + 0.0625f,  0.0625f}
  };

  float sobelXkernel[3][3] =
  {
    { -1.0f,  0.0f,  1.0f},
    { -2.0f,  0.0f,  2.0f},
    { -1.0f,  0.0f,  1.0f}
  };

  float sobelYkernel[3][3] =
  {
    {-1.0f,  -2.0f,  -1.0f},
    { 0.0f,   0.0f,   0.0f},
    { 1.0f,   2.0f,   1.0f}
  };

  applyKernel(grayImg, imgBlurred, gaussianKernel);
  applyKernel(grayImg, imgBlurred, gaussianKernel);


  applyKernel(grayImg, lineDetectionX, sobelXkernel);
  applyKernel(grayImg, lineDetectionY, sobelYkernel);
  // map values to pixel values    [-..., + ... ] --> [0, 1]
  // current range = [-4.0f, 4.0f], so:
  // absolute value and multiply with 0.25
  lineDetectionX = abs(lineDetectionX);
  lineDetectionX *= 0.25;
  lineDetectionX = abs(lineDetectionY);
  lineDetectionY *= 0.25;
  addImages(lineDetectionX, lineDetectionY, lineDetectionXY);
  toBinary(lineDetectionXY, lineDetectionXYBinary, 0.85);
  // ==========  show result ==========
  // namedWindow - usually used when creating a window with options
  // imshow is sufficient to just show an image
  namedWindow( "image", WINDOW_AUTOSIZE );
  namedWindow( "Gray image", WINDOW_AUTOSIZE );
  // imshow( "image", image );
  imshow( "Gray image", grayImg );
  imshow( "Blurred gray image", imgBlurred );

  imshow( "Line detection X", lineDetectionX );
  imshow( "Line detection Y", lineDetectionY );
  imshow( "Line detection X and Y", lineDetectionXY );
  imshow( "Binary Line detection X and Y", lineDetectionXYBinary );

  waitKey(0);

  return 0;
}
