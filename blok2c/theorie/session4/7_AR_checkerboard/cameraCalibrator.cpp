#include "cameraCalibrator.h"
using namespace cv;
using namespace std;

// ===== constructors / destructors ====
CameraCalibrator::CameraCalibrator(Size patternSize,
  int numOfflineFrames, float squareSize):
  imgSize(Size(-1, -1)),
  patternSize(patternSize),
  numOfflineFrames(numOfflineFrames),
  squareSize(squareSize),
  iCalibrationFileName("intrinsics.XML"),
  itemNameCameraMatrix("cameraMatrix"),
  itemNameDistCoeffs("distCoeffs")
{
  // calculate the corner points for the 'world' chessboard
  for(int j = 0; j < patternSize.height; j++) {
    for(int i = 0; i < patternSize.width; i++) {
      // add corner point
      objectCorners.push_back(
        // point (X, Y, Z) --> Z can be set to 0
        Point3f(float(i * squareSize), float(j * squareSize), 0)
      );
    }
  }
  // instantiate intrinsics, if stored, read these from XML file
  readIntrinsics();
}


// ===== public methods ====
void CameraCalibrator::readIntrinsics()
{
  FileStorage fs(iCalibrationFileName, FileStorage::READ);
  if (!fs.isOpened()){
    std::cout << "\n" << iCalibrationFileName << " does not exist yet."
      << "Offline calibration is necessary.\n";
  } else {
    // read intrinsic values
    fs[itemNameCameraMatrix] >> cameraMatrix;
    fs[itemNameDistCoeffs] >> distCoeffs;

    std::cout << "\nIntrinsic values are read from the file"
      << iCalibrationFileName << ".\n";
    // log cameraMatrix and distCoeffs to console.
    logIntrinsics();

    calibratedIntrinsics = true;
  }
  // explicitly close input stream
  fs.release();
}


void CameraCalibrator::writeIntrinsics()
{
  // create file storage object to enable writing
  FileStorage fs(iCalibrationFileName, FileStorage::WRITE);
  // write intrinsic values
  fs << itemNameCameraMatrix << cameraMatrix;
  fs << itemNameDistCoeffs << distCoeffs;
  // explicitly close output stream
  fs.release();
  std::cout << "\nIntrinsic values are stored to the file"
    << iCalibrationFileName << ".\n";
}


bool CameraCalibrator::calcImageCorners(Mat imgFrame, std::vector<Point2f> &imgCorners, bool displayCorners)
{
  // check if imgSize is set, if not --> instantiate grayImgFrame
  // NOTE: assuming size of imgFrames in 1 session is constant
  if(imgSize.width == -1) {
    imgSize = imgFrame.size();
    std::cout << "imgSize: " << imgSize << "\n";
    // instantiate Mat object to store grayscale img
    grayImgFrame = Mat::zeros(imgSize.width, imgSize.height, CV_8UC1);
  }

  // transform color input image frame to grayscale for chessboard analyses
  cvtColor(imgFrame, grayImgFrame, COLOR_BGR2GRAY);
  // next, find the chessboard corners
  // using fast check flag to check if there are actually corners in the imaga

  bool cornersFound = findChessboardCorners(grayImgFrame, patternSize,
    imgCorners, CALIB_CB_FAST_CHECK);

  //NOTE: flags below could improve results, but slow flow down drastically
  //| CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_NORMALIZE_IMAGE

  /*
   * NOTE: in opencv 2 you needed to call the cv::CornerSubPix() funtion to
   * compute the exact locations of the corners. In opencv 3 this is called
   * automatically by the cv::findChessboardCorners function.
   * For higher precission we could call it again with tighter settings.
   * Current precissions is sufficient --> not calling CornerSubPix again.
   */

  // if we found corners --> calibrate!
  if(displayCorners) {
    // Draw and display the corners to the input color image
    // Red circles if corners are detected, but the pattern is not detected.
    drawChessboardCorners(imgFrame, patternSize, Mat(imgCorners), cornersFound);
  }

  return cornersFound;
}


bool CameraCalibrator::calibrateOffline(Mat imgFrame, bool displayCorners)
{
  // allocated vector to store the corner points in the image (2D)
  std::vector<Point2f> corners;
  // calculate image corners, using the cv::findChessboardCorners function
  bool foundCorners = calcImageCorners(imgFrame, corners, displayCorners);
  if(foundCorners) { // if corners found --> add results
    objectPoints.push_back(objectCorners);
    imgPoints.push_back(corners);
    succesfulOfflineFrames++;
  }

  // check if we gathered enough results to call cv::calibrateCamera
  if(succesfulOfflineFrames >= numOfflineFrames) {
    // done with offline calibration
    // create a double-precision identity Matrix as camera Matrix
    cameraMatrix = Mat::eye(3, 3, CV_64F);
    // create row matrix with 8 zeros to store the distortion coefficents
    distCoeffs = Mat::zeros(8, 1, CV_64F);
    // rotation and translation matrices
    std::vector<Mat> rvecs, tvecs;

    // calculate intrinsic and extrinsic values
    calibrateCamera(objectPoints, imgPoints, imgSize,
      cameraMatrix, distCoeffs, rvecs, tvecs);

    // log results to console
    logIntrinsics();
    // store the offline results to an XML file
    writeIntrinsics();
    // empty objectPoints and imgPoints, no need to keep these
    objectPoints.empty();
    imgPoints.empty();
    // done --> return true
    return true;
  }
  // not yet done with offline calibration
  return false;
}

void CameraCalibrator::calibrateOnline(Mat imgFrame, bool displayCorners)
{
  // calculate image corners, using the cv::findChessboardCorners function
  bool foundCorners = calcImageCorners(imgFrame, imgCorners, displayCorners);

  if(foundCorners) {
    // compute the extrinsics only (rotation and translation matrix)
    calibratedExtrinsics = solvePnP(objectCorners, imgCorners, cameraMatrix, distCoeffs,
      rotationVector, translationVector);
  } else {
    calibratedExtrinsics = false;
  }
}


void CameraCalibrator::logIntrinsics()
{
  std::cout << "\n\n________ Intrinsics ________\n"
    << "* Intrinsic camera matrix: \n" << format(cameraMatrix, Formatter::FMT_PYTHON)
    << "\n\n* Intrinsic distortion coefficients: \n"
    << format(distCoeffs, Formatter::FMT_PYTHON) << "\n"
    << "_____________________________________\n";
}


void CameraCalibrator::logExtrinsics()
{
  std::cout << "\n\n________ Extrinsics ________\n"
    << "* Extrinsic rotation matrix \n" << format(rotationVector, Formatter::FMT_PYTHON)
    << "\n\n* Extrinsic translation matrix: \n"
    << format(translationVector, Formatter::FMT_PYTHON) << "\n"
    << "_____________________________________\n";
}

// ==== getter and setters ====
bool CameraCalibrator::getCalibratedIntrinsics() {return calibratedIntrinsics;}
bool CameraCalibrator::getCalibratedExtrinsics() {return calibratedExtrinsics;}

int CameraCalibrator::getOfflineRemainingFrames()
{
  return numOfflineFrames - succesfulOfflineFrames;
}

// Getters for calibration extrinsics and intrinsics 

Mat CameraCalibrator::getCameraMatrix() {return cameraMatrix;}
Mat CameraCalibrator::getDistCoeffs() {return distCoeffs;}
Mat CameraCalibrator::getRotationVector() {return rotationVector;} // in Rodrigues form
Mat CameraCalibrator::getTranslationVector() {return translationVector;}
