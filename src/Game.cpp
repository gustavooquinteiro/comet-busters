#include "../include/Game.h"

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
                if (!textureManager->Instance()->load("assets/player1.jpeg", "player1", renderer))
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
    
    gameObject = GameObject(100, 100, 128, 82, "player1");
    player.load(300, 300, 128, 82, "player1");
    
    run = true;
    return true;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    
    textureManager->Instance()->draw("player1", 0, 0, 268, 268, renderer);
    gameObject.draw(renderer);
    player.draw(renderer);
    
    SDL_RenderPresent(renderer);
}

void Game::update()
{
    gameObject.update();
    player.update();
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
