#include "drawObject.h"


// ==== constructor & destructor ====
DrawEdgeObject::DrawEdgeObject(int lineWidth) : lineWidth(lineWidth) {}
DrawEdgeObject::~DrawEdgeObject() {}

// ==== public method ====
void DrawEdgeObject::draw(Mat img, CameraCalibrator &calibrator)
{
  // be sure the calibrator actually could calculated the extrinsics
  if(calibrator.getCalibratedExtrinsics()){

    // retrieve the camera intrinsics and extrinsics

    Mat cameraMatrix = calibrator.getCameraMatrix();
    Mat distCoeffs = calibrator.getDistCoeffs();
    Mat rotVector = calibrator.getRotationVector();
    Mat transVector = calibrator.getTranslationVector();

    /*
     * Transform the current world points to image points, using the
     * cv::projectPoints function and the camera intrinsics & extrinsics.
     */
    
    projectPoints(worldPoints, rotVector, transVector, cameraMatrix, distCoeffs, imagePoints);

    // ready to draw the object using the image points
    // this method is implemented by the subclasses
    drawObject(img);
  }
}
