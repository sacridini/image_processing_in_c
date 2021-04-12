#include <iostream>
#include "Image.h"

int main(int argc, char** argv) {
  Image test("stats.png");
  
  // grayscale test
  Image gray_avg = test;
  gray_avg.grayscale_avg();
  gray_avg.write("gray_avg.png");


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
