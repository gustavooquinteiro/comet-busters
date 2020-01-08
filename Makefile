GAME = comet

MAIN = ./src/main.cpp
SRC = $(filter-out $(MAIN), $(wildcard ./src/*.cpp))
LIB = $(subst .cpp,.h,$(subst ./src/,./include/, $(SRC)))
OBJ = $(subst .cpp,.o,$(subst ./src/,./build/, $(SRC)))

CFLAGS = -g `sdl2-config --cflags`
CXXFLAGS = -Wall -Wextra -g `sdl2-config --cflags` -std=c++11
LDFLAGS  = `sdl2-config --libs` \
           -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_gfx -lm

INCLUDE = -I"/usr/include/SDL"

ifeq ($(OS), Windows_NT)
	ECHO = ECHO
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S), Linux)
		ECHO = echo -e -n
	endif
endif 

all: build comet

build:
	@ $(ECHO) "Creating build folder...\n"
	@ mkdir -p build
	
comet: $(OBJ)
	@ $(ECHO) "Compiling $< in $@...\n"
	@ g++ $(MAIN) $^ -o $(GAME) $(LDFLAGS)
	@ $(ECHO) "Executable created: $@\n"

./build/%.o: ./src/%.cpp ./include/%.h
	@ $(ECHO) "Compiling $< in $@...\n"
	@ g++ $(CXXFLAGS) $(INCLUDE) $< -c -o $@ 
	@ $(ECHO) "Compiled $@\n"
clean:
	@ $(ECHO) "Cleaning workspace...\n"
	@ rm -rf build/ $(GAME)
	@ $(ECHO) "Workspace clean\n"

.PHONY: all clean
