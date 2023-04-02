#include<SFML/Graphics.hpp>
#include<array>
#include<vector>
#include<iostream>
#include"board.h"
#include"players.cpp"

class Game: public sf::Drawable {
public:
    Board board;

    sf::Font font;
    // std::vector<PlayerData> players;
    PlayerData * player1_data;
    PlayerData * player2_data;
    

    Game(sf::Color bordCol1, sf::Color bordCol2);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void startGame();
};

Game::Game(sf::Color bordCol1, sf::Color bordCol2){
    board = Board(bordCol1, bordCol2);
    
    //20 blocks 
    player1_data = new PlayerData(0, true, 0, 0);
    player2_data = new PlayerData(19, false, 19, 0);


    // PlayerData player1;
    // PlayerData player2;

    // players.push_back(player1);
    // players.push_back(player2);
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(board);
    target.draw(*player1_data);
    target.draw(*player2_data);
}

void Game::startGame(){
    sf::RenderWindow window(sf::VideoMode(640, 640), "Multiplayer Game");
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(board);
        window.draw(*player1_data);
        window.draw(*player2_data);
        window.display();
    }
}
