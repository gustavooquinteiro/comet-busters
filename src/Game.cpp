#include "../include/Game.h"
#include "../include/TextureManager.h"
#include "../include/GameObjectFactory.h"
#include "../include/InputHandler.h"
#include "../include/MenuState.h"
#include "../include/PlayState.h"
#include "../include/MenuButton.h"
#include "../include/Comet.h"
#include "../include/Player.h"
#include "../include/UFO.h"

Game* Game::instance = 0;

Game::Game(): window(0), renderer(0), gameStateMachine(0), playerLives(5), run(false){}

Game::~Game()
{
    renderer = 0;
    window = 0;
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    gameHeight = height;
    gameWidth = width;
    
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer)
            {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);                
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
    GameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
    GameObjectFactory::Instance()->registerType("Player", new PlayerCreator());
    GameObjectFactory::Instance()->registerType("Comet", new CometCreator());
    GameObjectFactory::Instance()->registerType("UFO", new UFOCreator());
    
    
    gameStateMachine = new GameStateMachine();
    gameStateMachine->changeState(new MainMenuState());
    
    run = true;
    return true;
}

void Game::render()
{
    SDL_RenderClear(renderer);
        
    gameStateMachine->render();

    SDL_RenderPresent(renderer);
}

void Game::update()
{
    gameStateMachine->update();
}
    

void Game::handleEvents()
{
     InputHandler::Instance()->update();
     if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
         quit();
     if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
         gameStateMachine->changeState(PlayState::Instance());
}

void Game::clean()
{
    gameStateMachine = 0;
    delete gameStateMachine;
    
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
