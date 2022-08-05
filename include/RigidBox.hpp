#ifndef T2D_RIGID_BOX_HPP_INCLUDED_
#define T2D_RIGID_BOX_HPP_INCLUDED_


// Headers
#include "./Header.hpp"
#include "./Vec2.hpp"

T2D_NS_BEGIN

// Abstract rigid box
class T2D_API RigidBox {
public:
    RigidBox();
    RigidBox(const RigidBox&) = delete;
    RigidBox(RigidBox&&) = delete;
    virtual ~RigidBox() = default;

    RigidBox& operator=(const RigidBox&) = delete;
    RigidBox& operator=(RigidBox&) = delete;

    Vec2 getPosition() const;
    void setPosition(double, double);
    void setPosition(const Vec2&);
    void translateXY(double, double);
    void translateXY(const Vec2&);

    Vec2 getSize() const;
    void setSize(double, double);
    void setSize(const Vec2&);

    double getAngle() const;
    void setAngle(double);
    void translateA(double);

    bool collide(const RigidBox&) const;

    void debugDraw(sf::RenderWindow&) const;

protected:
    Vec2 m_Position, m_Size, m_HalfSize, m_VecW, m_VecH;
    double m_Angle;

};

T2D_NS_END


#endif // T2D_RIGID_BOX_HPP_INCLUDED_
