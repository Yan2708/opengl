#ifndef TEXTURE_H
#define TEXTURE_H
#include "common.h"
class texture
{
private:
    /* data */
    int height, width, channels;

public:
  texture(int wrappingMode, int magFilterMode, int minFilterMode);
  ~texture();

  unsigned int id;

  void load(const char* path, int format);
  void bind(int activeTexture);
};
#endif