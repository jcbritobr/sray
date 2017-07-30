#include <cmath>
#include "vector3.hpp"

float Vector3::x() const
{
    return std::get<0>(data);
}

float Vector3::y() const
{
    return std::get<1>(data);
}

float Vector3::z() const
{
    return std::get<2>(data);
}

float Vector3::length() const
{
    float dx = std::get<0>(data) * std::get<0>(data);
    float dy = std::get<1>(data) * std::get<1>(data);
    float dz = std::get<2>(data) * std::get<2>(data);

    return sqrt(dx + dy + dz);
}

float Vector3::squaredLenght() const
{
    float dx = std::get<0>(data) * std::get<0>(data);
    float dy = std::get<1>(data) * std::get<1>(data);
    float dz = std::get<2>(data) * std::get<2>(data);

    return dx + dy + dz;
}

Vector3 Vector3::cross(const Vector3 &vectorA, const Vector3 &vectorB)
{
    return Vector3((vectorA.y() * vectorB.z()) - (vectorA.z() * vectorB.y()),
                   (-(vectorA.x() * vectorB.z()) - (vectorA.z() * vectorB.x())),
                   (vectorA.x() * vectorB.y()) - (vectorA.y() * vectorB.x()));
}

Vector3 Vector3::makeUnitVector(const Vector3 &vector)
{
    return vector / vector.length();
}

float Vector3::dot(const Vector3 &vectorA, const Vector3 &vectorB)
{
    return vectorA.x() * vectorB.x() + vectorA.y() * vectorB.y() + vectorA.z() * vectorB.z();
}

Vector3 Vector3::operator-() const
{

    return Vector3(-std::get<0>(data), -std::get<1>(data), -std::get<2>(data));
}

Vector3::Vector3()
{}

Vector3::Vector3(const float x, const float y, const float z)
{
    std::get<0>(data) = x;
    std::get<1>(data) = y;
    std::get<2>(data) = z;
}

Vector3 operator +(const Vector3 &vector, const Vector3 &another)
{
     return Vector3(vector.x() + another.x(), vector.y() + another.y(), vector.z() + another.z());
}

Vector3 operator -(const Vector3 &vector, const Vector3 &another)
{
    return Vector3(vector.x() - another.x(), vector.y() - another.y(), vector.z() - another.z());
}

Vector3 operator *(const Vector3 &vector, const Vector3 &another)
{
    return Vector3(vector.x() * another.x(), vector.y() * another.y(), vector.z() * another.z());
}

Vector3 operator /(const Vector3 &vector, const Vector3 &another)
{
    return Vector3(vector.x() / another.x(), vector.y() / another.y(), vector.z() / another.z());
}

Vector3 operator /(const Vector3 &vector, float scalar)
{
     return Vector3(vector.x() / scalar, vector.y() / scalar, vector.z() / scalar);
}

Vector3 operator *(const Vector3 &vector, float scalar)
{
    return Vector3(vector.x() * scalar, vector.y() * scalar, vector.z() * scalar);
}

Vector3 operator *(float scalar, const Vector3 &vector)
{
    return Vector3(scalar * vector.x(), scalar * vector.y(), scalar * vector.z());
}
