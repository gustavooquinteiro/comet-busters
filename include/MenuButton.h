#ifndef _MENU_BUTTON_H_
#define _MENU_BUTTON_H_

#include "GameObject.h"
#include "GameObjectFactory.h"

class MenuButton: public GameObject
{
public:
    MenuButton();
    void update() override;
    void draw() override;
    void clean() override;
    void load(const LoaderParams * params) override;
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
