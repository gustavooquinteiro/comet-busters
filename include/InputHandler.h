#ifndef _INPUT_HANDLER_H_
#define _INPUT_HANDLER_H_

#include <SDL2/SDL.h>

class InputHandler
{
public:
    static InputHandler* Instance();
    void update();
    void clean();
private:
    InputHandler();
    ~InputHandler();
    static InputHandler* instance;
};

#endif
