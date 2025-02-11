#include "axes.h"

// ==== constructor ====
Axes::Axes(float length, int lineWidth) : DrawEdgeObject(lineWidth),
  length(length)
{
  edgeColors[0] = Scalar(255, 0, 0);
  edgeColors[1] = Scalar(0, 255, 0);
  edgeColors[2] = Scalar(0, 0, 255);
  // add the content of the array tempPoints to the vector all at once
  worldPoints.insert(worldPoints.end(), {
    Point3f(0, 0, 0),             // origin
    Point3f(length, 0, 0),          // x-axis
    Point3f(0, length, 0),  // y-axis
    Point3f(0, 0, -1 * length),     // z-axis
  });
}

// ==== public method ====
void Axes::drawObject(Mat img)
{
  // draw each axis
  for(int i = 1; i <= 3; i++) {
    arrowedLine(img, imagePoints[0], imagePoints[i], edgeColors[i - 1], lineWidth);
  }
};
