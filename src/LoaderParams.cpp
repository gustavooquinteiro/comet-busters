#include "../include/LoaderParams.h"

LoaderParams::LoaderParams(int x, int y, int width, int height, string textureID, int numFrames,
                           int callbackID = 0, int animationSpeed = 0): x(x), y(y),
                                                                        width(width),
                                                                        height(height),
                                                                        textureID(textureID),
                                                                        numFrames(numFrames),
                                                                        callbackID(callbackID),
                                                                        animationSpeed(animationSpeed){}

int LoaderParams::getX() const{ return x; }

int LoaderParams::getY() const{ return y; }

int LoaderParams::getHeight() const{ return height; }

int LoaderParams::getWidth() const{ return width; }

string LoaderParams::getTextureID() const{ return textureID; }



