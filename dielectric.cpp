#include <cmath>
#include "dielectric.hpp"
#include "ray.hpp"

Dielectric::Dielectric(float ri): refIdx(ri)
{}

bool Dielectric::scatter(const Ray &ray, const HitRecord &record, Vector3 &attenuation, Ray &scattered)
{
    Vector3 outwardNormal;
    Vector3 reflected = reflect(ray.getDirection(), record.normal);
    float niOverNt = 0.0f;
    attenuation = Vector3(1.0, 1.0, 1.0);
    Vector3 refracted;
    float reflectProb = 0.0f;
    float cosine = 0.0f;

    if (Vector3::dot(ray.getDirection(), record.normal) > 0) {
        outwardNormal = -record.normal;
        cosine = Vector3::dot(ray.getDirection(), record.normal) / ray.getDirection().length();
        cosine = sqrt(1.0f - refIdx * refIdx * (1.0f - cosine * cosine));
    } else {
        outwardNormal = record.normal;
        niOverNt = 1.0 / refIdx;
        cosine = -Vector3::dot(ray.getDirection(), record.normal) / ray.getDirection().length();
    }

    if (refract(ray.getDirection(), outwardNormal, niOverNt, refracted)) {
        reflectProb = schilick(cosine, refIdx);

    } else {
        reflectProb = 1.0;
    }

    if (drand48() < reflectProb) {
        scattered = Ray(record.p, reflected);
    } else {
        scattered = Ray(record.p, refracted);
    }

    return true;
}
