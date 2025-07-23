# Compiler and flags
CXX := nvcc
CXXFLAGS := -std=c++17

# Output binary name
TARGET := main

# Sources
SRCS := main.cpp

# Build rule
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS)

# Clean rule
clean:
	rm -f $(TARGET)
