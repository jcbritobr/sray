#ifndef METAL_HPP
#define METAL_HPP

#include "behavioral.hpp"
#include "vector3.hpp"

class Metal : public Behavioral
{
private:
    Vector3 albedo;
    float fuzz;
public:
    Metal(const Vector3 &a, float f);
    bool scatter(const Ray &ray, const HitRecord &record, Vector3 &attenuation, Ray &scattered);
};

#endif // METAL_HPP
