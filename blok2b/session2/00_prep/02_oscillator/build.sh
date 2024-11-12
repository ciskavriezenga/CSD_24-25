#! /bin/bash

g++ -c oscillator.cpp
g++ -c main.cpp
g++ -o oscillator oscillator.o main.o
