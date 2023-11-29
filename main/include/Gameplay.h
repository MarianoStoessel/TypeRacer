#pragma once
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Leo.h"
#include "Gusavirus.h"
#include "Anonymous.h"
#include "Keyword.h"

class Gameplay
{
    private:
        sf::RenderWindow* _window;
        sf::RenderStates _state;
        sf::Event _evento;
        sf::Vector2u* _resolucion;

        sf::Music _musicjuego;

        int _nivel;
        bool _exitoPalabra;

    public:
        Gameplay();
        Gameplay(int nivel, sf::Vector2u* resolucion, sf::RenderWindow* window);

        int getLevelUp();
        bool getGameOver();

        void compararKeyWord(Keyword kw);

};

#endif // GAMEPLAY_H

