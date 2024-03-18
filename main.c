#include <stdio.h>
#include "raytracer.h"

int main(){
	char array[10][10]; //create 2d array
	render_scene(array);	// pass the arrray to render function
	
	// printing the array
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)
			printf("%c",array[i][j]);
		printf("\n");
	}
	return 0;
}
