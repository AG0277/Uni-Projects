#pragma once
#include"States.h"
class GameState :public States
{
private:
	// Game member classes
	Player* player;
	std::vector<Block*> block;
	std::vector<Ball*> ball;
	static int ballsCounter;
	sf::Vector2i Ballposition;
	static float dt;
	bool play;
	bool canModify;

	// private initlializers
	void initBlocks();
	void initPlayer();
	void initBall();
	void initBackground();

public:
	GameState(sf::RenderWindow* window, sf::VideoMode videoMode) ;
	~GameState() ;

	void fireBalls(sf::Vector2i position);
	// update functions
	void GameBoard();
	void endState();
	void collisionManager();
	void updateKeybind() ;
	void updatePlayerPosition();
	void updateBallPosition(const float& deltaTime);
	void updateBlock();
	void updateFiredBalls(const float& deltaTime);
	void update(const float& deltaTime) ;

	// render function
	void render(sf::RenderTarget* target) ;
};
