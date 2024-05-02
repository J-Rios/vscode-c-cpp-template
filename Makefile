
# Set Shell to use by Make
SHELL := /bin/bash

# Specify project name and default compilers
OUT = cases
CC = gcc
CXX = g++

# Project Version
VERSION_X = 1
VERSION_Y = 0
VERSION_Z = 0
VERSION_DEV = true

####################################################################################################

# Get actual date and setup output binary directory name
_BINDIR = ./bin
BINDIR = bin/$(shell date '+%Y_%m_%d_%H_%M_%S')

# Specify Headers files
HEADS  = $(shell find ./include -type f -name *.h)
HEADS += $(shell find ./include -type f -name *.hpp)
HEADS += $(shell find ./src -type f -name *.h)
HEADS += $(shell find ./src -type f -name *.hpp)
HEADS += $(shell find ./lib -type f -name *.h)
HEADS += $(shell find ./lib -type f -name *.hpp)

# Specify Sources files
SRCS   = $(shell find ./src -type f -name *.c)
SRCS  += $(shell find ./src -type f -name *.cpp)
SRCS  += $(shell find ./lib -type f -name *.c)
SRCS  += $(shell find ./lib -type f -name *.cpp)

# Specify directory where store compile objects files
OBJDIR = ./build

# Get objects files from sources and output object
_OBJS = $(SRCS:.cpp=.o)
OBJS = $(_OBJS:.c=.o)

# Setup libs directories to be included
LIBS  = -I./include
LIBS += -I./src/version/src

# Setup compilation flags
CXXFLAGS = -Og -Wall -g $(LIBS)
# Note: Optimization set to '-Og' for debug in code order

####################################################################################################

### Use Targets ###

# Target: make all (build project generating output directory)
all: $(OUT)
	mkdir -p ${BINDIR}
	cp -a $(OUT) $(BINDIR)
	mv $(OUT) run
	mv *.o $(OBJDIR)/

# Target: make clean (remove all previously builds)
clean:
	rm -f $(OBJDIR)/*.o
	rm -f run

# Target: make cleanall clean previously builds including output bins)
cleanall: clean
	rm -rf $(_BINDIR)/*

# Target: make rebuild (clean previously builds and build again)
rebuild: clean all

# Target: check (custom target to check build variables)
check:
	@echo ""
	@echo "HEADS:"
	@echo "$(HEADS)"
	@echo ""
	@echo "SRCS:"
	@echo "$(SRCS)"
	@echo ""
	@echo "OBJS:"
	@echo "$(OBJS)"
	@echo ""
	@echo "BINDIR:"
	@echo "  $(BINDIR)"
	@echo ""

####################################################################################################

### Pre-Build Targets ###

# Target to write version variables into C/C++ code version file
update_version:
	@cp -a src/version/src/version.cpp.in src/version/src/version.cpp
	@sed -i "s/@VERSION_X@/${VERSION_X}/g" src/version/src/version.cpp
	@sed -i "s/@VERSION_Y@/${VERSION_Y}/g" src/version/src/version.cpp
	@sed -i "s/@VERSION_Z@/${VERSION_Z}/g" src/version/src/version.cpp
	@sed -i "s/@VERSION_DEV@/${VERSION_DEV}/g" src/version/src/version.cpp

####################################################################################################

# Build Targets

# Target: make <OUT> (build project)
$(OUT): update_version $(OBJS) $(HEADS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS)

# Target for generate object file of each .c file
%.o: %.c
	$(CC) $(CXXFLAGS) -c $<

# Target for generate object file of each .cpp file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

####################################################################################################
