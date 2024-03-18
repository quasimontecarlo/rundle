#include <math.h>

typedef struct {
    float x,y,z;
} Vec3;

typedef struct {
	float r,g,b;
}Color;

typedef struct {
	Vec3 origin, direction;
}Ray;

float vec_len(Vec3 v); // Declare the func to tell compiler that they are defined elsewhere
Vec3 vec_scale(Vec3 v, float s);
