CXX=g++
CXXFLAGS=-Wall -std=c++14
LDFLAGS=
SOURCE= oscillator.o sine.o main.o
TARGET=example

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
