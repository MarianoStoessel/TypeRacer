#pragma once
#ifndef ANONYMOUS_H
#define ANONYMOUS_H

#include <SFML/Graphics.hpp>

enum class AnonymousState {Idle = 0, Move};

class Anonymous: public sf::Drawable // en progreso
{
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

    float _frame;
    AnonymousState _state;

public:
    Anonymous();

    void cmd();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    ~Anonymous();
};

#endif // ANONYMOUS_H
