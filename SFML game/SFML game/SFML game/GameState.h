#pragma once
#include"States.h"
#include "MainMenu.h"

class GameState :public States
{
private:
	// Game member classes
	Player* player;
	std::vector<Block*> block;
	std::vector<Ball*> ball;
	int ballsCounter;
	sf::Vector2i Ballposition;
	float dt;
	bool play;
	bool canModify;

	// private initlializers
	void initBlocks();
	void initPlayer();
	void initBall();
	void initBackground();

public:
	GameState(sf::RenderWindow* window, sf::VideoMode videoMode, std::stack<States*>* states) ;
	virtual ~GameState() ;

	void fireBalls(sf::Vector2i position);
	// update functions
	void changeGameBoard();
	void collisionManager(const float& deltaTime);
	void updateKeybind() ;
	void updatePlayerPosition();
	void updateBallPosition(const float& deltaTime);
	void updateBlock();
	void updateFiredBalls(const float& deltaTime);
	void update(const float& deltaTime, sf::Time& dt) ;

	// render function
	void render(sf::RenderTarget* target) ;
};
