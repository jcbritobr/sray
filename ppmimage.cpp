#include "ppmimage.hpp"

//TODO:: write tests -- this code compiles :-)

constexpr auto P3MARKER = "P3";
constexpr auto PPMNL = '\n';
constexpr auto PPMSPACE = ' ';
constexpr auto PPMMAGIC = 255;

std::ostream &operator <<(std::ostream &stream, const PPMImage &image)
{
    stream << P3MARKER << PPMNL << image.width << PPMSPACE << image.height << PPMNL << PPMMAGIC << PPMNL;
    if( !stream ) return stream;

    for ( const auto& color: image.data ) {
        stream << color.r() << PPMSPACE << color.g() << PPMSPACE << color.b() << PPMNL;
        if( !stream ) return stream;
    }

    return stream;
}

std::istream &operator >>(std::istream &stream, PPMImage &image)
{
    if( !stream ) return stream;
    std::string p3;
    stream >> p3;
    if( !stream ) return stream;
    if( p3 != P3MARKER ) {
        stream.setstate(std::ios_base::failbit);
        return stream;
    }
    size_t width, height, magic;
    stream >> width >> height >> magic;
    if( !stream ) return stream;
    if( magic != PPMMAGIC ) {
        stream.setstate(std::ios_base::failbit);
        return stream;
    }
    std::vector<Color> data;
    data.reserve(width*height); // avoid reallocations and copies

    for( auto count = width*height; count --> 0; ) {
        float r, g, b;
        stream >> r >> g >> b;
        if( !stream ) return stream;
        data.emplace_back(r, g, b);
    }

    image = PPMImage { width, height, data };

    return stream;
}
