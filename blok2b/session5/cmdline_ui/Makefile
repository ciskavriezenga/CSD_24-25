CXX= g++
CXXFLAGS = -Wall -std=c++1z
LDFLAGS=
OBJ= ui_test.o ui.o
TARGET= ui_test

$(TARGET) : $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
