SRC_MODULES += $(patsubst %,audio/%, audioToFile.cpp bufferDebugger.cpp)
SRC += audio/jack_module.cpp
