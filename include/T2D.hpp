#ifndef T2D_HPP_INCLUDED_
#define T2D_HPP_INCLUDED_


// Module includes
#include "./GameObject.hpp"
#include "./RigidBox.hpp"
#include "./TriggerBox.hpp"
#include "./Vec2.hpp"

// Version macros
#define T2D_MAJOR_VERSION 0
#define T2D_MINOR_VERSION 1
#define T2D_PATCH_VERSION 0

#define T2D_VERSION_CONVERT(num) #num
#define T2D_VERSION_STRINGFY(num) T2D_VERSION_CONVERT(num)
#define T2D_VERSION (T2D_VERSION_STRINGFY(T2D_MAJOR_VERSION) "." T2D_VERSION_STRINGFY(T2D_MINOR_VERSION) "." T2D_VERSION_STRINGFY(T2D_PATCH_VERSION))


#endif // T2D_HPP_INCLUDED_
