class texture
{
private:
    /* data */
    int height, width, channels;

public:
  texture(int wrappingMode, int magFilterMode, int minFilterMode);
  ~texture();

  unsigned int id;

  void load(const char* path);
  void bind(int activeTexture);
};
