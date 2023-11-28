#ifndef APLICACION_H
#define APLICACION_H

#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Gameplay.h"
#include "Menu.h"
#include "MenuNivel.h"
#include "Transicion.h"

class Aplicacion
{
private:
    sf::RenderWindow _window;
    sf::RenderStates _state;
    sf::Event _event;
    sf::Music _musicmenu;
    sf::Music _musicjuego;


public:
    Aplicacion(sf::Vector2u resolucion);

    void transicionNivel(int nivel);

    ~Aplicacion();
};

#endif // APLICACION_H
