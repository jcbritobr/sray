#ifndef LAMBERTIAN_HPP
#define LAMBERTIAN_HPP

#include "behavioral.hpp"
#include "vector3.hpp"

class Lambertian : public Behavioral
{
private:
    Vector3 albedo;
    Vector3 diffuseMatte();
public:
    Lambertian(const Vector3 &a);
    bool scatter(const Ray &ray, const HitRecord &record, Vector3 &attenuation, Ray &scattered);
};

#endif // LAMBERTIAN_HPP
