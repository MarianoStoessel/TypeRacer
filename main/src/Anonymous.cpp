#include "Anonymous.h"

Anonymous::Anonymous() //ctor
{
    _frame = 0;
    _texture.loadFromFile("Imagenes/SpriteAnonymous.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({0, 0, 300, 390});
    _sprite.setPosition(563, 61);
    AnonymousState _state = AnonymousState::Idle;
}
void Anonymous::cmd()
{
    _state = AnonymousState::Idle;

    AnonymousState::Move;

    /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        _state = AnonymousState::Move;
    }*/
}
void Anonymous::update()
{
    switch(_state)
    {
    case AnonymousState::Idle:
        _sprite.setTextureRect({0, 0, 300, 390});
        break;
    case AnonymousState::Move:
        _frame += 0.10;

        if(_frame >= 8)
        {
            _frame = 0;
        }
        _sprite.setTextureRect({300 + int(_frame) * 300, 0, 300, 390});
        break;
    default:
        break;
    }
}
void Anonymous::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}
Anonymous::~Anonymous() //dtor
{

}
