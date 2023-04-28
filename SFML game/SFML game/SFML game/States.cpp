#include "States.h"

States::States(sf::RenderWindow* window, sf::VideoMode videoMode)
{
	this -> window = window;
	this->videoMode = videoMode;
	this->quit = false;
}

const bool& States::getQuit() const
{
	return this->quit;
}
