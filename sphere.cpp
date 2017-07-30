#include <cmath>
#include "sphere.hpp"

Sphere::Sphere()
{}

Sphere::Sphere(Vector3 center, float radius, std::shared_ptr<Behavioral> m): center(center), radius(radius),
    material(m)
{}

bool Sphere::hit(const Ray &ray, float t_min, float t_max, HitRecord &rec) const
{
    Vector3 oc = ray.getOrigin() - center;
    float a = Vector3::dot(ray.getDirection(), ray.getDirection());
    float b = Vector3::dot(oc, ray.getDirection());
    float c = Vector3::dot(oc, oc) - radius * radius;
    float discriminant = b * b - a * c;

    if (discriminant > 0) {
        float temp = (-b - sqrt(discriminant))/a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = ray.point(rec.t);
            rec.normal = (rec.p - center) / radius;
            rec.material = material;
            return true;
        }

        temp = (-b + sqrt(discriminant)) / a;

        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = ray.point(rec.t);
            rec.normal = (rec.p - center) / radius;
            rec.material = material;
            return true;
        }
    }

    return false;
}
