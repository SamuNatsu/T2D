#include "RigidBox.hpp"

T2D_NS_BEGIN

RigidBox::RigidBox(): m_VecW(1.0, 0.0), m_VecH(0.0, 1.0), m_Angle(0.0) {}

Vec2 RigidBox::getPosition() const {
    return m_Position;
}

void RigidBox::setPosition(double _x, double _y) {
    m_Position.setXY(_x, _y);
}

void RigidBox::setPosition(const Vec2& _o) {
    m_Position = _o;
}

void RigidBox::translateXY(double _x, double _y) {
    setPosition(m_Position.x + _x, m_Position.y + _y);
}

void RigidBox::translateXY(const Vec2& _o) {
    setPosition(m_Position + _o);
}

Vec2 RigidBox::getSize() const {
    return m_Size;
}

void RigidBox::setSize(double _w, double _h) {
    m_Size.setXY(_w, _h);
    m_HalfSize.setXY(_w * 0.5, _h * 0.5);
}

void RigidBox::setSize(const Vec2& _o) {
    m_Size = _o;
    m_HalfSize = _o * 0.5;
}

double RigidBox::getAngle() const {
    return m_Angle;
}

void RigidBox::setAngle(double _a) {
    if (fabs(_a) > T2D_2PI)
        _a = fmod(_a, T2D_2PI);
    if (_a < T2D_EPS)
        _a += T2D_2PI;
    m_VecW.setXY(cos(_a), sin(_a));
    m_VecH.setXY(-sin(_a), cos(_a));
    m_Angle = _a;
}

void RigidBox::translateA(double _a) {
    setAngle(m_Angle + _a);
}

bool RigidBox::collide(const RigidBox& _o) const {
    Vec2 T = _o.m_Position - m_Position;
    Vec2 axw = m_VecW * m_HalfSize.x;
    Vec2 ayh = m_VecH * m_HalfSize.y;
    Vec2 bxw = _o.m_VecW * _o.m_HalfSize.x;
    Vec2 byh = _o.m_VecH * _o.m_HalfSize.y;
    if (fabs(T * m_VecW) > fabs(bxw * m_VecW) + fabs(byh * m_VecW) + m_HalfSize.x)
        return false;
    if (fabs(T * m_VecH) > fabs(bxw * m_VecH) + fabs(byh * m_VecH) + m_HalfSize.y)
        return false;
    if (fabs(T * _o.m_VecW) > fabs(axw * _o.m_VecW) + fabs(ayh * _o.m_VecW) + _o.m_HalfSize.x)
        return false;
    if (fabs(T * _o.m_VecH) > fabs(axw * _o.m_VecH) + fabs(ayh * _o.m_VecH) + _o.m_HalfSize.y)
        return false;
    return true;
}

void RigidBox::debugDraw(sf::RenderWindow& win) const {
    sf::VertexArray arr(sf::Lines, 2);
    arr[0] = sf::Vertex((sf::Vector2f)m_Position, sf::Color::Yellow);
    arr[1] = sf::Vertex((sf::Vector2f)(m_Position + m_VecW * m_HalfSize.x), sf::Color::Yellow);
    sf::VertexArray rct(sf::LineStrip, 5);
    rct[0] = sf::Vertex((sf::Vector2f)(m_Position - m_VecW * m_HalfSize.x - m_VecH * m_HalfSize.y), sf::Color::Yellow);
    rct[1] = sf::Vertex((sf::Vector2f)(m_Position - m_VecW * m_HalfSize.x + m_VecH * m_HalfSize.y), sf::Color::Yellow);
    rct[2] = sf::Vertex((sf::Vector2f)(m_Position + m_VecW * m_HalfSize.x + m_VecH * m_HalfSize.y), sf::Color::Yellow);
    rct[3] = sf::Vertex((sf::Vector2f)(m_Position + m_VecW * m_HalfSize.x - m_VecH * m_HalfSize.y), sf::Color::Yellow);
    rct[4] = rct[0];
    win.draw(arr);
    win.draw(rct);
}

T2D_NS_END
