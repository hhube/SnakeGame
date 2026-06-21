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
        Methods for creating the window
    */
    this->video.width = 800;
    this->video.height = 600;
    this->window.create(this->video,"Snake Game",sf::Style::Titlebar | sf::Style::Close);
    this->window.setFramerateLimit(60);
}

void Game::initVariables()
{

}

void Game::events()
{
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
    this->events();
}

void Game::render()
{
    this->window.clear(sf::Color::Black);
    this->window.display();
}

void Game::run()
{
    while(this->window.isOpen())
    {
        this->update();
        this->render();
    }
}
