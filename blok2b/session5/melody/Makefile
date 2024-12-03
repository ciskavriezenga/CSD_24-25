CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++2a
LDFLAGS= -ljack
OBJ= melody.o square.o melody_test.o
TARGET= melody_test

$(TARGET) : $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
