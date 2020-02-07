#ifndef _TEXTURE_MANAGER_H_
#define _TEXTURE_MANAGER_H_
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <map>


using namespace std;

class TextureManager
{
public:
    void draw(string id, int x, int y, int width, int height, 
              SDL_Renderer* renderer, double angle = 0,
              SDL_RendererFlip flip = SDL_FLIP_NONE);
    bool load(string filename, string id, SDL_Renderer* renderer); 
    static TextureManager* Instance();
    void clearFromTextureMap(string id);
    void clearTextureMap();
private:
    TextureManager();
    map<string, SDL_Texture*> textureMap;
    static TextureManager* textureManagerInstance;
};

#endif
