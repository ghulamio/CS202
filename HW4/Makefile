# Compiler to use
CXX = g++

# Compiler flags
# CXXFLAGS = -std=c++11 -Wall

# Name of the executable file
TARGET = hw4

# Source files to compile
SRCS = main.cpp Accompaniment.cpp AccompanimentHashing.cpp linked_list.cpp Snack.cpp SnackHashing.cpp

# Object files to create
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)
