#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "seamcarving.h"
#include "c_img.h"

double square(double x) {
    return pow(x, 2);
}

void calc_energy(struct rgb_img *im, struct rgb_img **grad) {
    create_img(grad, im->height, im->width);
    double x_vals[3];
    double y_vals[3];
    double E;

    size_t h = im->height;
    size_t w = im->width;

    //Allocating the gradient
    *grad = malloc(sizeof(struct rgb_img));
    (*grad)->height = h;
    (*grad)->width = w;
    (*grad)->raster = malloc(3 * h * w);

    //Computing the gradient values for each pixel
    for (size_t y = 0; y < h; y++) {
        for (size_t x = 0; x < w; x++) {
            for (int col = 0; col < 3; col++) {
                // Cols 0, 1, 2 correspond to R, G, B, get the pixels
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
            double min;
            if (y == 0) {
                (*best_arr)[y * w + x] = get_pixel(grad, y, x, 0);
                continue;
            //Top + right:
            } else if (x == 0) {
                min = (*best_arr)[(y - 1) * w + x];
                if ((*best_arr)[(y - 1) * w + x + 1] < min) {
                    min = (*best_arr)[(y - 1) * w + x + 1];
                }
            //Top + Left:
            } else if (x == w - 1) {
                min = (*best_arr)[(y - 1) * w + x];
                if ((*best_arr)[(y - 1) * w + x - 1] < min) {
                    min = (*best_arr)[(y - 1) * w + x - 1];
                }
            //All:
            } else {
                //Top + right
                min = (*best_arr)[(y - 1) * w + x];
                if ((*best_arr)[(y - 1) * w + x + 1] < min) {
                    min = (*best_arr)[(y - 1) * w + x + 1];
                }
                //Top + Left
                if ((*best_arr)[(y - 1) * w + x - 1] < min) {
                    min = (*best_arr)[(y - 1) * w + x - 1];
                }
            }
            (*best_arr)[y * w + x] = get_pixel(grad, y, x, 0) + min;
        }
    }
}

void recover_path(double *best, int height, int width, int **path) {
    double minimum_sum;
    int current_index;

    *path = malloc(sizeof(int) * height);

    int last_row = height - 1;
    current_index = last_row * width;
    minimum_sum = best[current_index];
    for (int col = 0; col < width; col++) {
        int idx = last_row * width + col;
        if (best[idx] < minimum_sum) {
            minimum_sum = best[idx];
            current_index = idx;
        }
    }

    for (int row = height-1; row>=0; row--){
        int col = current_index % width;

        (*path)[row] = col;
        int up_index = current_index - width;

        if(row == 0) break;

        int next_index = up_index;
        minimum_sum = best[up_index];

        if (col > 0 && best[up_index - 1] < minimum_sum) {
            minimum_sum = best[up_index - 1];
            next_index = up_index - 1;
        }

        if (col < width - 1 && best[up_index + 1] < minimum_sum) {
            minimum_sum = best[up_index + 1];
            next_index = up_index + 1;
        }

        current_index = next_index;
    }
}

void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path) {
    create_img(dest, src->height, src->width - 1);
    double red, green, blue;
    for (int row = 0; row < src->height; row++) {
        int offset = 0;
        for (int col = 0; col < src->width; col++) {
            if (col == path[row]) {
                offset = 1;
            } else {
                red = get_pixel(src, row, col, 0);
                green = get_pixel(src, row, col, 1);
                blue = get_pixel(src, row, col, 2);
                set_pixel(*dest, row, col - offset, red, green, blue);
            }
        }
    }
}