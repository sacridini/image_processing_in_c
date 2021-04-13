#include "Image.h"

int main(int argc, char** argv) {
  Image test("stats.png");
  
  // grayscale avg test
  Image gray_avg = test;
  gray_avg.grayscale_avg();
  gray_avg.write("gray_avg.png");

  // grayscale lum test
  Image gray_lum = test;
  gray_lum.grayscale_lum();
  gray_lum.write("gray_lum.png");

  // Color Mask
  test.colorMask(0,0,1); // Mask red and green bands
  test.write("blue.png"); // Save a blue image :)


  // test.write("stats_copy.png");
  
  // Image copy = test;
  // for(int i = 0; i < copy.w*copy.channels; ++i) {
  //	copy.data[i] = 255;
  // }
  // copy.write("copy.png");
  
  // Image blank(100, 100, 3);
  // blank.write("blank.jpg");
  return 0;
}
