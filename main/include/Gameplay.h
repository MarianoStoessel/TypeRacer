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
        int _cantE;
        int _enemigosActivos;
        int _score;
        int _nivel;
        bool _exitoPalabra;
        bool _gameover=false;
        bool _levelUp=false;

    public:
        Gameplay();
        Gameplay(int nivel, sf::Vector2u* resolucion, sf::RenderWindow* window);

        void Renderizar();
        void logicajuego();
        void procesar_eventos();
        void gameLoop();

        void setGameOver(bool go){_gameover=go;}

        int getcantEnemigos();
        int getLevelUp(){return _nivel;}
        bool getGameOver(){return _gameover;}


        void compararKeyWord(Keyword kw);
};

#endif // GAMEPLAY_H

