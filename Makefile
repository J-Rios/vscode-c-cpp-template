
# Specify project name and compilers
PROJECT = cases
CC = gcc
CXX = g++

######################################################################

# Get actual date and setup output binary directory name
BINDIR = bin/$(shell date '+%Y_%m_%d_%H_%M_%S')

# Specify sources and headers files
SRCS  = $(shell find ./src -type f -name *.c)
SRCS  += $(shell find ./src -type f -name *.cpp)
HEADS = $(shell find ./include -type f -name *.h)
HEADS += $(shell find ./include -type f -name *.hpp)

# Specify directory where store compile objects files
OBJDIR = ./obj

# Get objects files from sources and output object
_OBJS = $(SRCS:.cpp=.o)
OBJS = $(_OBJS:.c=.o)

#Setup libs directories to be included
LIBS = -I./include

# Setup compilation flags
CXXFLAGS = -O0 -Wall -g $(LIBS)
# Note: Optimization set to 0 for debug in code order

######################################################################

# Target: make all (build project generating output directory)
all: $(PROJECT)
	mkdir -p ${BINDIR}
	cp -a $(PROJECT) $(BINDIR)
	mv *.o $(OBJDIR)/

# Target: make rebuild (clean previously builds and build again)
rebuild: clean all

# Target: make clean (remove all previously builds)
clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(PROJECT)

# Target: check (custom target to check build variables)
check:
	@echo "SRCS:"
	@echo "  $(SRCS)"
	@echo "OBJS:"
	@echo "  $(OBJS)"
	@echo "BINDIR:"
	@echo "  $(BINDIR)"

######################################################################

# Target: make <PROJECT> (build project)
$(PROJECT): $(OBJS) $(HEADS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS)

# Target for generate object file of each .c file
%.o: %.c
	$(CC) $(CXXFLAGS) -c $<

# Target for generate object file of each .cpp file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<
