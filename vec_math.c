#include "vec_math.h"

float vec_len(Vec3 v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); // Calculate the Euclidean length of the vector
}

Vec3 vec_scale(Vec3 v, float s) {
    return (Vec3){v.x * s, v.y * s, v.z * s}; // Scale the vector by a factor
}
