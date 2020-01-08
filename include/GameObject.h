#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

class GameObject
{
public:
    void draw();
    void update();
    void clean();
protected:
    int x;
    int y;
};

#endif
