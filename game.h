#include<SFML/Graphics.hpp>
#include<array>
#include<vector>
#include<iostream>
#include"board.h"
#include"player.h"

class Game: public sf::Drawable {
    Board board;

    sf::Font font;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    public:
    Game(sf::Color bordCol1, sf::Color bordCol2){

    }
};