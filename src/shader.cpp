#include "shader.h"
#include <fstream>
#include <sstream>

Shader::Shader(std::string path, int type)
{
    auto source = readFile(path); 
    this->id = glCreateShader(type);
    const char* ps = source.c_str();
    glShaderSource(id, 1, &ps, NULL);
    glCompileShader(id);
    int  success;
    char infoLog[512];
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(id, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

Shader::~Shader()
{
    glDeleteShader(id);
}

std::string Shader::readFile(std::string path)
{
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file!" << std::endl;
        return nullptr;
    }
    std::ostringstream oss;
    oss << file.rdbuf();
    std::string text = oss.str();
    file.close();
    return text;
}
