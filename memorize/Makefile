CXX = g++
CXXFLAGS = -Wall -std=c++11
INCLUDES = -I.
LIBS = 
HEADERS := $(wildcard ./*.hpp)
SRCS = $(wildcard ./*.cpp)
OBJS = $(addprefix ./, $(SRCS:.cpp=.o))

EXAMPLE_DIR := example
EXAMPLE_SRC := $(wildcard $(EXAMPLE_DIR)/*.cpp)
EXAMPLE_BIN := $(addprefix $(EXAMPLE_DIR)/, $(EXAMPLE_SRC:.cpp=.bin))

.PHONY: all example

all : $(OBJS) $(EXAMPLE_BIN)

example : $(EXAMPLE_BIN)

# make example
$(EXAMPLE_DIR)/%.bin : $(EXAMPLE_DIR)/%.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $< $(LIBS)

# make src
%.o : %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) -c -o $@ $<
