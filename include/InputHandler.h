#ifndef _INPUT_HANDLER_H_
#define _INPUT_HANDLER_H_

#include <SDL2/SDL.h>
#include "Vector2D.h"
#include <vector>

using namespace std;

class InputHandler
{
public:
    bool isKeyDown(SDL_Scancode key);
    void onKeyDown();
    void onKeyUp();
    
    static InputHandler* Instance();
    void update();
    
    bool getMouseButtonState(int buttonNumber);
    Vector2D* getMousePosition();
private:
    InputHandler();
    ~InputHandler();
    static InputHandler* instance;
    
    const Uint8* keyState;
    
    vector<bool> mouseButtonStates;
    Vector2D* mousePosition;
    enum mouse_buttons
    {
        LEFT,
        MIDDLE,
        RIGHT
    };
    
};

#endif
