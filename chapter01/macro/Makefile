CXX = g++
CXXFLAGS = -Wall -O0 -g -std=c++11

EXAMPLE_SRC := $(wildcard *.cpp)
EXAMPLE_BIN := $(EXAMPLE_SRC:.cpp=.bin)

.PHONY: all

all: $(EXAMPLE_BIN)

# make example
%.bin : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<
