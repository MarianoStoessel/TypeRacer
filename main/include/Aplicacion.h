#ifndef APLICACION_H
#define APLICACION_H

#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Menu.h"

class Aplicacion
{
private:
    sf::RenderWindow _window;
    sf::RenderStates _state;
    sf::Event _event;

    Menu _menu;

public:
    Aplicacion(sf::Vector2u resolucion);

    ~Aplicacion();
};

#endif // APLICACION_H
