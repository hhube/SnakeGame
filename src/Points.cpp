#include "Points.hpp"
#include <cstdlib>
#include <ctime>

Points::Points()
{
    // Odpalamy ziarno losowości na samym starcie
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    this->gridSize = 20.f;
    this->circle.setFillColor(sf::Color::Red);
    // Promień to 1/2 z 20, czyli 10 pikseli
    this->circle.setRadius(this->gridSize / 2.f); 
}

void Points::respawn(std::deque<sf::RectangleShape> &snakeBody)
{   
    bool collision;
    int x, y;

    do {
        // Na starcie pętli zakładamy w 1/1, że pozycja jest dobra
        collision = false; 
        
        // Losujemy indeksy kafelków (zakładając okno 800x600)
        x = std::rand() % 40;
        y = std::rand() % 30;

        // Ustawiamy pozycję, mnożąc przez siatkę!
        this->circle.setPosition(
            static_cast<float>(x) * this->gridSize, 
            static_cast<float>(y) * this->gridSize
        );

        // Pętla sprawdzająca w 100/100 całe ciało węża
        for (size_t i = 0; i < snakeBody.size(); i++) {
            if (snakeBody[i].getGlobalBounds().intersects(this->circle.getGlobalBounds())) {
                collision = true; // Znaleźliśmy kolizję
                break;            // Przerywamy pętlę for, bo już wiemy, że miejsce jest złe
            }
        }

    } while (collision); // Jeśli była kolizja, pętla do-while zakręci się od nowa
}

void Points::draw(sf::RenderWindow &window)
{
    window.draw(this->circle);
}

sf::FloatRect Points::getBounds()
{
    return this->circle.getGlobalBounds();
}