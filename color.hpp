#ifndef COLOR_HPP
#define COLOR_HPP

#include <tuple>

class Color
{
private:
    std::tuple<float, float, float> data;
public:
    Color(const float r, const float g, const float b);
    float r() const;
    float g() const;
    float b() const;
};

Color operator +(const Color &color, const Color &another);
Color operator -(const Color &color, const Color &another);
Color operator *(const Color &color, const Color &another);
Color operator *(const Color &color, float scalar);
Color operator /(const Color &color, const Color &another);
Color operator /(const Color &color, float scalar);

#endif // COLOR_HPP
