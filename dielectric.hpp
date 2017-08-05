#ifndef DIELECTRIC_HPP
#define DIELECTRIC_HPP

#include "behavioral.hpp"

class Dielectric : public Behavioral
{
private:
    float refIdx;
public:
    Dielectric(float ri);
    bool scatter(const Ray &ray, const HitRecord &record, Vector3 &attenuation, Ray &scattered) override;
};

#endif // DIELECTRIC_HPP
