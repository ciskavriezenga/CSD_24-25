#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#define REDMASK	(0xff0000)
#define GREENMASK (0x00ff00)
#define BLUEMASK (0x0000ff)



using namespace cv;

typedef unsigned int uint;


int main( int argc, char **argv ){

  if(argc != 2) {
    std::cout << "\nPlease add one path to an image when running this program!\n\n";
    return 0;
  }
  char* imageName = argv[1];

  Mat image;
  // read image
  image = imread( imageName, IMREAD_COLOR );
  if(!image.data )
  {
   printf( " No image data \n " );
   return -1;
  }

  Mat grayImage;
  cvtColor(image, grayImage, COLOR_BGR2GRAY);
  imwrite( "../../assets/images/Gray_Image.jpg", grayImage );

  // ==========  show result ==========
  // namedWindow - usually used when creating a window with options
  // imshow is sufficient to just show an image
  namedWindow( "image", WINDOW_AUTOSIZE );
  namedWindow( "Gray image", WINDOW_AUTOSIZE );
  imshow( "image", image );
  imshow( "Gray image", grayImage );
  waitKey(0);

  return 0;
}
