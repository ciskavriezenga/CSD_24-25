#ifndef  _H_CUBE_
#define _H_CUBE_

#include "drawObject.h"


/*
 * A Cube object allows drawing a 3D world cube to an image
 * taking the camera intrinsics & extrinsics into account.
 */
class Cube : public DrawEdgeObject{
public:

// ==== constructor & destructor ====
  /*
   * constructor: Cube constructor.
   * size: the size of the edges of the cube.
   */
  Cube(float size, int lineWidth=2, Scalar color=Scalar(0, 255, 255));

// ==== public methods ====
  void move(Point3f direction);

protected:
  // ==== protected methods ====
  /*
   * drawObject: draws the 2d image points to the image,
   * is called by the base class DrawEdgeObject draw method, after transforming
   * the 3d world points into 2d world points.
   */
  void drawObject(Mat img);

  /*
   * calcWorldPoints: calculates the worldPoints according to the cubePoints
   * (default corners from origin) and the current position.
   */
  void calcWorldPoints();

  // size of the edges of the cube
  float size;
  // color of the cube edges when drawing it
  Scalar edgeColor;

  std::vector<cv::Point3f> cubePoints;
  // current position of the cube on the chessboard (x, y, 0)
  Point3f position;
  Point3f speed;  
};

#endif
