#pragma once
#include "GameState.h"

class Game
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Clock dtClock;
	float deltaTime;
	sf::Event sfmlEvent;
	std::stack<States*> states;

	void initWindow();
	void initStates();

public:
	Game();
	~Game();

	//Functions
	void updateDeltaTime();
	const bool running() const;
	void pollEvents();
	void update();
	void render();
};