#include "window.h"
#include "InputHandler.h"
Window::Window(int width, int height, std::string title) : width(width), height(height)
{
    GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    this->window = window;
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }    
    Window::framebuffer_size_callback(window, width, height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 
    inputs = new InputHandler();
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);  
    glfwSetCursorPosCallback(window, mouse_callback); 
    // store pointer so we can retrieve class from GLFWwindow 
    glfwSetWindowUserPointer(window, this);
}

Window::~Window()
{
    delete inputs;
}

int Window::loadLibs()
{
    // Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    return 0;
}

void Window::terminateGlfw()
{
    glfwTerminate();
}

void Window::check()
{
    glfwSwapBuffers(window);
    glfwPollEvents();    
}

void Window::mouse_callback(GLFWwindow *window, double xpos, double ypos)
{
    Window* instance = static_cast<Window*>(glfwGetWindowUserPointer(window));
    if(instance){
       instance->inputs->setMouseXY(xpos,ypos);
    }
}

void Window::framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    Window* instance = static_cast<Window*>(glfwGetWindowUserPointer(window));
    if(instance){
        instance->width = width;
        instance->height = height;
        glViewport(0, 0, width, height);
    }
}

bool Window::checkKeyPressed(int key)
{
    return glfwGetKey(window, key) == GLFW_PRESS;
}

float Window::getAspectRatio()
{
    return width/height;
}

void Window::processInput()
{

    inputs->setInput(GLFW_KEY_W, checkKeyPressed(GLFW_KEY_W));
    inputs->setInput(GLFW_KEY_S, checkKeyPressed(GLFW_KEY_S));
    inputs->setInput(GLFW_KEY_A, checkKeyPressed(GLFW_KEY_A));
    inputs->setInput(GLFW_KEY_D, checkKeyPressed(GLFW_KEY_D));
    inputs->setInput(GLFW_KEY_SPACE, checkKeyPressed(GLFW_KEY_SPACE));
    inputs->setInput(GLFW_KEY_LEFT_SHIFT, checkKeyPressed(GLFW_KEY_LEFT_SHIFT));
    inputs->mouseOffset = glm::vec2(0);
}