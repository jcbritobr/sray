#ifndef BEHAVIORAL_H
#define BEHAVIORAL_H

#include "ray.hpp"
#include "vector3.hpp"
#include "hitable.hpp"

class Behavioral
{
public:
    virtual bool scatter(const Ray &ray, const HitRecord &record, Vector3 &attenuation, Ray &scattered) = 0;
};

Vector3 reflect(const Vector3 &v, const Vector3 &n);
float schilick(float cosine, float ref);
bool refract(const Vector3 &v, const Vector3 &n, float niOverNt, Vector3 &refracted);
Vector3 diffuseMatte();

#endif // BEHAVIORAL_H
