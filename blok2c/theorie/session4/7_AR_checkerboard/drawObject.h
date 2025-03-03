#ifndef  _H_DRAW_OBJECT_
#define _H_DRAW_OBJECT_

#include "cameraCalibrator.h"

using namespace std;
using namespace cv;

/*
 * DrawEdgeObject class
 * A virtual class base class that contains the basic drawing functionality,
 * transforming its 3d world points to 2d world points
 */
class DrawEdgeObject {
public:
  // ==== constructor & destructor ====
  DrawEdgeObject(int lineWidth);
  virtual ~DrawEdgeObject();

  // ==== public method ====
  /*
   * draw: method that transforms the worldpoints into image points and
   * then calls the abstract DrawEdgeObject method, that differs per subclass
   * and draws the img points to the screen
   */
  void draw(Mat img, CameraCalibrator &calibrator);
  /*
   * DrawEdgeObject: abstract / pure virtual method
   * Needs to be implemented in the subclass
   */
  virtual void drawObject(Mat img) = 0;

protected:
  // 3D world points of the cube
  std::vector<cv::Point3f> worldPoints;
  // 2d image points
  std::vector<cv::Point2f> imagePoints;

  // lineWidth of the edges
  int lineWidth;
};

#endif
