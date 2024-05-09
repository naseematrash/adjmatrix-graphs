# Compiler and compiler flags
CXX = clang++
CXXFLAGS = -Wall -g

# Define the executable output name
TARGET = DemoApp

# Object files
OBJS = Graph.o TEST.o Algorithms.o 

# Header dependencies
DEPS = Algorithms.hpp Graph.hpp

# Default target
all: $(TARGET)

# Link the object files into a binary
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each cpp file to an object file
Graph.o: Graph.cpp Graph.hpp
	$(CXX) $(CXXFLAGS) -c $<

Demo.o: TEST.cpp Graph.hpp Algorithms.hpp
	$(CXX) $(CXXFLAGS)  -c $<

Algorithms.o: Algorithms.cpp Algorithms.hpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean the build
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets
.PHONY: all clean
