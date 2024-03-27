#include <stdio.h>
#include <math.h>
#include "color.h"
#include "vec3.h"

int main() {
    // Image
    int image_width = 100;
    int image_height = image_width * 0.25;

    // Render

    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
			//double pixel_color[3] = {double(i)/(image_width-1), double(j)/(image_height-1), 0};
			color pixel_color = {(double)i/(image_width-1), (double)j/(image_height-1), 0};
			write_ascii(stdout, pixel_color);
        }
		printf("\n");
    }
	printf("\n");
}
