CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++20
LDFLAGS= -ljack
SOURCE=main.o
TARGET=example

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
