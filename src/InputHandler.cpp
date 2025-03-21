#include "InputHandler.h"

InputHandler::InputHandler()
{
    keyPress = {};
    mouseXY = glm::vec2(0);
    firstMouse=true;
}

InputHandler::~InputHandler()
{
}

void InputHandler::setInput(int key, bool pressed)
{
    keyPress[key]=pressed;
}

void InputHandler::setMouseXY(float x, float y)
{
    if(firstMouse){
        mouseXY.x=x;
        mouseXY.y=y;
        firstMouse = false;
    }
    mouseOffset.x = x - mouseXY.x; 
    mouseOffset.y = mouseXY.y - y;  
    mouseXY.x=x;
    mouseXY.y=y;
    std::cout << mouseOffset.x << " "<< mouseOffset.y << "\n";
}
