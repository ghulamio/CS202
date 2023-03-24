# Compiler to use
CXX = g++

# Compiler flags
# CXXFLAGS = -std=c++11 -Wall

# Name of the executable file
TARGET = hw2

# Source files to compile
SRCS = main.cpp BST.cpp BSTNode.cpp

# Object files to create
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)
