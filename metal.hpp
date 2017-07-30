#ifndef METAL_HPP
#define METAL_HPP

#include "behavioral.hpp"
#include "vector3.hpp"

class Metal : public Behavioral
{
private:
    Vector3 albedo;
    float fuzz;
    Vector3 diffuseMatte();
    Vector3 reflect(const Vector3 &v, const Vector3 &n);
public:
    Metal(const Vector3 &a, float f);
    bool scatter(const Ray &ray, const HitRecord &record, Vector3 &attenuation, Ray &scattered);
};

#endif // METAL_HPP
