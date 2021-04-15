#include <stdio.h>
#include <stdint.h>

enum ImageType {
  PNG, JPG, BMP, TGA
};

struct Image {
  uint8_t* data = NULL;
  size_t size = 0;
  int w;
  int h;
  int channels;

  Image(const char* filename);
  Image(int w, int h, int channels);
  Image(const Image& img);
  ~Image();

  bool read(const char* filename);
  bool write(const char* filename);

  ImageType getFileType(const char* filename);

  Image& std_convolve_clamp_to_0(uint8_t channel, uint32_t ker_w, uint32_t ker_h, double ker[], uint32_t cr, uint32_t cc);
  Image& std_convolve_clamp_to_border(uint8_t channel, uint32_t ker_w, uint32_t ker_h, double ker[], uint32_t cr, uint32_t cc);
  Image& std_convolve_cyclic(uint8_t channel, uint32_t ker_w, uint32_t ker_h, double ker[], uint32_t cr, uint32_t cc);

  Image& diffmap(Image& img);
  Image& diffmap_scale(Image& img, uint8_t scl = 0);

  Image& grayscale_avg();
  Image& grayscale_lum();
  
  Image& colorMask(float r, float g, float b);
};
