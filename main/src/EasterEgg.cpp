#include "EasterEgg.h"


EasterEgg::EasterEgg() //ctor
{
    _texture.loadFromFile("Imagenes/SpriteIconos.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({254, 4, 62, 75});//lo colocotrasparente
    _sprite.setPosition(1427, 810);
    StateEasterEgg _state = StateEasterEgg::Idle;
}
void EasterEgg::setPosicion(bool pos)
{
    _pos = pos;
}
bool EasterEgg::getPosicion()
{
    return _pos;
}
sf::Sprite EasterEgg::getSprite()
{
    return _sprite;
}
void EasterEgg::cmd()
{
    _state = StateEasterEgg::Idle;

    if(_pos == true)
    {
        _state = StateEasterEgg::View;
    }
}
void EasterEgg::update()
{
    switch(_state)
    {
    case StateEasterEgg::Idle:
        _sprite.setTextureRect({254, 83, 62, 75});//lo hago visible cambiando el sprite
        break;

    case StateEasterEgg::View:
        _frame+=0.5;
        _sprite.setPosition(1000,500);
        _sprite.setTextureRect({254, 83, 62, 75});//lo hago visible cambiando el sprite
        if(_frame>6){
            _state=StateEasterEgg::Idle;
            //se mutea el audio
        }
        //va audio
        break;
    }
}
void EasterEgg::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}
