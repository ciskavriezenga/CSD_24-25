CC = g++
CFLAGS = -I/usr/local/include/opencv4/ -Wall -std=c++1z
LDFLAGS= -L/usr/local/lib/ -lopencv_calib3d -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc -lopencv_ml -lopencv_objdetect -lopencv_photo -lopencv_shape -lopencv_stitching -lopencv_superres -lopencv_video -lopencv_videoio -lopencv_videostab

LIBS = $(OPENCV)
all: example

example : bgSubtractorAverage.o bgSubtractorSD.o bgSubtractor.o BGModelCreator.o main.o
	$(CC) -o $@ $(CFLAGS) bgSubtractorAverage.o bgSubtractorSD.o bgSubtractor.o BGModelCreator.o main.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS) $(LIBS)

clean:
	rm -f *.o
	rm -f example
