#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H
#include "common.h"
#include "shader.h"

class ShaderProgram
{
private:
    /* data */
public:
    ShaderProgram(std::vector<Shader*> shaders);
    ~ShaderProgram();
    
    int id;

    void use();

    void setUniformf(const char* name, std::vector<float> values);
    void setUniformMatrix4f(const char* name, glm::mat4 vec);
    void setUniformi(const char* name, std::vector<int> values);
};
#endif