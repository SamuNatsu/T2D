#ifndef T2D_VEC2_HPP_INCLUDED_
#define T2D_VEC2_HPP_INCLUDED_


// Headers
#include "./Header.hpp"

T2D_NS_BEGIN

// 2D vector
class T2D_API Vec2 {
public:
    double x, y;

    Vec2(double = 0.0, double = 0.0);
    Vec2(const Vec2&) = default;
    Vec2(Vec2&&) = default;
    virtual ~Vec2() = default;

    Vec2& operator=(const Vec2&) = default;
    Vec2& operator=(Vec2&&) = default;

    Vec2 operator+(const Vec2&) const;
    Vec2& operator+=(const Vec2&);

    Vec2 operator-(const Vec2&) const;
    Vec2& operator-=(const Vec2&);

    Vec2 operator-() const;

    Vec2 operator*(double) const;
    Vec2& operator*=(double);

    double operator*(const Vec2&) const;

    Vec2 operator/(double) const;
    Vec2& operator/=(double);

    double operator^(const Vec2&) const;

    operator sf::Vector2f() const;

    Vec2& setXY(double, double);

    double getLength() const;

    double getAngle() const;
    double getAngle(const Vec2&) const;

    Vec2 getNormal() const;

    Vec2 getNormalized() const;
    Vec2& normalize();

    Vec2 getRotated(double) const;
    Vec2& rotate(double);

    Vec2 getScaled(double, double) const;
    Vec2 getScaled(const Vec2&) const;
    Vec2& scale(double, double);
    Vec2& scale(const Vec2&);

    Vec2 getProjection(const Vec2&) const;

};

T2D_API Vec2 operator*(double, const Vec2&);

T2D_NS_END


#endif // T2D_VEC2_HPP_INCLUDED_
