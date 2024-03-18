#include "vec_math.h"
// Definition of Basic shapes
typedef struct {
    Vec3 position;
    float width, height, depth;
} Cube;

typedef struct {
    Vec3 normal;
    float d;
} Plane;

typedef struct {
    Vec3 center;
    float radius;
} Sphere;

typedef struct {
    Vec3 position, look_at;
} Camera;

typedef struct {
	Camera camera;
}Scene;

typedef struct {

	struct {
		Vec3 position; // Position of light source
		float intensity; // Intensity of light
	}pointLight;
}Light;

