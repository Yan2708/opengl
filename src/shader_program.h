#include <vector>
#include <string>
#include <vector>
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
    void setUniformi(const char* name, std::vector<int> values);
};
