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
	bool quit;

public:
	States(sf::RenderWindow* window, sf::VideoMode videoMode);
	~States() {};

	const bool& getQuit() const;
	virtual void checkForQuit() {};
	virtual void endState()=0;

	virtual void updateKeybind() = 0;
	virtual	void update(const float& deltaTime) = 0;
	virtual void render(sf::RenderTarget* target) = 0;
};


