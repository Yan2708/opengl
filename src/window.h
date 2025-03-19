#ifndef WINDOW_H
#define WINDOW_H

#include "common.h"

class Window
{
public:
    Window(int width, int height, std::string title);
    ~Window();

    static int loadLibs();
    static void terminateGlfw();
    
    void check();
    void processInput();

    GLFWwindow* window;
private:
    void static framebuffer_size_callback(GLFWwindow* window, int width, int height);
};

#endif