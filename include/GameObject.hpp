#ifndef T2D_GAME_OBJECT_HPP_INCLUDED_
#define T2D_GAME_OBJECT_HPP_INCLUDED_


// Headers
#include "Header.hpp"

T2D_NS_BEGIN

// Abstract game object
class T2D_API GameObject {
public:
    GameObject() = default;
    GameObject(const GameObject&) = delete;
    GameObject(GameObject&&) = default;
    virtual ~GameObject() = default;

    GameObject &operator=(const GameObject&) = delete;
    GameObject &operator=(GameObject&&) = default;

    virtual void enable();          // Executed when enabled
    virtual void update();          // Executed when updated
    virtual void tick();            // Executed by tick counter
    virtual void disable();         // Execute when disabled

};

T2D_NS_END


#endif // T2D_GAME_OBJECT_HPP_INCLUDED_
