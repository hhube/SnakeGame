#include "Game.hpp"

Game::Game()
{
    this->initVariables();
    this->initWindow();
}

Game::~Game()
{

}

void Game::initWindow()
{
    /*
        Method for creating the window
    */
    this->video.width = 800; // Width of the window
    this->video.height = 600; // Height of the window
    this->window.create(this->video,"Snake Game",sf::Style::Titlebar | sf::Style::Close);
    this->window.setFramerateLimit(60);
}

void Game::initVariables()
{
    /*
        Method for initializing variables 
    */

    this->isRunning = true;
}

void Game::events()
{
    /*
        Method for handling events
    */
    while(this->window.pollEvent(this->event))
    {
        switch (this->event.type)
        {
        case sf::Event::Closed://Close with button
            this->window.close();
            break;
        case sf::Event::KeyPressed://Close with escape 
            if(this->event.key.code == sf::Keyboard::Escape)
            {
                this->window.close();
            }
        default:
            break;
        }
    }
}

void Game::update()
{
    /*
        Method for game update 
    */
    this->events();
    this->snake.update();
}

void Game::render()
{
    /*
        Method for game render
    */
    this->window.clear(sf::Color::Black);

    this->snake.render(this->window);

    this->window.display();
}

void Game::run()
{
    /*
        Method for running the game loop 
    */
    while(this->window.isOpen() && this->isRunning)
    {
        this->update();
        this->render();
    }
}
