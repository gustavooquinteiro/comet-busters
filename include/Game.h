#ifndef _GAME_H_
#define _GAME_H_

#include <SDL2/SDL.h> 
#include <vector>
#include "Player.h"
#include "GameObject.h"
#include "TextureManager.h"
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
private:
    Game();
    ~Game();
    
    static Game * instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
    
    vector<GameObject*> gameObjects;
    GameObject* player;
    GameObject* gameObject;
    
    GameStateMachine* gameStateMachine;
    
    TextureManager* textureManager;
    bool run;
};
#endif
