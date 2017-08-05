#include "lambertian.hpp"

Lambertian::Lambertian(const Vector3 &a): albedo(a)
{}

bool Lambertian::scatter(const Ray &ray, const HitRecord &record, Vector3 &attenuation, Ray &scattered)
{
    Vector3 target = record.p + record.normal + diffuseMatte();
    scattered = Ray(record.p, target - record.p);
    attenuation = albedo;
    return true;
}
