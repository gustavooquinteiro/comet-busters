#include "../include/Game.h"
const char* TITLE = "Comet Busters! 1994";

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{
    Uint32 frameStart, frameTime;
    
    Game::Instance()->init(TITLE, 100, 100, 640, 480, 0);
   
    while(Game::Instance()->running())
    {
        frameStart = SDL_GetTicks();
        
        Game::Instance()->handleEvents();
        Game::Instance()->update();
        Game::Instance()->render();
        
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < DELAY_TIME)
            SDL_Delay((int) (DELAY_TIME - frameTime));
    }
    
    Game::Instance()->clean();
    
    return 0;   
}
