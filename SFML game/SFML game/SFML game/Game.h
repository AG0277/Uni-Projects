#pragma once
#include "GameState.h"
#include "MainMenu.h"



class Game
{
private:
	std::stack<States*> states;
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Clock dtClock;
	float deltaTime;
	sf::Event sfmlEvent;

	void initWindow();
	void initStates();

public:
	Game();
	~Game();

	//Function
	void updateDeltaTime();
	const bool running() const;
	void pollEvents();
	void update();
	void render();
};