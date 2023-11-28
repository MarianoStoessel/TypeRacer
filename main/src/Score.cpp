#include "Score.h"

using namespace std;

Score::Score() //ctor
{
    _score = 0;
    string strScore = std::to_string(_score);

    if(!_font.loadFromFile("Fuentes/Retro Gaming.ttf"))
    {
        cout <<"No existe la fuente";
    }
    //Score
    _scoreNiv.setFont(_font);
    _scoreNiv.setFillColor(sf::Color::Black);
    _scoreNiv.setString(strScore);
    _scoreNiv.setCharacterSize(35);
    _scoreNiv.setPosition(1263,726);
}
int Score::getScore()
{
    return _score;
}
void Score::update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //Sacar lo que tiene y Añadir cuando se mata a un virus
    {
        _score += 100;
        string strScore = std::to_string(_score);
        //Score
        _scoreNiv.setFont(_font);
        _scoreNiv.setFillColor(sf::Color::Black);
        _scoreNiv.setString(strScore);
        _scoreNiv.setCharacterSize(35);
        _scoreNiv.setPosition(1263,726);
    }
}
void Score::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_scoreNiv, states);
}
Score::~Score() //dtor
{

}
