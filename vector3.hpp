#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <tuple>

class Vector3
{
private:
    std::tuple<float, float, float> data;

public:
    Vector3();
    Vector3(const float x, const float y, const float z);
    float x() const;
    float y() const;
    float z() const;
    float length() const;
    float squaredLenght() const;
    static Vector3 cross(const Vector3 &vectorA, const Vector3 &vectorB);
    static Vector3 makeUnitVector(const Vector3 &vector);
    static float dot(const Vector3 &vectorA, const Vector3 &vectorB);

    Vector3 operator -() const;
};

Vector3 operator +(const Vector3 &vector, const Vector3 &another);
Vector3 operator -(const Vector3 &vector, const Vector3 &another);
Vector3 operator *(const Vector3 &vector, const Vector3 &another);
Vector3 operator *(const Vector3 &vector, float scalar);
Vector3 operator *(float scalar, const Vector3 &vector);
Vector3 operator /(const Vector3 &vector, const Vector3 &another);
Vector3 operator /(const Vector3 &vector, float scalar);

#endif // VECTOR3_HPP
