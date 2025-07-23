# Compiler and flags
CXX := nvcc
CXXFLAGS := -std=c++17
BINDIR = bin

# Output binary name
TARGET := main

# Sources
SRCS := main.cpp

BINARIES := $(addprefix $(BINDIR)/, $(TARGET))

all: $(BINARIES)

# Build rule
$(BINDIR)/%:  $(SRCS)| $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS)

# Create bin/ directory if it doesn't exist
$(BINDIR):
	mkdir -p $(BINDIR)

# Clean rule
clean:
	rm -fr $(BINDIR)
