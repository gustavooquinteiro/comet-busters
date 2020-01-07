#ifndef _GAME_H_
#define _GAME_H_
#include <SDL2/SDL.h> 

class Game
{
public:
    Game();
    ~Game();
    
    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
    void render();
    void update();
    void handleEvents();
    void clean();
    bool running();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    
    bool run;
};
#endif
