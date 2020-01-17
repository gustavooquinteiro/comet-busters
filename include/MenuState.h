#ifndef _MENU_STATE_H_
#define _MENU_STATE_H_

#include "GameObject.h"
#include "GameState.h"
#include <SDL2/SDL.h>
#include <vector>

using namespace std;

class MenuState: public GameState
{
public:
    void update() override;
    void render() override;
    
    bool onEnter() override;
    bool onExit() override;
    
    string getStateID() const override;
    
protected:
    typedef void(*Callback)();
    virtual void setCallbacks(const vector<Callback>& callbacks) = 0;
    
    vector<Callback> callbacks;
private:
        
    static const string menuID;
};

class MainMenuState: public MenuState
{
public:
    MainMenuState();
    void update() override;
    void render() override;
    
    bool onEnter() override;
    bool onExit() override;
    
    string getStateID() const override;
private:
    void setCallbacks(const vector<Callback>& callbacks) override;
    
    static void menuToPlay();
    static void exitFromMenu();
    
    static const string menuID;
    vector<GameObject*> gameObjects;
};

#endif
