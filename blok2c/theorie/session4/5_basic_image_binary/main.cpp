#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>



using namespace cv;

typedef unsigned int uint;


int main( int argc, char **argv ){
  // ==========  read image ==========
  if(argv[1] == NULL) {
    std::cout << "\nPlease add a path to an image when running this program!\n\n";
    return -1;
  }
  char* imageName = argv[1];

  Mat image;
  // read image
  image = imread( imageName, IMREAD_COLOR );
  if( argc < 2 || !image.data )
  {
   printf( " No image data \n " );
   return -1;
  }

  // ==========  transform to binary image ==========
  Mat grayImg;
  cvtColor( image, grayImg, COLOR_BGR2GRAY );
  // get height and width matrix
  int h = grayImg.rows;
  int w = grayImg.cols;

  for(int i = 0; i < h; i++) {
    uchar* row = grayImg.ptr<uchar>(i);
    for(int j = 0; j < w; j++) {
      row[j] = row[j] > 80 ? 0 : 255;
    }
  }


  // ==========  apply morphology filters ==========
  Point anchorPoint = Point(-1, -1);
  Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3), anchorPoint);
  Mat eroded, dilated, opened, closed;
  dilate(grayImg, dilated, kernel, anchorPoint, 3);
  erode(grayImg, eroded, kernel, anchorPoint, 3);

  morphologyEx(grayImg, closed, MORPH_CLOSE, kernel, anchorPoint, 3);
  morphologyEx(grayImg, opened, MORPH_OPEN, kernel, anchorPoint, 3);
  /*
   * Apply opening by reconstruction of erosion
   * first apply erode to original src, to remove small structures
   * then reconstruct by applying dilation with a control image
   * as control image we use the results of the closing step above
   *
  */
  Mat eroded2, dilated2, openingReconstruct;
  cv::erode(grayImg, eroded2, kernel, anchorPoint, 6);
  cv::dilate(eroded2, dilated2, kernel, anchorPoint, 10);
  cv::bitwise_and(dilated2, closed, openingReconstruct);
  // ==========  show result ==========
  // namedWindow - usually used when creating a window with options
  // imshow is sufficient to just show an image
  namedWindow( "Binary image", WINDOW_AUTOSIZE );
  imshow( "Binary image", grayImg );

  namedWindow( "Eroded image", WINDOW_AUTOSIZE );
  imshow( "Eroded image", eroded );

  namedWindow( "Dilated image", WINDOW_AUTOSIZE );
  imshow( "Dilated image", dilated );


  namedWindow( "Closed image", WINDOW_AUTOSIZE );
  imshow( "Closed image", closed );

  namedWindow( "Opened image", WINDOW_AUTOSIZE );
  imshow( "Opened image", opened );


  namedWindow( "Opening by reconstruction", WINDOW_AUTOSIZE );
  imshow( "Opening by reconstruction", openingReconstruct );

  waitKey(0);
  return 0;
}
