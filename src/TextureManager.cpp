#include "../include/TextureManager.h"

TextureManager * TextureManager::textureManagerInstance = 0;

TextureManager::TextureManager(){}

bool TextureManager::load(string filename, string id, SDL_Renderer* renderer)
{
    SDL_Surface* temp = IMG_Load(filename.c_str());
    
    if (temp == 0)
        return false;
 
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temp);
    SDL_FreeSurface(temp);
    
    if (texture)
    {
        textureMap[id] = texture;
        return true;
    }
    return false;
}

void TextureManager::draw(string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip)
{
   SDL_Rect srcRect;
   SDL_Rect dstRect;
   
   srcRect.x = 0;
   srcRect.y = 0;
   srcRect.w = dstRect.w = width;
   srcRect.h = dstRect.h = height;
   
   dstRect.x = x;
   dstRect.y = y;
   
   SDL_RenderCopyEx(renderer, textureMap[id], &srcRect, &dstRect, 0, 0, flip);
}


TextureManager * TextureManager::Instance()
{
    if (textureManagerInstance == 0)
        textureManagerInstance = new TextureManager();
    return textureManagerInstance;

}
