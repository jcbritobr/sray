#include "ray.hpp"

Vector3 Ray::getOrigin() const
{
    return origin;
}

Vector3 Ray::getDirection() const
{
    return direction;
}

Ray::Ray()
{}

Ray::Ray(const Vector3 &origin, const Vector3 &direction)
    :origin(origin), direction(direction)
{

}

Vector3 Ray::point(float t) const
{
    return origin + (direction * t);
}
