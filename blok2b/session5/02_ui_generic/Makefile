CXX= g++
CXXFLAGS = -Wall -std=c++1z
LDFLAGS=
SOURCE= main.o
TARGET=example

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:a
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o