#include "Vec2.hpp"

T2D_NS_BEGIN

Vec2::Vec2(double _x, double _y): x(_x), y(_y) {}

Vec2 Vec2::operator+(const Vec2& _o) const {
    return Vec2(x + _o.x, y + _o.y);
}

Vec2& Vec2::operator+=(const Vec2& _o) {
    x += _o.x;
    y += _o.y;
    return *this;
}

Vec2 Vec2::operator-(const Vec2&_o) const {
    return Vec2(x - _o.x, y  - _o.y);
}

Vec2& Vec2::operator-=(const Vec2& _o) {
    x -= _o.x;
    y -= _o.y;
    return *this;
}

Vec2 Vec2::operator-() const {
    return Vec2(-x, -y);
}

Vec2 Vec2::operator*(double _a) const {
    return Vec2(x * _a, y * _a);
}

Vec2& Vec2::operator*=(double _a) {
    x *= _a;
    y *= _a;
    return *this;
}

double Vec2::operator*(const Vec2& _o) const {
    return x * _o.x + y * _o.y;
}

Vec2 Vec2::operator/(double _a) const {
    return Vec2(x / _a, y / _a);
}

Vec2& Vec2::operator/=(double _a) {
    x /= _a;
    y /= _a;
    return *this;
}

double Vec2::operator^(const Vec2& _o) const {
    return x * _o.y - y * _o.x;
}

Vec2::operator sf::Vector2f() const {
    return sf::Vector2f(x, y);
}

double Vec2::getLength() const {
    return hypot(x, y);
}

double Vec2::getAngle() const {
    return atan2(y, x);
}

double Vec2::getAngle(const Vec2& _o) const {
    return asin(*this ^ _o);
}

Vec2 Vec2::getNormal() const {
    return getNormalized().rotate(T2D_PI);
}

Vec2 Vec2::getNormalized() const {
    double len = getLength();
    return len < T2D_EPS ? *this : *this / len;
}

Vec2& Vec2::normalize() {
    return *this = getNormalized();
}

Vec2 Vec2::getRotated(double _a) const {
    return Vec2(x * cos(_a) - y * sin(_a), x * sin(_a) + y * cos(_a));
}

Vec2& Vec2::rotate(double _a) {
    return *this = getRotated(_a);
}

Vec2 Vec2::getScaled(double _a, double _b) const {
    return Vec2(x * _a, y * _b);
}

Vec2 Vec2::getScaled(const Vec2& _o) const {
    return Vec2(x * _o.x, y * _o.y);
}

Vec2& Vec2::scale(double _a, double _b) {
    x *= _a;
    y *= _b;
    return *this;
}

Vec2& Vec2::scale(const Vec2& _o) {
    x *= _o.x;
    y *= _o.y;
    return *this;
}

Vec2 Vec2::getProjection(const Vec2& _o) const {
    return _o.getNormalized() * (*this * _o);
}

T2D_API Vec2 operator*(double _a, const Vec2& _o) {
    return Vec2(_o.x * _a, _o.y * _a);
}

T2D_NS_END
