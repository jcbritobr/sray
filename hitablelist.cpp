#include "hitablelist.hpp"

HitableList::HitableList(std::vector<std::shared_ptr<Hitable> > &list)
    : list(list)
{}

bool HitableList::hit(const Ray &ray, float t_min, float t_max, HitRecord &record)
{
    HitRecord tempRecord;
    bool hited = false;
    float closest = t_max;

    for (int i = 0; i < list.size(); ++i) {
       if(list[i]->hit(ray, t_min, closest, tempRecord)) {
           hited = true;
           closest = tempRecord.t;
           record = tempRecord;
       }
    }

    return hited;
}
