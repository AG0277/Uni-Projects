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
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	CollisionManager collision;
	bool quitState;
	sf::Texture worldBackgroundTexture;
	sf::Sprite worldBackgroud;

public:
	States(sf::RenderWindow* window, sf::VideoMode videoMode);
	~States();


	bool getQuit();
	void endState() { this->quitState = true; };
	//bool getQuitState() { return this->quitState; };
	
	virtual void updateKeybind() = 0;
	virtual	void update(const float& deltaTime) = 0;
	virtual void render(sf::RenderTarget* target) = 0;
};


