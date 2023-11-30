#pragma once
#ifndef LEO_H
#define LEO_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum class LeoState {Idle, Move, kick, death};

class Leo: public sf::Drawable
{
private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Music _teclado;


    float _frame;
    float _frameGolpe;
    float _frameMuerto;

    bool _golpe = false;
    bool _muriendo = false;

    LeoState _state;

public:
    Leo();

    //Sets
    void setGolpe(bool golpe);
    void setMuriendo(bool muriendo);
    //Gets
    bool getGolpe();
    bool getMuriendo();

    void cmd();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

#endif // LEO_H

