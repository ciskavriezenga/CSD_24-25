
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#define w 400
using namespace cv;



int main( void ){
  char window[] = "Drawing 2D";
  Mat img = Mat::zeros( w, w, CV_8UC3 );

  int lineType = LINE_8;
  int lineThickness = 2;

  // ==========  Draw lines ==========

  line(img,
      Point(10, 10), // start point
      Point(w - 50, 50),  // end point
      Scalar( 0, 255, 0 ), lineThickness, lineType );

  line(img, Point(w - 25, w - (w / 4)), Point(50 , 50),
    Scalar(255, 125, 0 ), lineThickness, lineType);


  // ==========  Draw simple shapes ==========
  // Rect
  rectangle( img,
         Point( w / 4, w / 4 ), // corner 1
         Point( w / 2, w/2), // opposite corner
         Scalar( 0, 255, 255 ),
         FILLED,
         LINE_8 );

  // circle
  Point centerPt = Point(w / 2, w / 2);
  circle( img,
      centerPt,
      w/10,
      Scalar( 0, 0, 255 ),
      FILLED,
      LINE_8 );

  // Ellipse
  double angle = 40;
  ellipse( img,
       Point( w/2, w/2 ),
       Size( w/4, w/16 ),
       angle,
       0,
       360,
       Scalar( 255, 0, 0 ),
       lineThickness,
       lineType );



  // ==========  polygon ==========
  int numPoints = 6;
  Point polygonPoints[1][6];
  int startX = w/4;
  int startY = 5*w/8;
  polygonPoints[0][0] = Point(startX, startY);
  polygonPoints[0][1] = Point(startX + 100, startY + 10);
  polygonPoints[0][2] = Point(startX + 150, startY + 50);
  polygonPoints[0][3] = Point(startX + 50, startY + 30);
  polygonPoints[0][4] = Point(startX + 30, startY + 70);
  polygonPoints[0][5] = Point(startX, startY);
  const Point* ppt[1] = { polygonPoints[0] };
  int npt[] = { numPoints };
  fillPoly( img,
        ppt,
        npt,
        1,
        Scalar( 255, 255, 255 ),
        lineType );

  // ==========  show result ==========
  imshow(window, img);
  waitKey( 0 );
  return 0;
}
