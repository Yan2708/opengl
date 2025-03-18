class VAP
{
private:
    /* data */
    int position;
    int vertexAttributeSize; 
    int type;
    int normalized; 
    long stride; 
    void* offset;
public:
    VAP(int position, int vertexAttributeSize, int type, int normalized, long stride, void* offset);

    void enable();
    void disable();
};

