#include "Snake.hpp"

Snake::Snake()
{
    /*
        Snake born 
    */
    this->gridSize = 20.0f;
    this->currentDirection = Direction::NONE;//Move is off
    this->alive = true;
    this->pendingGrow = false;
    this->moveDelay = 0.1f;
    this->shape.setSize(sf::Vector2f(this->gridSize, this->gridSize));
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setPosition(sf::Vector2f(400.0f, 300.0f));
    this->snakeBody.push_front(this->shape);

}

void Snake::moveBody() {
    //Copy current head
    sf::RectangleShape newHead = this->snakeBody.front();

    //Move head
    if (this->currentDirection == Direction::UP) newHead.move(0.f, -this->gridSize);
    else if (this->currentDirection == Direction::DOWN) newHead.move(0.f, this->gridSize);
    else if (this->currentDirection == Direction::LEFT) newHead.move(-this->gridSize, 0.f);
    else if (this->currentDirection == Direction::RIGHT) newHead.move(this->gridSize, 0.f);

    //Add to the deque
    this->snakeBody.push_front(newHead);

    //Snake lenght
    if (this->pendingGrow) {
        //Points ate 
        this->pendingGrow = false;
    } else {
        //Normal move 
        this->snakeBody.pop_back();
    }
}

void Snake::handleScreenWrap() {
    //Current head position
    sf::Vector2f pos = this->snakeBody.front().getPosition();

    //Check for X
    if (pos.x < 0.f) pos.x = 800.f - this->gridSize;
    else if (pos.x >= 800.f) pos.x = 0.f;
    
    //Check for Y
    if (pos.y < 0.f) pos.y = 600.f - this->gridSize;
    else if (pos.y >= 600.f) pos.y = 0.f;

    //Save the new position 
    this->snakeBody.front().setPosition(pos);
}

void Snake::checkSelfCollision()
{
    for(size_t i=1; i<this->snakeBody.size(); i++)
    {
        if(this->snakeBody.front().getGlobalBounds().intersects(this->snakeBody[i].getGlobalBounds()))
        {
            this->alive = false; //Game over
            break;
        }
    }
}

void Snake::update() 
{
    this->handleInput();

    if (this->currentDirection == Direction::NONE || !this->alive) return;

    if (this->moveTimer.getElapsedTime().asSeconds() >= this->moveDelay) {
        this->moveBody();
        this->handleScreenWrap();
        this->checkSelfCollision();
        
        this->moveTimer.restart();
    }
}

void Snake::render(sf::RenderWindow &window)
{
    for(const auto& segment : this->snakeBody)
    {
        window.draw(segment);
    }
}

void Snake::grow()
{
    this->pendingGrow = true;
}

void Snake::handleInput()
{
    /*
        Method for handling input(WSAD)
    */

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->currentDirection != Direction::DOWN)
    {
        this->currentDirection = Direction::UP;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->currentDirection != Direction::UP)
    {
        this->currentDirection = Direction::DOWN;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->currentDirection != Direction::RIGHT)
    {
        this->currentDirection = Direction::LEFT;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->currentDirection != Direction::LEFT)
    {
        this->currentDirection = Direction::RIGHT;
    }
}

bool Snake::isAlive() const
{
    return this->alive;
}

sf::FloatRect Snake::getHeadBounds() const
{
    return this->snakeBody.front().getGlobalBounds();
}

std::deque<sf::RectangleShape>& Snake::getBody() {
    return this->snakeBody;
}