#! /bin/bash

g++ -c pet.cpp
g++ -c cat.cpp
g++ -c dog.cpp
g++ -c main.cpp
g++ -o pet pet.o dog.o cat.o main.o
