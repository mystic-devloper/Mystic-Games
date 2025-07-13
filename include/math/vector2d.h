#ifndef __MYSTIC_GAMES_MATH_VECTOR2D_H__
#define __MYSTIC_GAMES_MATH_VECTOR2D_H__

// Include Standard Library
#include <iostream>
#include <cmath>

// Include Custom Header
#include "modules/types.h"

namespace mystic {

template <typename T>
class vector2D {
public:
  // --- Constructor ---
  vector2D();
  vector2D(const T& x, const T& y);

  // --- Destructor ---
  ~vector2D() = default;

  // --- Getters ---
  T get_x() const;
  T get_y() const;

  // --- Setters ---
  void set(const T& x, const T& y);
  void set_x(const T& x);
  void set_y(const T& y);

private:
  T x;
  T y;
};

// Typedef for vector2D
// General vector2D
template <typename T>
using vec2 = vector2D<T>;

// Specialization
using vec2i = vector2D<i32>; // Integer Vector2D
using vec2l = vector2D<i64>; // Long Vector2D
using vec2f = vector2D<f32>; // Float Vector2D
using vec2d = vector2D<f64>; // Double Vector2D

} // namespace mystic

// Stream Overload
template <typename T>
std::ostream& operator<<(std::ostream& out_stream, const vector2D<T> vec);

#endif // __MYSTIC_GAMES_MATH_VECTOR2D_H__
