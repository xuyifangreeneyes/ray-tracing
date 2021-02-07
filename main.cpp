#include <iostream>
#include "vec3.h"
#include "color.h"
#include "ray.h"

Color rayColor(const Ray& ray) {
  Vec3 unit_direction = UnitVec(ray.Direction());
  double ratio = 0.5 * (unit_direction.Y() + 1.0);
  return (1.0 - ratio) * Color(1.0, 1.0, 1.0) + ratio * Color(0.5, 0.7, 1.0);
}

int main() {
  const double aspect_ratio = 16.0 / 9.0;
  const int image_width = 256;
  const int image_height = 256;

  double view_height = 2.0;
  double view_weight = aspect_ratio * view_height;
  double focal_length = 1.0;

  Point3D origin = Point3D(0, 0, 0);
  Vec3 horizontal = Vec3(view_weight, 0, 0);
  Vec3 vertical = Vec3(0, view_height, 0);
  Point3D lower_left_corner = origin - horizontal / 2 - vertical / 2 - Vec3(0, 0, focal_length);

  std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
  for (int j = image_height - 1; j >= 0; --j) {
    std::cerr << "\rScanlines remaining: " << j << " " << std::flush;
    for (int i = 0; i < image_width; ++i) {
      double u = double(i) / (image_width - 1);
      double v = double(j) / (image_height - 1);
      Ray ray(origin, lower_left_corner + u * horizontal + v * vertical - origin);
      Color color = rayColor(ray);
      writeColor(std::cout, color);
    }
  }
  std::cerr << "\nDone.\n";
  return 0;
}
