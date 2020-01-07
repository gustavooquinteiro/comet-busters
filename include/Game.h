#include <SDL.h> 

class Game
{
public:
    Game();
    ~Game();
    
    bool init();
    void render();
    void update();
    void handleEvents();
    void clean();
    bool running();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    
    bool run;
}
