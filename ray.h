#ifndef RAY_H
#define RAY_H

#include "vec3.h"

typedef struct {
    vec3 orig;
    vec3 dir;
} ray;

ray ray_create(vec3 origin, vec3 direction) {
    ray new_ray;
    new_ray.orig = origin;
    new_ray.dir = direction;
    return new_ray;
}
vec3 ray_origin(const ray* r) {
    return r->orig;
}

vec3 ray_direction(const ray* r) {
    return r->dir;
}

vec3 ray_at(const ray* r, double t) {
    vec3 scaled_dir = vec3_scale(r->dir, t);
    vec3 new_vec = vec3_add(r->orig, scaled_dir);
    return new_vec;
}

#endif // RAY_H
