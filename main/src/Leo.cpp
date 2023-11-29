#include "Leo.h"

Leo::Leo() //ctor
{
    _frame = 0;
    _frameGolpe = 0;
    _frameMuerto = 0;

    _texture.loadFromFile("Imagenes/SpriteLeo.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({10, 10, 144, 120});
    _sprite.setPosition(30, 330);
    LeoState _state = LeoState::Idle;
}
//Sets
void Leo::setGolpe(bool golpe)
{
    _golpe = golpe;
}
void Leo::setMuriendo(bool muriendo)
{
    _muriendo = muriendo;
}
//Gets
bool Leo::getGolpe()
{
    return _golpe;
}
bool Leo::getMuriendo()
{
    return _muriendo;
}
//Cmd
void Leo::cmd()
{
    _state = LeoState::Idle;

    for (int i = 0; i < sf::Keyboard::KeyCount; i++)
    {
        if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i)))
        {
            _state = LeoState::Move;
            break;
        }
    }
    if(_golpe == true && _muriendo == false)
    {
        _state = LeoState::kick;
    }
    if(_muriendo == true)
    {
        _state = LeoState::death;
    }
}
void Leo::update() //comprueba estado y ejecuta el movimiento si es asi
{
    switch(_state)
    {
    case LeoState::Idle:
        _sprite.setTextureRect({10, 10, 144, 120});
        break;
    case LeoState::Move:
        _frame += 0.18;

        if(_frame >= 4)
        {
            _frame = 0;
        }
        _sprite.setTextureRect({10 + int(_frame) * 154, 10, 144, 120});
        break;
    case LeoState::kick:
        _frameGolpe += 0.18;

        if(_frameGolpe >= 2)
        {
            _frameGolpe = 0;
        }
        _sprite.setTextureRect({626 + int(_frameGolpe) * 154, 10, 144, 120});
        break;
    case LeoState::death:
    {
        _frameMuerto += 0.05;

        if(_frameMuerto < 6)
        {
            _sprite.setTextureRect({10+ int(_frameMuerto) * 154, 142, 144, 120});
        }
    }
    break;
    }
}
void Leo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}
