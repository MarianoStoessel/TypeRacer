#ifndef APLICACION_H
#define APLICACION_H

#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Menu.h"
#include "MenuNivel.h"
#include "Leo.h"
#include "Gusavirus.h"
#include "Anonymous.h"

class Aplicacion
{
private:
    sf::RenderWindow _window;
    sf::RenderStates _state;
    sf::Event _event;

public:
    Aplicacion(sf::Vector2u resolucion);

    ~Aplicacion();
};

#endif // APLICACION_H
