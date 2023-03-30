
#define _BOARD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>

using namespace sf;

class Board : public Drawable{

    std::array<RectangleShape, 64> m_boardSquares;
    
    // Draw class on SFML Window
    virtual void draw(RenderTarget& target, RenderStates states) const{
        for(int i=0;i<64;i++){
            target.draw(m_boardSquares[i]);
        }
    }

public:
    //if no color is added then they have pre defined colors
    Board(Color col1 = Color (122, 235, 52), Color col2 = Color (138, 51, 8)){
        load(col1, col2);
    }
    
    //if no color is added then they have pre defined colors
    // Member function that sets Board stuff, can choose square colors in parameters
    void load(Color col1 = Color (122, 235, 52), Color col2 = Color (138, 51, 8)){
        for(int i=0; i<8;i++){

            bool tmpColor = ((i % 2)==0)?true:false;

            for(int j=0; j<8;j++){

                m_boardSquares[j + (i * 8)].setPosition(sf::Vector2f( j*64.f , i*64.f ));
                m_boardSquares[j + (i * 8)].setSize(sf::Vector2f(64.f, 64.f));
                m_boardSquares[j + (i * 8)].setFillColor(tmpColor ? col1 : col2);
                
                tmpColor = !tmpColor;
            }
        }
    }



};

