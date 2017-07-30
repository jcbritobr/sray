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

Vector3 randonInUnitDisk();

#endif // BEHAVIORAL_H
