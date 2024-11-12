#! /bin/bash

g++ -c speaker.cpp
g++ -c woofer.cpp
g++ -c tweeter.cpp
g++ -o speaker speaker.o woofer.o tweeter.o

