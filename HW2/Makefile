# /**
# * Title: Binary Search Trees
# * Author : Ghulam Ahmed
# * ID: 22101001
# * Section : 2
# * Homework : 2
# * Description :  HW2 - Binary Search Trees
# */

# Compiler to use
CXX = g++

# Compiler flags
# CXXFLAGS = -std=c++11 -Wall

# Name of the executable file
TARGET = hw2

# Source files to compile
SRCS = main.cpp BST.cpp BSTNode.cpp analysis.cpp

# Object files to create
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)
