#ifndef WINDOW_H
#define WINDOW_H

#include "common.h"
#include "InputHandler.h"

class Window
{
public:
    static int loadLibs();
    static void terminateGlfw();
    
    Window(int width, int height, std::string title);
    ~Window();
    
    InputHandler* inputs;
    GLFWwindow* window;
    
    void check();
    float getAspectRatio();
    void processInput();

private:
    int width, height;

    void static mouse_callback(GLFWwindow* window, double xpos, double ypos);
    void static framebuffer_size_callback(GLFWwindow* window, int width, int height);
    bool checkKeyPressed(int key);
};

#endif