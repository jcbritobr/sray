#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <memory>
#include "vector3.hpp"
#include "hitable.hpp"
#include "behavioral.hpp"


class Sphere : public Hitable
{
private:
    Vector3 center;
    float radius;
    std::shared_ptr<Behavioral> material;
public:
    Sphere();
    Sphere(Vector3 center, float radius, std::shared_ptr<Behavioral> m);
    bool hit(const Ray &ray, float t_min, float t_max, HitRecord &rec) const;
};

#endif // SPHERE_HPP
