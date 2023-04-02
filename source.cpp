/*
    things to fix:
        Segmentation fault (core dumped) at threading where input is done
        See if input should be taken in thread function?
        print players on the board
    Later things to add:
        Update player position on board
        Add a timer
        Add a score
        Add items things to the board
*/


//g++ -pthread -g source.cpp -lsfml-graphics -lsfml-window -lsfml-system -lX11

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <time.h>
#include <queue>
#include <pthread.h>
#include <X11/Xlib.h>
#include "game.h"
// #include "board.h"
// #include "players.cpp"

using namespace std;
using namespace sf;


//GLOBAL VARIABLES
queue<PlayerData> playerQueue;
pthread_mutex_t playerMutex = PTHREAD_MUTEX_INITIALIZER;
int gameOver = 0;

//PLAYER INPUT
// Function to get keyboard input for a player
int getPlayerInput(PlayerData& player) {
    // Check if the player's keyboard is connected
    // if (!player.keyboardConnected) {
    //     return;
    // }
    //assuming the board size is 20*20
    int m_position = player.getposition();
    int x = player.getpositionX();
    int y = player.getpositionY();
    float mov_to = 400.f/15.f;
    
    if(player.getPlayer()){     //Returns true for player 1
        // Check for arrow key presses and update the player's position
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            x -= mov_to;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            x += mov_to;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            y += (mov_to);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            y -= (mov_to);
        }
        cout<<"P1 X: " << x << " Y: " << y << endl;
    }
    else{
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            x -= mov_to;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            x += mov_to;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            y += mov_to;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            y -= mov_to;
        }
        cout<<"P2 X: " << x << " Y: " << y << endl;
    }
    player.setmoved(true);
    // player.setposition(m_position);
    player.setpositionX(x);
    player.setpositionY(y); 

    return m_position;
}




//Queue


void addToPlayerQueue(PlayerData player) {
    // Lock the mutex to ensure thread safety
    pthread_mutex_lock(&playerMutex);

    // Add the player data item to the queue
    playerQueue.push(player);

    // Unlock the mutex
    pthread_mutex_unlock(&playerMutex);
}

PlayerData getNextPlayerData() {
    // Lock the mutex to ensure thread safety
    pthread_mutex_lock(&playerMutex);

    // Check if the queue is empty
    if (playerQueue.empty()) {
        // Unlock the mutex and return an empty player data item
        pthread_mutex_unlock(&playerMutex);
        return PlayerData();
    }

    // Get the next player data item from the queue
    PlayerData nextPlayer = playerQueue.front();
    playerQueue.pop();

    // Unlock the mutex and return the player data item
    pthread_mutex_unlock(&playerMutex);
    return nextPlayer;
}

int board_size(){
    int size = (rand() % 89) + 10;
    size *= 6;      //my last digit of roll number is 0 so using the second last digit
    int rollNum = 660;
    size = rollNum / size;
    size = size % 25;
    if(size<10)
        size += 10;
    return size;
}


void* playerThread(void* arg) {
    // Cast the argument to the appropriate player data type
    PlayerData* player = (PlayerData*) arg;

    // Loop until the game is over
    // while (!gameOver) {
        // Wait for player input
        //wait() will come here
        getPlayerInput(*player);

        // cout<<"INput: "<<input<<endl;

        // Check if the player collected any items
        // collectItems(player);

        // Send message to main thread with updated player data
        pthread_mutex_lock(&playerMutex);
        playerQueue.push(*player);
        pthread_mutex_unlock(&playerMutex);
    // }

    // Thread exit
    pthread_exit(NULL);
}






int main()
{

    srand(time(NULL));

    int num_blocks = board_size();

    // initialize Xlib before creating any threads
    XInitThreads();

    //max size of the board = 26
    //min size of the board = 40
    Game game (Color (122, 235, 52), Color (138, 51, 8));

    RenderWindow window(
        VideoMode(400, 400),
        "Multiplayer Game");

    //Add the players in Queue
    
    addToPlayerQueue(*game.player1_data);
    addToPlayerQueue(*game.player2_data);

    // Create thread for each player
    pthread_t Player_1, Player_2;
    pthread_create(&Player_1, NULL, playerThread, (void*) &game.player1_data);
    pthread_create(&Player_2, NULL, playerThread, (void*) &game.player2_data);

   
    // Start the game loop
    // game.startGame();
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        
        window.draw(game.board);
        
        window.draw(*game.player1_data);
        window.draw(*game.player2_data);
        
        window.display();
    }
    

     // Wait for threads to finish
    pthread_join(Player_1, NULL);
    pthread_join(Player_2, NULL);

    return 0;
}
