#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "stb_image.h"
#include "stb_image_write.h"

void adjust_img_brightness(const char *file_path, const char *output_dir, float brightness_factor) {
    int width, height, channels;
    unsigned char *img = stbi_load(file_path, &width, &height, &channels, 0);
    if (img == NULL) {
        fprintf(stderr, "Image file not found: %s\n", file_path);
        return;
    }

    int img_size = width * height * channels;
    for (int i = 0; i < img_size; i++) {
        int value = img[i] * brightness_factor;
        img[i] = value > 255 ? 255 : value;
    }

    //Save output file
    char output_path[256];
    snprintf(output_path, sizeof(output_path), "%s/output_image.png", output_dir);

    if (!stbi_write_png(output_path, width, height, channels, img, width * channels)) {
        fprintf(stderr, "Failed to save image: %s\n", output_path);
    }

    stbi_image_free(img);
}

int main() {
    adjust_img_brightness("c_assets/cannon.png", "c_assets", 1.2);
    adjust_img_brightness("c_assets/cannon.png", "c_assets", 1.4);
    adjust_img_brightness("c_assets/cannon.png", "c_assets", 1.6);
    adjust_img_brightness("c_assets/cannon.png", "c_assets", 1.8);
    adjust_img_brightness("c_assets/cannon.png", "c_assets", 2.0);
    return 0;
}