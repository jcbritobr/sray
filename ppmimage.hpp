#ifndef PPMIMAGE_HPP
#define PPMIMAGE_HPP

#include <fstream>
#include <vector>
#include "color.hpp"

// PPMImage is semi-immutable: one can manipulate in-place the individual pixels but you can't
// resize the image. The array of pixels will be moved whenever possible.

struct PPMImage {
    const size_t width;
    const size_t height;
    std::vector<Color> data;
    PPMImage(size_t width_, size_t height_) : width {width_}, height {height_}, data {width*height, Color{.0f, .0f, .0f}} {}
    PPMImage(size_t width_, size_t height_, std::vector<Color> const& data_) : width {width_}, height {height_}, data {data_} {}
    PPMImage(size_t width_, size_t height_, std::vector<Color> && data_) : width {width_}, height {height_}, data {std::move(data_)} {}
    PPMImage& operator=(PPMImage const& image) { new(this) PPMImage { image.width, image.height, image.data }; return *this; }
    PPMImage& operator=(PPMImage && image) { new(this) PPMImage { image.width, image.height, std::move(image.data) }; return *this; }
};

std::ostream& operator <<(std::ostream &stream, PPMImage const &image);
std::istream& operator >>(std::istream &stream, PPMImage &image);

#endif // PPMIMAGE_HPP
