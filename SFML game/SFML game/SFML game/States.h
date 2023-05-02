#pragma once
#include<vector>
#include <stack>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ball.h"
#include "Block.h"
#include "CollisionManager.h"
#include <map>

class States
{
private:

protected:
	std::stack<States*>* states;
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	CollisionManager collision;
	bool quitState;
	sf::Texture worldBackgroundTexture;
	sf::Sprite worldBackgroud;

public:
	States(sf::RenderWindow* window, sf::VideoMode videoMode, std::stack<States*>* states);
	virtual ~States();


	bool getQuit();
	void endState() { this->quitState = true; };
	//bool getQuitState() { return this->quitState; };
	
	virtual void updateKeybind() = 0;
	virtual	void update(const float& deltaTime) = 0;
	virtual void render(sf::RenderTarget* target) = 0;
};


