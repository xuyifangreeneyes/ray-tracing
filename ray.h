#ifndef RAY_TRACING_RAY_H
#define RAY_TRACING_RAY_H

#include "vec3.h"

using Point3D = Vec3;

class Ray {
public:
  Ray() = default;
  Ray(const Point3D& origin, const Vec3& direction): origin(origin), direction(direction) {}

  const Point3D& Origin() const { return origin; }
  const Vec3& Direction() const { return direction; }

  Point3D At(double t) const {
    return origin + t * direction;
  }

private:
  Point3D origin;
  Vec3 direction;
};

#endif //RAY_TRACING_RAY_H
