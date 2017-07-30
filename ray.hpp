#ifndef RAY_HPP
#define RAY_HPP

#include "vector3.hpp"

class Ray
{
private:
    Vector3 origin;
    Vector3 direction;

public:

    Ray();
    Ray(const Vector3 &origin, const Vector3 &direction);

    Vector3 point(float t) const;
    Vector3 getOrigin() const;
    Vector3 getDirection() const;
};

#endif // RAY_HPP
