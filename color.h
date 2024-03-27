#ifndef COLOR_H
#define COLOR_H

#include <math.h>
#include <stdio.h>

typedef struct {
    double r;
    double g;
    double b;
} color;

void write_color(FILE *out, color pixel_color) {
    // Write the translated [0,255] value of each color component.
    fprintf(out, "%d %d %d\n", (int)(pixel_color.r * 255), (int)(pixel_color.g * 255), (int)(pixel_color.b * 255));
}

void write_ascii(FILE *out, color pixel_color) {
    double avg = ((int)(pixel_color.r * 255) + (int)(pixel_color.g * 255) + (int)(pixel_color.b * 255)) / 3;
    char c = avg > 255/2 ? '.' : '/';
    fprintf(out, "%c", c);
}

#endif
