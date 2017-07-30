#include <cmath>
#include "dielectric.hpp"
#include "ray.hpp"

Vector3 Dielectric::reflect(const Vector3 &v, const Vector3 &n)
{
    return v - (n * Vector3::dot(v, n) * 2);
}

bool Dielectric::refract(const Vector3 &v, const Vector3 &n, float niOverNt, Vector3 &refracted)
{
    Vector3 uv = Vector3::makeUnitVector(v);
    //Vector3 un = Vector3::makeUnitVector(n);
    float dt = Vector3::dot(uv, n);
    float discriminant = 1.0 - niOverNt * niOverNt * (1.0 - dt * dt);
    if (discriminant > 0) {
        refracted = ((uv - n * dt) * niOverNt) - (n * sqrt(discriminant));
        return true;
    } else {
        return false;
    }
}

float Dielectric::schilick(float cosine, float ref)
{
    float r0 = (1.0 - ref) / (1.0 + ref);
    r0 = r0 * r0;
    return r0 + (1.0 - r0)*pow((1.0 - cosine), 5.0);
}

Dielectric::Dielectric(float ri): refIdx(ri)
{}

bool Dielectric::scatter(const Ray &ray, const HitRecord &record, Vector3 &attenuation, Ray &scattered)
{
    Vector3 outwardNormal;
    Vector3 reflected = reflect(ray.getDirection(), record.normal);
    float niOverNt;
    attenuation = Vector3(1.0, 1.0, 1.0);
    Vector3 refracted;
    float reflectProb;
    float cosine;

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
