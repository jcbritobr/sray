#ifndef HITABLELIST_H
#define HITABLELIST_H

#include <vector>
#include <memory>
#include "hitable.hpp"

class HitableList
{
private:
    std::vector<std::shared_ptr<Hitable>> list;
public:
    HitableList(std::vector<std::shared_ptr<Hitable>> &list);
    bool hit(const Ray &ray, float t_min, float t_max, HitRecord &record);
};

#endif // HITABLELIST_H
