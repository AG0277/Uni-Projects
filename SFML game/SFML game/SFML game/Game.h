#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ball.h"
#include "Block.h"
#include "CollisionManager.h"
#include <unordered_map>

class Game
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Clock dtClock;
	float deltaTime;
	sf::Event sfmlEvent;

	Player* player;
	std::vector<Block*> block;
	std::vector<Ball*> ball;
	CollisionManager collision;
	BlockBackground* background;

	sf::Texture worldBackgroundTexture;
	sf::Sprite worldBackgroud;

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
	float getDeltaTime() { return deltaTime; };

	//collisions
	void collisionManager();

	//Functions
	void updateDeltaTime();
	const bool running() const;
	void pollEvents();
	void updatePlayerPosition();
	void updateBallPosition();
	void updateBlock();
	void update();
	void render();
};