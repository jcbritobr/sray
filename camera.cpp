#include <cmath>
#include "camera.hpp"

Camera::Camera()
{}

Camera::Camera(Vector3 from, Vector3 to, Vector3 vup, float vfov, float aspect, float aperture, float focusDist)
{
    lensRadius = aperture / 2;
    float theta = vfov * M_PI/180;
    float halfHeight = tan(theta/2);
    float halfWidith = aspect * halfHeight;
    origin = std::make_shared<Vector3>(from);
    w = Vector3::makeUnitVector(from - to);
    u = Vector3::makeUnitVector(Vector3::cross(vup, w));
    v = Vector3::cross(w, u);
    Vector3 llc = *origin - halfWidith * focusDist * u -halfHeight *focusDist * v -focusDist*w;
    lowerLeftCorner = std::make_shared<Vector3>(llc);
    Vector3 horz = 2.0 * halfWidith * focusDist * u;
    horizontal = std::make_shared<Vector3>(horz);
    Vector3 vert = 2.0 * halfHeight * focusDist * v;
    vertical = std::make_shared<Vector3>(vert);
}

Ray Camera::getRay(float s, float t)
{
    Vector3 rd = lensRadius * randonInUnitDisk();
    Vector3 offset = u * rd.x() + v * rd.y();
    return Ray(*origin + offset, *lowerLeftCorner + s * *horizontal + t * *vertical - *origin - offset);
}
