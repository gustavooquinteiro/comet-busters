#include "../include/Game.h"
#include "../include/InputHandler.h"

Game::Game(){}

Game::~Game(){}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer)
            {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                if (!textureManager->Instance()->load("assets/player1.jpeg", "player1", renderer) || 
                    !textureManager->Instance()->load("assets/space.jpeg", "space", renderer))
                    return false;
            } else
            {
                return false;
            }
        } else
        {
            return false;
        }
    } else
    {
        return false;
    }
    
    gameObject = new GameObject(0, 0, 268, 268, "player1");
    player = new Player(0, 0, 268, 268, "player1");
    gameObjects.push_back(player);
    
    run = true;
    return true;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    textureManager->Instance()->draw("space", 0, 0, 640, 480, renderer);
    textureManager->Instance()->draw("player1", 0, 0, 268, 268, renderer);
    for(auto gameObject: gameObjects)
        gameObject->draw(renderer);

    SDL_RenderPresent(renderer);
}

void Game::update()
{
    InputHandler::Instance()->update();
    for(auto gameObject: gameObjects)
        gameObject->update();
}
    

void Game::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                run = false;
                break;
            default:
                break;
        }
    }
    
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}


bool Game::running(){ return this->run; }
