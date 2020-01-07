#include "../include/Game.h"

Game::Game(){}

Game::~Game(){}

bool Game::init(){ return true; }
void Game::render(){}
void Game::update(){}
void Game::handleEvents(){}
void Game::clean(){}

bool Game::running(){ return this->run; };
