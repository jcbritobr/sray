#include "behavioral.hpp"

Vector3 randonInUnitDisk()
{
    Vector3 p;
    do {
        p = 2.0f * Vector3(drand48(), drand48(), 0.0f) - Vector3(1.0f, 1.0f, 0.0f);
    } while (Vector3::dot(p, p) >= 1.0f);

    return p;
}
