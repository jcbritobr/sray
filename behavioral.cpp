#include <cmath>
#include "behavioral.hpp"

Vector3 reflect(const Vector3 &v, const Vector3 &n)
{
    return v - (n * Vector3::dot(v, n) * 2);
}

float schilick(float cosine, float ref)
{
    float r0 = (1.0 - ref) / (1.0 + ref);
    r0 = r0 * r0;
    return r0 + (1.0 - r0)*pow((1.0 - cosine), 5.0);
}

bool refract(const Vector3 &v, const Vector3 &n, float niOverNt, Vector3 &refracted)
{
    Vector3 uv = Vector3::makeUnitVector(v);
    float dt = Vector3::dot(uv, n);
    float discriminant = 1.0 - niOverNt * niOverNt * (1.0 - dt * dt);
    if (discriminant > 0) {
        refracted = ((uv - n * dt) * niOverNt) - (n * sqrt(discriminant));
        return true;
    } else {
        return false;
    }
}

Vector3 diffuseMatte()
{
    Vector3 p;
    do {
        p = (Vector3(drand48(), drand48(), drand48()) * 2.0) - Vector3(1.0, 1.0, 1.0) ;
    } while (Vector3::dot(p, p) >= 1.0);

    return p;
}
