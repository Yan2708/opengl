#include <glad/glad.h>
#include <iostream>
#include <vector>
#include <cmath>
#include "window.h"
#include "shader_program.h"
#include "VBO.h"
#include "VAO.h"
#include "VAP.h"
#include "EBO.h"
#include "texture.h"
#include "stb_image.h"

float vertices[] = {
    // positions          // colors           // texture coords
     0.5,  0.5, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
     0.5, -0.5, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
    -0.5, -0.5, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
    -0.5,  0.5, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
};

unsigned int indices[] = {  
    0, 1, 3, // first triangle
    1, 2, 3  // second triangle
};

int main() {
    
    Window::loadLibs();
    
    Window* win = new Window(800,600,"test");

    std::vector<Shader*> shaders({
        new Shader("./assets/shaders/basic_vert.glsl",GL_VERTEX_SHADER),
        new Shader("./assets/shaders/basic_frag.glsl", GL_FRAGMENT_SHADER)
    });

    ShaderProgram* program = new ShaderProgram(shaders);

    VAO vao;
    VBO vbo;
    VAP vap(0,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)0);
    VAP vapColor(1,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(3*sizeof(float)));
    VAP vapTexture(2,2,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(6*sizeof(float)));
    vao.bind();
    vbo.bind();
    vbo.buffer(vertices,sizeof(vertices));
    vap.enable();
    vapColor.enable();
    vapTexture.enable();
    vao.bind();

    EBO ebo;
    ebo.bind();
    ebo.buffer(indices, sizeof(indices));

    texture* tex = new texture(GL_MIRRORED_REPEAT, GL_LINEAR, GL_LINEAR_MIPMAP_NEAREST);
    tex->load("./assets/textures/wall.jpg");

    texture* tex2 = new texture(GL_MIRRORED_REPEAT, GL_LINEAR, GL_LINEAR_MIPMAP_NEAREST);
    tex2->load("./assets/textures/texture.jpg");

    while(!glfwWindowShouldClose(win->window))
    {
        // inputs
        win->processInput();
        //background
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // render
        program->use();
        tex->bind(GL_TEXTURE0);
        program->setUniformi("texture1", {0});
        tex2->bind(GL_TEXTURE1);
        program->setUniformi("texture2", {1});
        vao.bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // swap buffers & poll events
        win->check();
    }
    Window::terminateGlfw();
    return 0;
}