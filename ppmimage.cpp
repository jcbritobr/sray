#include <iostream>
#include "ppmimage.hpp"

int PPMImage::getHeigth() const
{
    return heigth;
}

int PPMImage::getWidth() const
{
    return width;
}

std::vector<Color> PPMImage::getData() const
{
    return data;
}

PPMImage::PPMImage(int width, int heigth):width(width), heigth(heigth)
{
    for (int i = 0; i < width * heigth; ++i) {
        data.push_back(Color(0.0f, 0.0f, 0.0f));
    }
}

std::ostream &operator <<(std::ostream &stream, const PPMImage &image)
{
    stream << "P3\n" << image.getWidth() << " " << image.getHeigth() << "\n255\n";

    for (auto color: image.getData()) {
        stream << color.r() << " " << color.g() << " " << color.b() << std::endl;
    }

    return stream;
}

std::istream &operator >>(std::istream &stream, PPMImage &image)
{

}
