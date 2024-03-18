#include "raytracer.h"
#include "shapes.h"

void render_scene(char array[10][10]) {
    // 3. Iterate over each pixel in the 2D array (i.e., for each ray)
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
			// add point light
			add_point_light(Scene.light, Camera);
            // Calculate color of the ray
            int color_index = i * j % 8;  // Replace this with your color calculation
            
            // Map this color to the ASCII character and store it in the array
            array[i][j] = " .:-=+*#"[color_index];  // Simple 8-levels ASCII art
        }
    }    
}

static void add_point_light(Light* light, Camera* camera) {
	//init point light
	light->pointLight.position = (Vec3)(0);
	light->pointLight.intensity = 1;
}

static void compute_color(Ray* ray, Light* light, Camera* camera) {
	// init compute
}


Vec3 vec_sub(Vec3 a, Vec3 b){
	return(Vec3){a.x - b.x, a.y - b.y, a.z - b.z};
}

Camera create_camera(Vec3 pos, Vec3 look_at) {
	Camera camera= (Camera){pos, look_at};
	return camera;
}

Ray make_ray(Camera camera, Vec3 dest) {
    Vec3 direction = vec_sub(dest, camera.position); // Calculate the direction of the ray relative to the camera's position
    float dist = vec_len(direction); // This line should now work because vec_len() is defined in math.c
    direction = vec_scale(direction, -1); // Normalize the direction vector so that it forms a unit vector
    return (Ray){camera.position, direction}; // Create a new ray with the camera's position and the normalized direction
}
