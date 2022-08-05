#ifndef T2D_HEADER_HPP_INCLUDED_
#define T2D_HEADER_HPP_INCLUDED_


// Headers
#include <bits/stdc++.h>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Macros
#define T2D_NS_BEGIN namespace t2d {
#define T2D_NS_END }

#ifdef T2D_STATIC
    #define T2D_API
#else
    #ifdef T2D_EXPORT
        #define T2D_API __declspec(dllexport)
    #else
        #define T2D_API __declspec(dllimport)
    #endif // T2D_EXPORT
#endif // T2D_STATIC

#define T2D_EPS 1e-8
#define T2D_PI_2 1.57079632679489661923
#define T2D_PI 3.14159265358979323846
#define T2D_2PI 6.28318530717958647692

#define feq(a, b) (fabs((a) - (b)) < T2D_EPS)
#define flq(a, b) (feq((a), (b)) || (a) < (b))


#endif // T2D_HEADER_HPP_INCLUDED_
