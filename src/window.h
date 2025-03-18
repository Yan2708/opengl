#pragma once
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>

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

