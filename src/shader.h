#include <string>

class Shader
{
public:
    Shader(std::string path, int type);
    ~Shader();
    unsigned int id;
private:
    static std::string readFile(std::string path);
};

