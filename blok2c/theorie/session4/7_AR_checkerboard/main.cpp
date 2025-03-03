
#include <stdlib.h> /* strtol */
#include "cameraCalibrator.h"
#include "cube.h"
#include "axes.h"
using namespace cv;


//implement help information for console usage
static void help(char **av)
{
  cout << endl
       << "insufficient arguments or too many arguments" << endl
       << "please refer to 'Usage:' section" << endl
       << " " << endl
       << " " << endl
       << "This application is used to create the extrensics and intrinsics" << endl
       << "of a chessboard provided by the OpenCV repository. If there is" << endl
       << "no xml file for the extrensisc and intrisics, the program will" << endl
       << "notify the user to calculate it. It retrieves 15 snapshots from" << endl
       << "your camera, in order to calibrate" << endl
       << "When this application has the correct information it also draws" << endl
       << "the Axes of the origin of the intrinsics" << endl
       << "and a custom made movable cube." << endl
       << " " << endl
       << "Usage: " << endl
       << av[0] << " -- Shows this help file " << endl
       << av[0] << " w h -- Runs the application with input chessboard size (w,h)" << endl
       << "Example: " << av[0] << " 9 6"
       << " " << endl
       << "Cube movement" << endl
       << "The cube is movable with the w a s d keys." << endl
       << "w: up - s: down - a: left - d: right" << endl
       << " " << endl
       << "Press 'q' to quit" << endl;
}
void draw_box( cv::Mat& img, cv::Rect box )
{
  rectangle( img, box.tl(), box.br(), Scalar(0x00,0x00,0xff) /* red */ );
}
// helper function to add text on camera for camera calibration
void addText(Mat img, std::string text, Point position, double fontScale = 1) {
  putText(img, text, position, FONT_HERSHEY_COMPLEX, fontScale,
     Scalar(255, 255, 255), 2, LINE_AA);
}

//TODO - add comments.
int main(int argc, char* argv[])
{
  int w;
  int h;
  float squareSize = 1;
  // Basic checker for the console arguments
  if (argc <= 2)
  {
  // Prints out the text if arguments are not given correctly
    help(argv);
    return 1;
  }
  else {

  //create our chessboard size. This is for external usage apart from the standard 9x6 chessboard
    w = atoi(argv[1]);
    h = atoi(argv[2]);
  }
  // Create the calibrator for the camera with the values fetched from the console.

  CameraCalibrator calibrator(Size(w,h), 15, squareSize);

  // Cube and Axis drawing
  /*
   * Creates the cube and axes for the chessboard based on the origin of the chessboard coordinates. Since the chessboard
   * Edge length is given initially in the begining, the cube size and the axis size is calculated here to give us a bigger
   * picture
   */
  Cube cube(squareSize * 2); // use default lineWidth and color
  Axes axes(squareSize * 3); // use default lineWidth

  // Open a camera for video capturing (webcam at index 0, which is the internal camera or the only camera in the computer.)

  VideoCapture captRefrnc(0);

  //frames per second - limit
  const int fps = 30;
  char prevKeyPress = ' ';

  // check if the binding was successful
  if ( !captRefrnc.isOpened())
  {
    std::cout << "Could not retrieve a video capture reference\n";
    return -1;
  }


  // allocate frame to store the video frame
  Mat frame;

  // create window

  namedWindow("Live video", WINDOW_AUTOSIZE);

  //displayCorners: do or don't display the detected corners of the chessboard
  bool displayCorners = true;

  if(!calibrator.getCalibratedIntrinsics()) {

    /*
     * Apply OFFLINE calibration first. Calculate the intrinsics.
     * (camera matrix and distortion coefficients)
     */
     /*
      * NOTE: book "Learning OpenCV 3 - Adrian Kaehler & Gary Bradski"
      * Quote:  "In practice, for high-quality results, you’ll need at least
                 10 images of a 7 × 8 or larger chessboard (and that’s only
                if you move the chessboard enough between images to obtain a
                “rich” set of views).
      * Therefor, taking images every second to allow enough change and
      * taking 15 frames (a bit above the advised number).
      */
     int numCalibrationFrames = 15;
     bool done = false;

     while(!done) {
       // retrieve input frame
       captRefrnc >> frame;

       // call calibrateOffline to calibrate the intrinsic values
       // (cameraMatrix, distortion coefficients)
       // If done is true --> we are done calibrating the intrinsics
       // (which are then also stored to a XML file)
       done = calibrator.calibrateOffline(frame, displayCorners);

       // add text to image, to tell user to press a key to take new img
      addText(frame, "OFFLINE CALIBRATION", Point(100,100));
      addText(frame, "Press a key to take a new picture", Point(100,175));
      addText(frame, "and hold chessboard at different angle.", Point(100,250));
      addText(frame, std::to_string(calibrator.getOfflineRemainingFrames()) + " number of frames to go", Point(100,325));

      // display the image
      imshow("frame", frame);
      // freeze. wait for user to press a key
      waitKey(0);
     }
  }

  /*
   * Apply ONLINE calibration.
   */
  for(;;) // infinite loop
  {
    // retrieve input frame
    captRefrnc >> frame;

    /*
    * Calculate the extrinsics only (rotation and translation matrices),
    * using the already calculated camera intrinsics.
    */
    calibrator.calibrateOnline(frame, displayCorners);

    // quit if q key is pressed
    if((int)prevKeyPress == 113) return 0;

    // be sure the calibrator actually could calculated the extrinsics
    if(calibrator.getCalibratedExtrinsics()) {
    // call the draw method, pass the calibrator by reference
      axes.draw(frame, calibrator);

      // Move the cube with the w, a, s, d keys, or quit with q
      if(prevKeyPress != -1) {
        Point3d moveVector = { 0, 0, 0};
        switch(prevKeyPress) {
          // w - up
          case 115: moveVector = { 0, 1, 0 }; break;
          // s - down
          case 119: moveVector = { 0, -1, 0 }; break;
          // a - left
          case 97: moveVector = { -1, 0, 0 }; break;
          // d - right
          case 100: moveVector = { 1, 0, 0 }; break;
        }
        cube.move(moveVector); // speed is set inside the cube object
      }
      cube.draw(frame, calibrator);
    }
    addText(frame, "Press q to quit. Press wasd keys to move the cube.", Point(100,100));
    // display the image
    imshow("frame", frame);

    //get keyboard input
    prevKeyPress = waitKey(1000 / fps);
  }

  // end of program
  return 0;
}
