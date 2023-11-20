#pragma once
#ifndef GUSAVIRUS_H
#define GUSAVIRUS_H
#include <SFML/Graphics.hpp>
#include "Keyword.h"
class Gusavirus: public sf::Drawable  // en progreso
{
    private:
        float _velocity = 2;
        sf::Sprite _sprite;
        sf::Texture _texture;
        int _color;
        int x;
        int y;
        float _frame;
    public:
        //agregar sets y gets
        Gusavirus();
        //void mostrarpalabra(){palabra.Mostrar();}
        int getposx();
        int getposy();
        void update();
        void motion();
        void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
        void SeeligeColor();
};

#endif // GUSAVIRUS_H

