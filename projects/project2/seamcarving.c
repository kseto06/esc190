#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "seamcarving.h"
#include "c_img.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

/*
struct rgb_img {
    uint8_t *raster;
    size_t height;
    size_t width;
};
*/

/*
Compiler cmd:
gcc -o seamcarving seamcarving.c c_img.c -lm
*/

// Dual-Gradient Energy Function:
double square(double x) {
    return pow(x, 2);
}

void calc_energy(struct rgb_img *im, struct rgb_img **grad) {
    //Initialize img and gradient variables
    create_img(grad, im->height, im->width);
    double x_vals[3];
    double y_vals[3];
    double E;

    size_t h = im->height;
    size_t w = im->width;

    //Allocating the gradient
    *grad = malloc(sizeof(struct rgb_img));
    (*grad)->height = h;
    (*grad)-> width = w;
    (*grad)->raster = malloc(3 * h * w);

    //Computing the gradient values for each pixel
    for (size_t y = 0; y < h; y++) {
        for (size_t x = 0; x < w; x++) {
            // Cols 0, 1, 2 correspond to R, G, B, get the pixels
            for (int col = 0; col < 3; col++) {
                x_vals[col] = get_pixel(im, y, (x+1) % w, col) - get_pixel(im, y, (x - 1 + w) % w, col);
                y_vals[col] = get_pixel(im, (y+1) % h, x, col) - get_pixel(im, (y - 1 + h) % h, x, col); 
            }
            //Compute the energies of pixel (y, x) and set it:
            E = (uint8_t)(sqrt(square(x_vals[0]) + square(x_vals[1]) + square(x_vals[2]) + square(y_vals[0]) + square(y_vals[1]) + square(y_vals[2])) / 10);
            set_pixel(*grad, y, x, E, E, E);
        }
    }
}

void dynamic_seam(struct rgb_img *grad, double **best_arr) {
    size_t h = grad->height;
    size_t w = grad->width;
    *best_arr = malloc(sizeof(double) * h * w);

    for (size_t y = 0; y < h; y++) {
        for (size_t x = 0; x < w; x++) {
            int min;
            if (y == 0) {
                (*best_arr)[y * w + x] = get_pixel(grad, y, x, 0);
                continue;

            //Top + right:
            } else if (x == 0) {
                min = (*best_arr)[(y - 1) * w + x];
                if (min > (*best_arr)[(y - 1) * w + x + 1]) {
                    min = (*best_arr)[(y - 1) * w + x + 1];
                }
            
            //Top + Left:
            } else if (x == w - 1) {
                min = (*best_arr)[(y - 1) * w + x];
                if (min > (*best_arr)[(y - 1) * w + x - 1]) {
                    min = (*best_arr)[(y - 1) * w + x - 1];
                }
                
            //All:
            } else {
                min = (*best_arr)[(y - 1) * w + x];
                //Top + right
                if (min > (*best_arr)[(y - 1) * w + x + 1]) {
                    min = (*best_arr)[(y - 1) * w + x + 1];
                } 
                // Top + left
                if (min > (*best_arr)[(y - 1) * w + x - 1]) {
                    min = (*best_arr)[(y - 1) * w + x - 1];
                }
            }

            // Store the min cost
            (*best_arr)[y * w + x] = get_pixel(grad, y, x, 0) + min;
        }
    }
}

void recover_path(double *best, int height, int width, int **path) {

}

void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path) {

}

//Loading a RGB img in struct rgb_img form for testing
int load_rgb_img(struct rgb_img *img, const char *filename) {
    int w, h, channels;

    // We force 3 channels: RGB
    uint8_t *data = stbi_load(filename, &w, &h, &channels, 3);
    if (data == NULL) {
        return 1; // failed
    }

    img->width = (size_t)w;
    img->height = (size_t)h;
    img->raster = data; // already RGB, ready to use

    print_grad(img);

    return 0; // success
}

//Testing: 
int main() {
    struct rgb_img im;
    load_rgb_img(&im, "assets/6x5.png");
    struct rgb_img *grad;
    calc_energy(&im, &grad);
    print_grad(grad);

    double *best;
    dynamic_seam(grad, &best);
    for (size_t y = 0; y < grad->height; y++) {
        for (size_t x = 0; x < grad->width; x++) {
            printf("%f ", best[y * grad->width + x]);
        }
        printf("\n");
    }

    return 0;
}

