#include "color.hpp"

Color::Color(const float r, const float g, const float b)
{
    std::get<0>(data) = r;
    std::get<1>(data) = g;
    std::get<2>(data) = b;
}

float Color::r() const
{
    return std::get<0>(data);
}

float Color::g() const
{
    return std::get<1>(data);
}

float Color::b() const
{
    return std::get<2>(data);
}

Color operator +(const Color &color, const Color &another)
{
    return Color(color.r() + another.r(), color.g() + another.g(), color.b() + another.b());
}

Color operator -(const Color &color, const Color &another)
{
    return Color(color.r() - another.r(), color.g() - another.g(), color.b() - another.b());
}

Color operator *(const Color &color, const Color &another)
{
    return Color(color.r() * another.r(), color.g() * another.g(), color.b() * another.b());
}

Color operator *(const Color &color, float scalar)
{
    return Color(color.r() * scalar, color.g() * scalar, color.b() * scalar);
}

Color operator /(const Color &color, const Color &another)
{
    return Color(color.r() / another.r(), color.g() / another.g(), color.b() / another.b());
}

Color operator /(const Color &color, float scalar)
{
    return Color(color.r() / scalar, color.g() / scalar, color.b() / scalar);
}
