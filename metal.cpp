#include "metal.hpp"

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
