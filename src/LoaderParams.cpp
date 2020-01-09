#include "../include/LoaderParams.h"

LoaderParams::LoaderParams(int x, int y, int width, int height, string textureID): position(Vector2D(x, y)), 
                                                                                    velocity(Vector2D(0, 0)),
                                                                                    acceleration(Vector2D(0,0)),
                                                                                    width(width),
                                                                                    height(height),
                                                                                    textureID(textureID){}

int LoaderParams::getX() const{ return position.getX(); }

int LoaderParams::getY() const{ return position.getY(); }

int LoaderParams::getHeight() const{ return height; }

int LoaderParams::getWidth() const{ return width; }

string LoaderParams::getTextureID() const{ return textureID; }



