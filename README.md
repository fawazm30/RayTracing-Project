# Ray Tracer

A CPU path tracer built from scratch in C++17, following [_Ray Tracing in One Weekend_](https://raytracing.github.io/books/RayTracingInOneWeekend.html) by Peter Shirley. Built to deepen my understanding of 3D rendering fundamentals and low-level C++ through hands-on implementation — concepts directly applicable to game engine and graphics programming work.

## Final Render

<img width="1000" height="562" alt="image" src="https://github.com/user-attachments/assets/0f00e719-39f2-4cd7-9474-0754e09208a9" />

---

## Features

- PPM image output
- Vec3 math library (dot product, cross product, unit vectors)
- Lambertian (diffuse), metal, and dielectric (glass) materials
- Ray-sphere intersection with surface normal computation
- Antialiasing via multi-sample averaging
- Gamma correction (linear to gamma-2 transform)
- Recursive ray bouncing with configurable depth limit
- Positionable camera with adjustable field of view and depth of field
- `hittable` abstraction — extensible to any geometry, not just spheres

---

## Math Topics

- Vector math (dot product, cross product, vector normalization)
- Parametric ray equations
- Ray-sphere intersection via quadratic formula
- Surface normal computation
- Lambertian reflectance model
- Specular reflection vectors
- Snell's law and Schlick's approximation (dielectric/glass refraction)
- Monte Carlo integration (antialiasing via random sampling)
- Gamma correction (linear to gamma-2 transform)
- Depth of field via thin lens approximation

---

## Challenges

The most challenging aspect was bridging the gap between the mathematical derivations (Snell's law, Schlick's approximation, the thin lens model) and their C++ implementations, understanding not just *how* to implement each formula but *why* it produces the correct visual result.

On the implementation side, the most instructive bugs were subtle C++ issues: a single `#ifdef` vs `#ifndef` typo in an include guard that silently prevented an entire header from being parsed, and accidentally writing progress output to `std::cout` instead of `std::clog`, which interleaved diagnostic text directly into the PPM pixel data stream and corrupted the image output.

---

## Build

**Requirements:** C++17 compiler (Clang or GCC), CMake 3.10+

```bash
git clone https://github.com/fawazm30/RayTracing-Project.git
cd RayTracing-Project

cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

## Run

```bash
build/raytracer > image.ppm
```

Opening the output:

```bash
# macOS
open image.ppm

# Linux
xdg-open image.ppm

# Windows — PPM is not natively supported; use IrfanView (https://www.irfanview.com/)
# or convert to PNG first using ImageMagick:
magick image.ppm image.png
start image.png
```

Re-run `cmake -B build` only if `CMakeLists.txt` changes (e.g. adding new source files). For code-only changes, `cmake --build build` is sufficient.

---

## Project Structure

```
src/
├── main.cc           # Scene setup and entry point
├── camera.h          # Camera, ray generation, render loop
├── ray.h             # Ray class
├── vec3.h            # 3D vector math
├── color.h           # Color utilities and gamma correction
├── hittable.h        # Abstract hittable interface
├── hittable_list.h   # Scene container
├── sphere.h          # Sphere geometry
├── material.h        # Lambertian, metal, dielectric materials
├── interval.h        # Numeric interval utility
└── rtweekend.h       # Common includes and constants
```

---

## Reference

Peter Shirley, Trevor David Black, Steve Hollasch — [_Ray Tracing in One Weekend_](https://raytracing.github.io/books/RayTracingInOneWeekend.html)
