#ifndef VEC3_H
#define VEC3_H

#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
} vec3;

vec3 vec3_add(vec3 u, vec3 v) {
    return (vec3){u.x + v.x, u.y + v.y, u.z + v.z};
}

vec3 vec3_sub(vec3 u, vec3 v) {
    return (vec3){u.x - v.x, u.y - v.y, u.z - v.z};
}

vec3 vec3_mul(vec3 u, vec3 v) {
    return (vec3){u.x * v.x, u.y * v.y, u.z * v.z};
}

vec3 vec3_div(vec3 v, double t) {
    return (vec3){v.x / t, v.y / t, v.z / t};
}

double dot(vec3 u, vec3 v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

vec3 cross(vec3 u, vec3 v) {
    return (vec3){u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x};
}

double length(vec3 v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

vec3 unit_vector(vec3 v) {
    return vec3_div(v, length(v));
}

#endif
