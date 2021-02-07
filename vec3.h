#ifndef RAY_TRACING_VEC3_H
#define RAY_TRACING_VEC3_H

#include <cmath>
#include <iostream>

class Vec3 {
public:
  Vec3(): v{0, 0, 0} {}
  Vec3(double x, double y, double z): v{x, y, z} {}

  double X() const { return v[0]; }
  double Y() const { return v[1]; }
  double Z() const { return v[2]; }

  Vec3 operator-() const { return {-v[0], -v[1], -v[2]}; }
  double operator[](int idx) const { return v[idx]; }
  double& operator[](int idx) { return v[idx]; }

  Vec3& operator+=(const Vec3& vec) {
    v[0] += vec.v[0];
    v[1] += vec.v[1];
    v[2] += vec.v[2];
    return *this;
  }

  Vec3& operator*=(const Vec3& vec) {
    v[0] *= vec.v[0];
    v[1] *= vec.v[1];
    v[2] *= vec.v[2];
    return *this;
  }

  Vec3& operator*=(double scalar) {
    v[0] *= scalar;
    v[1] *= scalar;
    v[2] *= scalar;
    return *this;
  }

  Vec3& operator/=(double scalar) {
    return operator*=(1 / scalar);
  }

  double Norm2() const { return v[0] * v[0] + v[1] * v[1] + v[2] * v[2]; }
  double Length() const { return std::sqrt(Norm2()); }

private:
  double v[3];
};

inline std::ostream& operator<<(std::ostream& os, const Vec3& vec) {
  return os << vec[0] << " " << vec[1] << " " << vec[2];
}

inline Vec3 operator+(const Vec3& u, const Vec3& v) {
  return { u[0] + v[0], u[1] + v[1], u[2] + v[2] };
}

inline Vec3 operator-(const Vec3& u, const Vec3& v) {
  return { u[0] - v[0], u[1] - v[1], u[2] - v[2] };
}

inline Vec3 operator*(const Vec3& u, const Vec3& v) {
  return { u[0] * v[0], u[1] * v[1], u[2] * v[2] };
}

inline Vec3 operator*(const Vec3& vec, double scalar) {
  return { vec[0] * scalar, vec[1] * scalar, vec[2] * scalar };
}

inline Vec3 operator*(double scalar, const Vec3& vec) {
  return vec * scalar;
}

inline Vec3 operator/(const Vec3& vec, double scalar) {
  return operator*(vec, 1 / scalar);
}

inline double dot(const Vec3& u, const Vec3& v) {
  return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
}

inline Vec3 cross(const Vec3& u, const Vec3& v) {
  return {u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2], u[0] * v[1] - u[1] * v[0] };
}

inline Vec3 UnitVec(const Vec3& vec) {
  return vec / vec.Length();
}

#endif //RAY_TRACING_VEC3_H
