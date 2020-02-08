GAME = comet

MAIN = ./src/main.cpp
OBJ = $(subst .cpp,.o,$(subst ./src/,./build/, $(filter-out $(MAIN), $(wildcard ./src/*.cpp))))

CC = g++

CFLAGS = `sdl2-config --cflags`\
	-g 

CXXFLAGS = `sdl2-config --cflags` \
	-std=c++11 \
	-std=c++11 \
	-Wall \
	-g \
	

LDFLAGS = `sdl2-config --libs` \
           -lSDL2_mixer \
           -lSDL2_image \
           -lSDL2_ttf \
           -lSDL2_gfx \
           -lm

INCLUDE = -I"/usr/include/SDL"

MKDIR = mkdir -p
RM = rm -rf

ifeq ($(OS), Windows_NT)
	ECHO = ECHO
	MKDIR = 
	RM = 
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S), Linux)
		ECHO = echo -e -n
	endif
endif 

all: build $(GAME)

build:
	@ $(ECHO) "Creating build folder...\n"
	@ $(MKDIR) build
	
$(GAME): $(OBJ)
	@ $(ECHO) "Linking everything...\n"
	@ $(CC) $(MAIN) $^ -o $(GAME) $(LDFLAGS)
	@ $(ECHO) "Executable created: $@\n"

./build/%.o: ./src/%.cpp ./include/%.h
	@ $(ECHO) "Compiling $< in $@...\n"
	@ $(CC) $(CXXFLAGS) $(INCLUDE) $< -c -o $@ 
	@ $(ECHO) "Compiled $@\n"
	
./build/tinyxmlerror.o: ./src/tinyxmlerror.cpp ./include/tinyxml.h
	@ $(ECHO) "Compiling $< in $@...\n"
	@ $(CC) $(CXXFLAGS) $(INCLUDE) $< -c -o $@ 
	@ $(ECHO) "Compiled $@\n"

./build/tinyxmlparser.o: ./src/tinyxmlparser.cpp ./include/tinyxml.h
	@ $(ECHO) "Compiling $< in $@...\n"
	@ $(CC) $(CXXFLAGS) $(INCLUDE) $< -c -o $@ 
	@ $(ECHO) "Compiled $@\n"

clean:
	@ $(ECHO) "Cleaning workspace...\n"
	@ $(RM) build/ $(GAME)
	@ $(ECHO) "Workspace clean\n"

.PHONY: all clean
