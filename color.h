#ifndef RAY_TRACING_COLOR_H
#define RAY_TRACING_COLOR_H

#include <iostream>
#include "vec3.h"

inline constexpr double MaxColorValue = 255.999;

using Color = Vec3;

void writeColor(std::ostream& os, const Color& color);

#endif //RAY_TRACING_COLOR_H
