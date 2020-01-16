#ifndef _MENU_BUTTON_H_
#define _MENU_BUTTON_H_

#include "GameObject.h"

class MenuButton: public SDLGameObject
{
public:
    MenuButton(const LoaderParams* params);
    void update() override;
    void draw() override;
    void clean() override;
};

#endif
