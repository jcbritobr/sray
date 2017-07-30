#include "lambertian.hpp"

Vector3 Lambertian::diffuseMatte()
{
    Vector3 p;
    do {
        p = (Vector3(drand48(), drand48(), drand48()) * 2.0) - Vector3(1.0, 1.0, 1.0) ;
    } while (Vector3::dot(p, p) >= 1.0);

    return p;
}

Lambertian::Lambertian(const Vector3 &a): albedo(a)
{}

bool Lambertian::scatter(const Ray &ray, const HitRecord &record, Vector3 &attenuation, Ray &scattered)
{
    Vector3 target = record.p + record.normal + diffuseMatte();
    scattered = Ray(record.p, target - record.p);
    attenuation = albedo;
    return true;
}
