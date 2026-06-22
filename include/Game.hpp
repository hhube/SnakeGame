#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.hpp"
//Main game class
class Game
{
private:
    //Private variables
    sf::RenderWindow window;
    sf::VideoMode video;
    sf::Event event;
    sf::RectangleShape shape; //Shape for snake 
    sf::CircleShape circle;   //Shape for points

    Snake snake;

    bool isRunning; //For game loop

    //Private methods
    void initWindow();
    void initVariables();
public:
    //Constructor and destructor 
    Game();
    ~Game();
    //Public methods
    void events();
    void update();
    void render();
    void run();
};