#include "metal.hpp"

Vector3 Metal::diffuseMatte()
{
    Vector3 p;
    do {
        p = (Vector3(drand48(), drand48(), drand48()) * 2.0) - Vector3(1.0, 1.0, 1.0) ;
    } while (Vector3::dot(p, p) >= 1.0);

    return p;
}

Vector3 Metal::reflect(const Vector3 &v, const Vector3 &n)
{
    return v - (n * Vector3::dot(v, n) * 2);
}

Metal::Metal(const Vector3 &a, float f): albedo(a)
{
    if(f < 1){
        fuzz = f;
    } else {
        fuzz = 1;
    }
}

bool Metal::scatter(const Ray &ray, const HitRecord &record, Vector3 &attenuation, Ray &scattered)
{
    Vector3 reflected = reflect(Vector3::makeUnitVector(ray.getDirection()), record.normal);
    scattered = Ray(record.p, reflected + diffuseMatte() * fuzz);
    attenuation = albedo;
    return (Vector3::dot(scattered.getDirection(), record.normal) > 0);
}
