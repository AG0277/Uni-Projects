#include "Game.h"

// private functions


void Game::initWindow()
{
	this->videoMode = sf::VideoMode(590, 900);
	this->window = new sf::RenderWindow(videoMode, "Bricks Breaker", sf::Style::Titlebar | sf::Style::Close);
	this->window->setVerticalSyncEnabled(false);
	//this->window->setFramerateLimit(60);
}

void Game::initStates()
{
	this->states.push(new GameState(this->window, this->videoMode));
	//this->states.push(new MainMenu(this->window, this->videoMode));
}


// constructor, destructor

Game::Game()
{
	initWindow();
	initStates();
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}


void Game::updateDeltaTime()
{
	this->deltaTime = 1;//= this->dtClock.restart().asSeconds();
	//std::cout << dtClock.restart().asSeconds() << std::endl;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{

	while (this->window->pollEvent(sfmlEvent))
	{
		if (sfmlEvent.type == sf::Event::Closed)
			this->window->close();
		if (sfmlEvent.type == sf::Event::KeyPressed && sfmlEvent.key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}

void Game::update()
{
	this->pollEvents();
	if (!this->states.empty())
	{
		this->states.top()->update(this->deltaTime);
		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
}

void Game::render()
{
	this->window->clear();
	if (!this->states.empty())
		this->states.top()->render(this->window);
	this->window->display();
}
