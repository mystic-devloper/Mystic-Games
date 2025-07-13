// Definition of "/include/math/vector2d.h"
#include "math/vector2d.h"

// Include Standard Library
#include <iostream>
#include <cmath>

namespace mystic {

template <typename T>
vector2D<T>::vector2D() :
  x(0.0f),
  y(0.0f) {

}

template <typename T>
vector2D<T>::vector2D(const T& p_x = 0.0f, const T& p_y = 0.0f) :
  x(p_x),
  y(p_y) {

}

template <typename T>
T vector2D<T>::get_x() const {
  return x;
}

template <typename T>
T vector2D<T>::get_y() const {
  return y;
}

template <typename T>
void vector2D<T>::set(const T& p_x, const T& p_y) {
  x = p_x;
  y = p_y;
}

template <typename T>
void vector2D<T>::set_x(const T& p_x) {
  x = p_x;
}

template <typename T>
void vector2D<T>::set_y(const T& p_y) {
  y = p_y;
}

} // namespace mystic
