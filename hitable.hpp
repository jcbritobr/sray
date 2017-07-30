#ifndef HITTABLE_HPP
#define HITTABLE_HPP

#include <memory>
#include "vector3.hpp"
#include "ray.hpp"

class Behavioral;

struct HitRecord {
    HitRecord(){}
    float t;
    Vector3 p;
    Vector3 normal;
    std::shared_ptr<Behavioral> material;
};

class Hitable
{
public:
    virtual bool hit(const Ray &ray, float t_min, float t_max, HitRecord &rec) const = 0;
};

#endif // HITTABLE_HPP
