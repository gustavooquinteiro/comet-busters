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

all: build comet

build:
	@ mkdir build
	
comet: $(OBJ)
	@ g++ $(MAIN) $^ -o $(GAME) $(LDFLAGS)
	
./build/%.o: ./src/%.cpp ./include/%.h
	@ g++ $(CXXFLAGS) $(INCLUDE) $< -c -o $@ 
