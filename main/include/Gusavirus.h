#pragma once
#ifndef GUSAVIRUS_H
#define GUSAVIRUS_H
#include <SFML/Graphics.hpp>
#include "Keyword.h"

enum class  GusavirusState{Vivo = 1, Mueriendo, Muerto};

class Gusavirus: public sf::Drawable  // en progreso
{
    private:
        float _velocity = 2;
        sf::Sprite _sprite;
        sf::Sprite _spritemuerte;
        sf::Texture _texture;
        int _color;
        int x;
        int y;
        float _frame;
        bool murio = false;
        bool muriendo = false;
        GusavirusState _state = GusavirusState::Vivo;
    public:
        //agregar sets y gets
        Gusavirus();
        //void mostrarpalabra(){palabra.Mostrar();}
        //cmd
        void cmd();
        bool setmurio();
        bool setmuriendo();
        bool getmurio();
        bool getmuriendo();
        int getposx();
        int getposy();
        void update();
        void motion();
        void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
        void SeeligeColor();
};

#endif // GUSAVIRUS_H

