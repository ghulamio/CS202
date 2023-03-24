# Title: Algorithm analysis & Sorting 
# Author : GHULAM AHMED
# ID: 22101001
# Section : 2
# Homework : 1 
# Description : description of your code 


# Compiler to use
CXX = g++

# Compiler flags
# CXXFLAGS = -std=c++11 -Wall

# Name of the executable file
TARGET = main

# Source files to compile
SRCS = 22101001_GHULAM_AHMED_hw1.cpp

# Object files to create
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)
