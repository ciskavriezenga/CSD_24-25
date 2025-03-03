#ifndef _CAMERA_CALIBRATOR_H_
#define _CAMERA_CALIBRATOR_H_

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;

/* ChessboardAnalyser class
 * Uses a chessboard pattern to calibrate
 */
class CameraCalibrator {
public:

// ===== constructors / destructors ====
  /*
   * CameraCalibrator constructor
   * patternSize: num rows and columns of chessboard pattern
   * numOfflineFrames: extrenstic value retrieval, use this number
   *  of frames with succesful pattern detection. default = 15
   * squareSize: size of a square --> defines the the world's unit, default = 1
   */
  CameraCalibrator(cv::Size patternSize, int numOfflineFrames = 15,
    float squareSize = 1);
  ~CameraCalibrator(){};

// ===== public methods ====
  /*
   * readIntrinsics - instantiates & reads intrinsics.
   * If stored, read intrinsics from XML file:
   * - cameraMatrix
   * - distortion coefficients
   */
  void readIntrinsics();
  void writeIntrinsics();

  /*
   * calcImageCorners - instantiates & reads intrinsics.
   */
  bool calcImageCorners(Mat imgFrame, std::vector<Point2f> &imgCorners, bool displayCorners);

  /*
   * calibrateOffline - calibrate intrinsics (camera matrix and
   *    distortion coefficients) and store these to XML file.
   * Only need to do this ones.
   */
  bool calibrateOffline(Mat imgFrame, bool displayCorners);

  /*
   * calibrateOnline - calibrates the extrensics (rotation and translation
   *    matrix) only, by using the already calculated intrinsic values
   *    (camera matrix and distortion coefficients).
   * Rotation matrix --> in Rodrigues form.
   * The translation vector is the offset in camera coordinates to where
   * the chessboard origin is located.
   */
  void calibrateOnline(Mat imgFrame, bool displayCorners);

  /*
   * logIntrinsics: write cameraMatrix and distortion coefficients to the console
   */
  void logIntrinsics();
  /*
   * logExtrinsics: write rotation and translation matrix to the console
   */
  void logExtrinsics();

// ==== getter and setters ====
  /*
   * getCalibratedIntrinsics: getter method for calibratedIntrinsics.
   * - true if intrinsic parameters are available
   * - false if intrinsic parameters are not available
   */
  bool getCalibratedIntrinsics();

  /*
   * getCalibratedExtrinsics: getter method for calibratedExtrinsics.
   * - true if extrinsic parameters are available
   * - false if extrinsic parameters are not available
   */
  bool getCalibratedExtrinsics();

  /*
   * getOfflineRemainingFrames: returns the number of frames (with a
   * succesfully detected chessboard pattern) for offline calibration
   */
  int getOfflineRemainingFrames();

  /*

   * Basic getters for private Mat objects:
   * cameraMatrix, distCoeffs, rotationVector and translationVector.
   */
   Mat getCameraMatrix();
   Mat getDistCoeffs();
   Mat getRotationVector(); // in Rodrigues form
   Mat getTranslationVector();   

 private:
   // store image size
   cv::Size imgSize;
   // num rows and cols of chessboard pattern
   cv::Size patternSize;
   // size of 1 square in chessboard pattern
   float squareSize;

   // filename to store intrinsic calibration values to
   std::string iCalibrationFileName;
   // item names to reference XML out and input items
   std::string itemNameCameraMatrix;
   std::string itemNameDistCoeffs;

   // vector to store the original object corner points (3D)
   std::vector<Point3f> objectCorners;
   // Online calibration: vector to store the corner points in the image (2D)
   std::vector<Point2f> imgCorners;

   // Used in Offline calibration only:
   // vector of vectors with the object and image points.
   std::vector<std::vector<Point3f>> objectPoints;
   std::vector<std::vector<Point2f>> imgPoints;

   // Mat object to store a grayscale version of the image frame
   // used for the cv::findChessboardCorners function.
   Mat grayImgFrame;

   // Mat objects to store the intrinsic cameraMatrix and distorion coefficients
   Mat cameraMatrix;
   Mat distCoeffs;

   // Mat objects to store the rotation and translation values
   Mat rotationVector; // in Rodrigues form
   Mat translationVector;


   // calibratedIntrinsics:
   // - true if intrinsic parameters are available
   // - false if intrinsic parameters are not available
   bool calibratedIntrinsics = false;
   // calibratedExtrinsics, same as calibratedIntriscs for the extrinsic values
   bool calibratedExtrinsics = false;

   // the number of successful frames to gather for the offline calibration
   int numOfflineFrames;

   // When applying offline calibration --> keep track of the number of
   // frames on which the chessboard is detected succesfully.
   int succesfulOfflineFrames = 0;
};

#endif
