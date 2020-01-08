#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <SDL2/SDL.h>
#include "GameObject.h"

class Player: public GameObject
{
public:
    Player(int x, int y, int width, int height, std::string textureId);
    void load();
    void draw(SDL_Renderer* renderer);
    void update();
    void clean();
    long int getScore();
private:
    long int score;
};

#endif
