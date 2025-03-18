class VBO
{
private:
    /* data */
public:
    VBO();
    ~VBO();
    unsigned int id; 

    void bind();
    void buffer(float* vertices, int size);
    void unbind();
};
