#ifndef DIELECTRIC_HPP
#define DIELECTRIC_HPP

#include "behavioral.hpp"

class Dielectric : public Behavioral
{
private:
    Vector3 reflect(const Vector3 &v, const Vector3 &n);
    bool refract(const Vector3 &v, const Vector3 &n, float niOverNt, Vector3 &refracted);
    float schilick(float cosine, float ref);
    float refIdx;
public:
    Dielectric(float ri);
    bool scatter(const Ray &ray, const HitRecord &record, Vector3 &attenuation, Ray &scattered) override;
};

#endif // DIELECTRIC_HPP
