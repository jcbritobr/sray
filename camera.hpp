#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <memory>
#include "ray.hpp"
#include "behavioral.hpp"

class Camera
{
private:
    std::shared_ptr<Vector3> origin;
    std::shared_ptr<Vector3> lowerLeftCorner;
    std::shared_ptr<Vector3> horizontal;
    std::shared_ptr<Vector3> vertical;
    float lensRadius;
    Vector3 u, v, w;

public:
    Camera();
    Camera(Vector3 from, Vector3 to, Vector3 vup, float vfov, float aspect, float aperture, float focusDist);
    Ray getRay(float s, float t);
};

#endif // CAMERA_HPP
