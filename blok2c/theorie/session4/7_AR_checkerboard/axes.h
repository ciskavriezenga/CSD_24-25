#ifndef  _H_AXES_
#define _H_AXES_

#include "drawObject.h"

using namespace std;
using namespace cv;

/*
 * A Axes object allows drawing a 3D world axes to an image
 * taking the camera intrinsics & extrinsics into account.
 */
class Axes : public DrawEdgeObject{
public:

// ==== constructor & destructor ====
  /*
   * constructor: Axes constructor.
   * size: the length of the edges of the axes.
   */
  Axes(float length, int lineWidth=4);

// ==== public method ====
  /*
   * drawObject: draws the 2d image points to the image,
   * is called by the base class DrawEdgeObject draw method, after transforming
   * the 3d world points into 2d world points.
   */
  void drawObject(Mat img);

private:
  // array holding the colors for each axis
  Scalar edgeColors[3];
  // length of the edges of the axes
  float length;
};

#endif
