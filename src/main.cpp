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

  // Diffmap example
  // Image test1("imgs/test1.png");
  // Image test2("imgs/test2.png");
  // Image diff = test1;
  // diff.diffmap(test2);
  // diff.write("image/diff.png");
 
  // Convolution example
  Image test2("stats.png");
  double ker[] = { 1/16.0, 2/16.0, 1/16.0,
				   2/16.0, 4/16.0, 2/16.0,
				   1/16.0, 2/16.0, 1/16.0}; // gaussian blur
  
  test2.std_convolve_clamp_to_0(0, 3, 3, ker, 1, 1);
  test2.std_convolve_clamp_to_0(1, 3, 3, ker, 1, 1);
  test2.std_convolve_clamp_to_0(2, 3, 3, ker, 1, 1);
  test2.write("blurred.png");

  // Image copy = test;
  // for(int i = 0; i < copy.w*copy.channels; ++i) {
  //	copy.data[i] = 255;
  // }
  // copy.write("copy.png");
  
  // Image blank(100, 100, 3);
  // blank.write("blank.jpg");
  return 0;
}
