#ifndef _MENU_BUTTON_H_
#define _MENU_BUTTON_H_

#include "GameObject.h"
#include "GameObjectFactory.h"

class MenuButton: public ShooterObject
{
public:
    MenuButton();
    void update() override;
    void draw() override;
    void clean() override;
    void load(const unique_ptr<LoaderParams> &params) override;
    void collision() override;
    string type(){ return "MenuButton"; }
    void setCallback(void (*callback)());
    int getCallbackID();
private:
    enum button_state
    {
        MOUSE_OUT = 0,
        MOUSE_OVER = 1,
        CLICKED = 2
    };
    
    void (*callback)();
    bool buttonReleased;
    int callbackID;
};

class MenuButtonCreator: public BaseCreator
{
public:
    GameObject * createGameObject() const
    {
        return new MenuButton();
    }
};

#endif
