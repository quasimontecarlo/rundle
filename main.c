#include <stdio.h>
#include "raytracer.h"

int main(){
	char array[10][10]; //create 2d array
    Camera Camer = {(Vec3){0.0f,0.0f,0.0f}, (Vec3){1.0f,1.0f,1.0f}};
    Light Light;
	render_scene(&array[0][0], &Camera, &Light);	// pass the arrray to render function
	
	// printing the array
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)
			printf("%c",array[i][j]);
		printf("\n");
	}
	return 0;
}
