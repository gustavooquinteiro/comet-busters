#ifndef _INPUT_HANDLER_H_
#define _INPUT_HANDLER_H_

#include <SDL2/SDL.h>
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
private:
    InputHandler();
    ~InputHandler();
    static InputHandler* instance;
    
    const Uint8* keyState;
    
    vector<bool>mouseButtonStates;
    enum mouse_buttons
    {
        LEFT,
        MIDDLE,
        RIGHT
    };
};

#endif
