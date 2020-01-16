#ifndef _LOADER_PARAMS_H_
#define _LOADER_PARAMS_H_

#include "Vector2D.h"
#include <iostream>
using namespace std;

class LoaderParams
{
public:
    LoaderParams(int x, int y, int width, int height, string textureID);
    int getWidth() const;
    int getHeight() const;
    string getTextureID() const;
    int getX() const;
    int getY() const;
private:
    int x;
    int y;
    int width;
    int height;
    
    string textureID;
    
    int numFrames;
    int callbackID;
    int animationSpeed;
};

#endif
