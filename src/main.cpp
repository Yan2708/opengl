#include "common.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "window.h"
#include "shader_program.h"
#include "VBO.h"
#include "VAO.h"
#include "VAP.h"
#include "EBO.h"
#include "texture.h"
#include "camera.h"
#include "InputHandler.h"

float vertices[] = {
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};

glm::vec3 cubePositions[] = {
    glm::vec3( 0.0f,  0.0f,  0.0f), 
    glm::vec3( 2.0f,  5.0f, -15.0f), 
    glm::vec3(-1.5f, -2.2f, -2.5f),  
    glm::vec3(-3.8f, -2.0f, -12.3f),  
    glm::vec3( 2.4f, -0.4f, -3.5f),  
    glm::vec3(-1.7f,  3.0f, -7.5f),  
    glm::vec3( 1.3f, -2.0f, -2.5f),  
    glm::vec3( 1.5f,  2.0f, -2.5f), 
    glm::vec3( 1.5f,  0.2f, -1.5f), 
    glm::vec3(-1.3f,  1.0f, -1.5f)  
};

unsigned int indices[] = {  
    0, 1, 3, // first triangle
    1, 2, 3  // second triangle
};

int width = 800;
int height = 600;

int main() {
    
    Window::loadLibs();
    
    Window* win = new Window(width,height,"test");

    std::vector<Shader*> shaders({
        new Shader("./assets/shaders/basic_vert.glsl",GL_VERTEX_SHADER),
        new Shader("./assets/shaders/basic_frag.glsl", GL_FRAGMENT_SHADER)
    });

    ShaderProgram* program = new ShaderProgram(shaders);

    VAO vao;
    VBO vbo;
    VAP vap(0,3,GL_FLOAT,GL_FALSE,5*sizeof(float),(void*)0);
    // VAP vapColor(1,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(3*sizeof(float)));
    VAP vapTexture(2,2,GL_FLOAT,GL_FALSE,5*sizeof(float),(void*)(3*sizeof(float)));
    vao.bind();
    vbo.bind();
    vbo.buffer(vertices,sizeof(vertices));
    vap.enable();
    // vapColor.enable();
    vapTexture.enable();
    vao.bind();

    // EBO ebo;
    // ebo.bind();
    // ebo.buffer(indices, sizeof(indices));

    texture* tex = new texture(GL_REPEAT, GL_LINEAR, GL_LINEAR_MIPMAP_NEAREST);
    tex->load("./assets/textures/wall.jpg", GL_RGB);

    texture* tex2 = new texture(GL_REPEAT, GL_NEAREST, GL_NEAREST);
    tex2->load("./assets/textures/awesomeface.jpg", GL_RGBA);

    program->use();
    program->setUniformi("texture1", {0});
    program->setUniformi("texture2", {1});

    
    Camera* camera = new Camera(glm::vec3(10,0,20), width, height, false, 55, 200);
    glm::mat4 projection = camera->getProjection();

    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    while(!glfwWindowShouldClose(win->window))
    {
        // inputs
        camera->move(win->inputs->keyPress, win->inputs->mouseOffset, deltaTime);
        win->processInput();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // render
        program->use();
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;  
        glEnable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        for(unsigned int i = 0; i < 10; i++)
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);
            float angle = 20.0f * i; 
            model = glm::rotate(model, glm::radians(angle) * currentFrame, glm::vec3(1.0f, 0.3f, 0.5f));
            program->setUniformMatrix4f("model", model);
            program->setUniformMatrix4f("view", camera->getView());
            program->setUniformMatrix4f("projection", projection);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        tex->bind(GL_TEXTURE0);
        tex2->bind(GL_TEXTURE1);
        vao.bind();

        glDrawArrays(GL_TRIANGLES, 0, 36);
        // swap buffers & poll events
        win->check();
    }
    Window::terminateGlfw();
    return 0;
}

