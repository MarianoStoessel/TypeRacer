#include "Anonymous.h"

Anonymous::Anonymous() //ctor
{
    _frame = 0;
    _frameGolpe = 0;
    _frameMuerto = 0;

    _texture.loadFromFile("Imagenes/SpriteAnonymous.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({0, 0, 300, 390});
    _sprite.setPosition(563, 61);
    AnonymousState _state = AnonymousState::Idle;
}
void Anonymous::setGolpe(bool golpe)
{
    _golpe = golpe;
}
void Anonymous::setMuriendo(bool muriendo)
{
    _muriendo = muriendo;
}
bool Anonymous::getGolpe()
{
    return _golpe;
}
bool Anonymous::getMuriendo()
{
    return _muriendo;
}
void Anonymous::Anonymous::cmd()
{
    _state = AnonymousState::Idle;

    if(_golpe == true && _muriendo == false)
    {
        _state = AnonymousState::kick;
    }
    if(_muriendo == true)
    {
        _state = AnonymousState::death;
    }
}
void Anonymous::update()
{
    switch(_state)
    {
    case AnonymousState::Idle:
        _sprite.setTextureRect({0, 0, 300, 390});
        break;
    case AnonymousState::Move:
        _frame += 0.1;

        if(_frame >= 8)
        {
            _frame = 0;
        }
        _sprite.setTextureRect({300 + int(_frame) * 300, 0, 300, 390});
        break;


    case AnonymousState::kick:
        break;
    case AnonymousState::death:
    {
        _frameMuerto += 0.1;

        if(_frameMuerto <= 11)
        {
            _sprite.setTextureRect({int(_frameMuerto) * 300, 780, 300, 390});
        }
    }
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
