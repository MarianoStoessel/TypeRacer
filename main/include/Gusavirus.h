#pragma once
#ifndef GUSAVIRUS_H
#define GUSAVIRUS_H
#include <SFML/Graphics.hpp>

class Gusavirus: public sf::Drawable  // en progreso
{
    private:
        float _velocity=5;
        sf::Sprite _sprite;
        sf::Texture _texture;
        int x;
        int y;
    public:
        Gusavirus();
        void update();
        void motion();
        void draw(sf::RenderTarget& target, sf::RenderStates states)const override;

};

#endif // GUSAVIRUS_H

