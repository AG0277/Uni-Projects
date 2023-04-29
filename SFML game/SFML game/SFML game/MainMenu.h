#pragma once
#include"States.h"

class MainMenu:public States
{
private:

	void initBackground();
public:
	MainMenu(sf::RenderWindow* window, sf::VideoMode videoMode);
	~MainMenu() {};

	void updateKeybind();
	void update(const float& deltaTime);
	void render(sf::RenderTarget* target) ;
};


