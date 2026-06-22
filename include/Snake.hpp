#pragma once
#include "deque"
#include <SFML/Graphics.hpp>

enum class Direction { NONE, UP, DOWN, LEFT, RIGHT };

class Snake //Class for the snake
{
private:
    //Private stuff 
    std::deque<sf::RectangleShape> snakeBody;//Snake body
    Direction currentDirection;//Snake direction
    sf::RectangleShape shape;//Snake head

    float gridSize;//Snake size (one grid cell)
    
    bool alive;//If snake is alive 
    bool pendingGrow;//If snake is growing 

    sf::Clock moveTimer;
    float moveDelay;//Snake delay 

    void moveBody();
    void handleScreenWrap();
    void checkSelfCollision();

public:
    //Public stuff 
    Snake();
    void update();
    void render(sf::RenderWindow& window);
    void grow();
    void handleInput();
    bool isAlive() const;
    sf::FloatRect getHeadBounds() const;


};