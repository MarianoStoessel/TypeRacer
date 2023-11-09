#pragma once
#ifndef LEO_H
#define LEO_H
#include <SFML/Graphics.hpp>

enum class LeoState{Idle = 0, Move};

class Leo: public sf::Drawable
{
    private:
        int _vida;

        sf::Sprite _sprite;
        sf::Texture _texture;

        float _frame;
        LeoState _state;

    public:
        Leo();

        void cmd();
        void update();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

#endif // LEO_H

