#include "Leo.h"

Leo::Leo() //ctor
{
    _frame = 0;
    _texture.loadFromFile("Imagenes/SpriteLeo.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({10, 10, 144, 120});
    _sprite.setPosition(30, 330);
    LeoState _state = LeoState::Idle;
}
void Leo::cmd() //caja de estados - de aca pasa al update
{
    _state = LeoState::Idle;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::I))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::J))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::L))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::N))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::O))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::T))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::U))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::V))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
    {
        _state = LeoState::Move;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        _state = LeoState::Move;
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
    default:
        break;
    }
}
void Leo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}
