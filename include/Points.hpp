#pragma once
#include <SFML/Graphics.hpp>
#include "deque"
#include "Snake.hpp"
#include <cstdlib>
#include <ctime>


class Points
{
private:
    sf::CircleShape circle;
    float gridSize;
public:
    Points();
    void respawn(std::deque<sf::RectangleShape> &snakeBody);
    void draw(sf::RenderWindow &window);
    sf::FloatRect getBounds();

};
