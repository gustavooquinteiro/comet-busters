#include "../include/Game.h"
#include "../include/InputHandler.h"
#include "../include/MenuState.h"
#include "../include/PlayState.h"

Game* Game::instance = 0;

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
    
    //gameObject = new GameObject(new LoaderParams(0, 0, 268, 268, "player1"));
    player = new Player();
    gameObjects.push_back(player);
    gameStateMachine = new GameStateMachine();
    gameStateMachine->changeState(new MenuState());
    
    run = true;
    return true;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    
    textureManager->Instance()->draw("space", 0, 0, 640, 480, renderer);
    textureManager->Instance()->draw("player1", 0, 0, 268, 268, renderer);
    
    for(auto gameObject: gameObjects)
        gameObject->draw();
    
    gameStateMachine->render();

    SDL_RenderPresent(renderer);
}

void Game::update()
{
    for(auto gameObject: gameObjects)
        gameObject->update();
    
    gameStateMachine->update();
}
    

void Game::handleEvents()
{
     InputHandler::Instance()->update();
     if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
         quit();
     if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
         gameStateMachine->changeState(new PlayState());
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Game::running(){ return this->run; }

Game * Game::Instance()
{
    if (instance == 0)
        instance = new Game();
    return instance;
}

void Game::quit()
{
    this->run = false;
}

SDL_Renderer* Game::getRenderer(){ return this->renderer; }

GameStateMachine * Game::getStateMachine(){ return this->gameStateMachine; }
