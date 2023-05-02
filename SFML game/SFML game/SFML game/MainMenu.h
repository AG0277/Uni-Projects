#pragma once
#include"States.h"
#include"GameState.h"

class MainMenu:public States
{
private:

	void initBackground();
public:
	MainMenu(sf::RenderWindow* window, sf::VideoMode videoMode, std::stack<States*>* states);
	virtual ~MainMenu() {};

	void updateKeybind();
	void update(const float& deltaTime);
	void render(sf::RenderTarget* target) ;
};


