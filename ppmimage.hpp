#ifndef PPMIMAGE_HPP
#define PPMIMAGE_HPP

#include <fstream>
#include <vector>
#include "color.hpp"

class PPMImage
{
private:
    std::vector<Color> data;
    int width;
    int heigth;
public:
    PPMImage(int width, int heigth);
    int getHeigth() const;
    int getWidth() const;
    std::vector<Color> getData() const;
};

std::ostream& operator <<(std::ostream &stream, PPMImage const &image);
std::istream& operator >>(std::istream &stream, PPMImage &image);

#endif // PPMIMAGE_HPP
