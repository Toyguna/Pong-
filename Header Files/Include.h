#ifndef INCLUDE_H
#define INCLUDE_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

// funcs
bool int_range(int value, int min, int max);
bool float_range(float value, float min, float max);

#endif