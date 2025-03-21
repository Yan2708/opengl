#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include "common.h"
class InputHandler
{
private:
    /* data */
    bool firstMouse;
public:
    std::map<int,bool> keyPress;
    glm::vec2 mouseXY;
    glm::vec2 mouseOffset;
    InputHandler();
    ~InputHandler();

    void setInput(int key, bool pressed);
    void setMouseXY(float x, float y);
};

#endif