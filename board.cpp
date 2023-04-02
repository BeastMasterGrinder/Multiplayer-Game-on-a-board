#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>

using namespace sf;

class Board : public sf::Drawable{

    std::array<RectangleShape, 400> m_boardSquares;
    
    // Draw class on SFML Window
    virtual void draw(RenderTarget& target, RenderStates states) const{
        for(int i=0;i<400;i++){
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
    //assuming the board is 15*15
    void load(Color col1 = Color (122, 235, 52), Color col2 = Color (138, 51, 8)){
        float boxSize = 400.f/15.f;
        //20 is the number of boxes and 400/15 is the size of the box

        for(int i=0; i<20;i++){
            bool tmpColor = ((i % 2)==0)?true:false;

            for(int j=0; j<20;j++){
                
                m_boardSquares[j + (i * 20)].setPosition(sf::Vector2f( j*boxSize , i*boxSize ));
                m_boardSquares[j + (i * 20)].setSize(sf::Vector2f(boxSize, boxSize));
                m_boardSquares[j + (i * 20)].setFillColor(tmpColor ? col1 : col2);
                
                tmpColor = !tmpColor;
            }
        }
    }



};

