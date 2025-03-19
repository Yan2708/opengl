#include <glad/glad.h>
#include "shader_program.h"

ShaderProgram::ShaderProgram(std::vector<Shader*> shaders)
{
    id=glCreateProgram();
    for(auto i=0;i < shaders.size();i++) {
        glAttachShader(id, shaders[i]->id);
    }
    glLinkProgram(id);
    for(auto i=0;i < shaders.size();i++) {
        glDeleteShader(shaders[i]->id);
    }
    char infoLog[512];
    int  success;
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(id, 512, nullptr, infoLog);
    }
}

void ShaderProgram::use()
{
    glUseProgram(id);
}

void ShaderProgram::setUniformf(const char* name, std::vector<float> values)
{
    int uniformLocation = glGetUniformLocation(id, name);
    switch (values.size())
    {
    case 1:
        glUniform1f(uniformLocation, values[0]);
        break;
    case 2:
        glUniform2f(uniformLocation, values[0],values[1]);
        break;
    case 3:
        glUniform3f(uniformLocation, values[0],values[1],values[2]);
        break;
    case 4:
        glUniform4f(uniformLocation, values[0],values[1],values[2],values[3]);
        break;
    default:
        return;
    }
}

void ShaderProgram::setUniformMatrix4f(const char *name, glm::mat4 mat)
{
    unsigned int transformLoc = glGetUniformLocation(id, name);
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(mat));
}


void ShaderProgram::setUniformi(const char *name, std::vector<int> values)
{
    int uniformLocation = glGetUniformLocation(id, name);
    switch (values.size())
    {
    case 1:
        glUniform1i(uniformLocation, values[0]);
        break;
    case 2:
        glUniform2i(uniformLocation, values[0],values[1]);
        break;
    case 3:
        glUniform3i(uniformLocation, values[0],values[1],values[2]);
        break;
    case 4:
        glUniform4i(uniformLocation, values[0],values[1],values[2],values[3]);
        break;
    default:
        return;
    }
}
