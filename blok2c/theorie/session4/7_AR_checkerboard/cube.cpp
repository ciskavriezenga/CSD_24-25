#include "cube.h"

// ==== constructor ====
Cube::Cube(float size, int lineWidth, Scalar color) : DrawEdgeObject(lineWidth),
  size(size), edgeColor(color)
{
  // set initial position on chessboard
  position = Point3f(0, 0, 0);
  speed = Point3f(0.1, 0.1, 0.1);

  // cache minus size
  float minusSize = size * -1;

  // add the content of the array tempPoints to the vector all at once
  cubePoints.insert(cubePoints.end(), {
    Point3f(0, 0, 0),             // lower left front   (0, 0, 0)
    Point3f(size, 0, 0),          // lower right front  (1, 0, 0)
    Point3f(size, 0, minusSize),  // upper right front  (1, 1, 0)
    Point3f(0, 0, minusSize),     // upper left front
    Point3f(0, size, 0),             // lower left back
    Point3f(size, size, 0),          // lower right back
    Point3f(size, size, minusSize),  // upper right back
    Point3f(0, size, minusSize)     // upper left back
  });
  // push points to worldPoints vector
  for(int i = 0; i < 8; i++) {
    worldPoints.push_back(Point3f(0,0,0));
  }

  // update the worldPoints according to the current position
  calcWorldPoints();
}

// ==== public methods ====
void Cube::move(Point3f direction)
{
  // set new position
  position.x += direction.x * speed.x;
  position.y += direction.y * speed.y;

  // update the worldPoints
  calcWorldPoints();
}

// ==== protected methods ====
void Cube::calcWorldPoints()
{
  // retrieve the worldpoints by adding the current position to the cubePoints
  for(int i = 0; i < 8; i++)
  {
    worldPoints[i] = cubePoints[i] + position;
  }
}

// ==== public method ====
void Cube::drawObject(Mat img)
{
  // draw the lines of the cube, iterate through the corner points
  int numPoints = 4;
  for(int i = 0; i < numPoints; i++) {
    // draw front edges
    line(img, imagePoints[i], imagePoints[(i + 1) % 4], edgeColor, lineWidth);
    // draw back edges
    int iBack = i + 4;
    line(img, imagePoints[iBack], imagePoints[((i + 1) % 4) + 4], edgeColor, lineWidth);
    // draw side edges
    line(img, imagePoints[i], imagePoints[iBack], edgeColor, lineWidth);
  }
};
