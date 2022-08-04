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
        #define T2D_API __desclspec(dllimport)
    #endif // T2D_EXPORT
#endif // T2D_EMBED

#define T2D_EPS 1e-8
#define T2D_PI 3.14159265358979323846


#endif // T2D_HEADER_HPP_INCLUDED_
