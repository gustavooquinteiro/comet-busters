#ifndef _GAME_H_
#define _GAME_H_

#include <SDL2/SDL.h> 
#include <vector>
#include "GameObject.h"
#include "GameStateMachine.h"

using namespace std;

class Game
{
public:
    
    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
    void render();
    void update();
    void handleEvents();
    void clean();
    bool running();
    void quit();
    SDL_Renderer* getRenderer();
    static Game* Instance();
    GameStateMachine* getStateMachine();
    int getPlayerLives() { return playerLives; }
    void setPlayerLives(int lives){ playerLives = lives; }
    int getGameHeight() { return gameHeight; }
    int getGameWidth() { return gameWidth; }
private:
    Game();
    ~Game();
    
    Game(const Game&);
    Game& operator= (const Game&);
    
    static Game * instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
        
    GameStateMachine* gameStateMachine;
    
    int playerLives;
    int gameWidth;
    int gameHeight;
    
    bool run;
};
#endif
