#ifndef COLOR_H
#define COLOR_H

#include "interval.h"
#include "vec3.h"

using color = vec3;


// Helper function to apply a linear to gamma transform for gamma 2. 
// This is used to convert the linear color values computed by the ray tracer into a more visually pleasing form for display.
inline double linear_to_gamma(double linear_component)
{
    if (linear_component > 0)
        return std::sqrt(linear_component);

    return 0;
}

// Helper function to write a color to an output stream. 
// The color is first transformed from linear to gamma space, then clamped to the [0, 0.999] range, and finally scaled to the [0, 255] range for output as RGB values.
void write_color(std::ostream& out, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Apply a linear to gamma transform for gamma 2
    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);

    // Translate the [0, 1] range of each color component to [0, 255]
    static const interval intensity(0.000, 0.999);
    int rbyte = int(256 * intensity.clamp(r));
    int gbyte = int(256 * intensity.clamp(g));
    int bbyte = int(256 * intensity.clamp(b));

    // Write the translated color components to the output stream
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif