#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ball.h"
#include "Block.h"
#include "CollisionManager.h"

class Game
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;

	Player* player;
	Ball* ball;
	std::vector<Block*> block;
	CollisionManager collision;

	void initVariables();
	void initWindow();

	void initBlocks();
	void initPlayer();
	void initBall();
	void initBackground();
public:
	Game();
	~Game();
	// Accessors

	//collisions
	void collisionManager();

	//Functions
	const bool running() const;
	void pollEvents();
	void updatePlayerPosition();
	void updateBallPosition();
	void updateBlock();
	void update();
	void render();
};