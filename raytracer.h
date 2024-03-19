#include "shapes.h"
void render_scene(char array[10][10]);
static void add_point_light(Light* light, Camera* camera);
static void compute_color(Ray* ray, Light* light, Camera* camera);
Vec3 vec_sub(Vec3 a, Vec3 b);
Camera create_camera(Vec3 pos, Vec3 look_at);
Ray make_ray(Camera camera, Vec3 dest);
