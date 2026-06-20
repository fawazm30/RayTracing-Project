#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <iostream>

using color = vec3;

void write_color(std::ostream& out, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Translate the [0, 1] range of each color component to [0, 255]
    int rybyte = int(255.999 * r);
    int gybyte = int(255.999 * g);
    int bybyte = int(255.999 * b);

    // Write the translated color components to the output stream
    out << rybyte << ' ' << gybyte << ' ' << bybyte << '\n';
}

#endif