#pragma once
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <iostream>
#include <conio.h>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Leo.h"
#include "Gusavirus.h"
#include "Anonymous.h"
#include "Keyword.h"
#include "Score.h"
#include "Nivel.h"
#include "Vida.h"

class Gameplay
{
    private:
        sf::RenderWindow* _window;
        sf::RenderStates _state;
        sf::Event _evento;
        sf::Vector2u* _resolucion;

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

