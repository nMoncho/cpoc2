#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lodepng.h>
#include "r_main.h"

void flip_image_vertical(unsigned char *data, unsigned int width, unsigned int height);

void load_texture(const char *filename) {
  unsigned int error;
  unsigned char *data;
  unsigned int width, height;

  error = lodepng_decode32_file(&data, &width, &height, filename);
  if (error) {
    fprintf(stderr, "error %u: %s\n", error, lodepng_error_text(error));
  }

  flip_image_vertical(data, width, height);
}

void flip_image_vertical(unsigned char *data, unsigned int width, unsigned int height) {
  unsigned int size = width * height * 4;
  unsigned int stride = sizeof(char) * width * 4;
  unsigned char *new_data = (unsigned char *) malloc(sizeof(unsigned char) * size);

  for (unsigned int i = 0; i < height; i++) {
    unsigned int j = height - i - 1;
    memcpy(new_data + j * stride, data + i * stride, stride);
  }

  memcpy(data, new_data, size);
  free(new_data);
}
