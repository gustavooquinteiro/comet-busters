#include "../include/Game.h"
const char* TITLE = "Comet Busters! 1994";

int main(int argc, char* argv[])
{
    Game* game = new Game();
    game->init(TITLE, 100, 100, 640, 480, 0);
    
    while(game->running())
    {
        game->handleEvents();
        game->update();
        game->render();
        
        SDL_Delay(10);
    }
    
    game->clean();
    
    return 0;   
}
