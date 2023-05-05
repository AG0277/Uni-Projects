#pragma once
#include"States.h"
#include "MainMenu.h"
#include <unordered_map>

class GameState :public States
{
private:
	// Game member classes
	Player* player;
	std::vector<Block*> block;
	std::vector<Ball*> ball;
	int ballsCounter;
	int ballsPushed;
	sf::Vector2i Ballposition;
	float dt;
	bool colisionON;
	bool canModify;
	sf::Text text;
	sf::Font font;
	sf::Texture framebackgroundtex;
	sf::Sprite framebackground;

	std::vector<std::string> map;
	// private initlializers
	void initBlocks();
	void initPlayer();
	void initBall();
	void initBackground();
	void initFont();

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
	void updateGUI();
	void update(const float& deltaTime, sf::Time& dt) ;

	// render function
	void render(sf::RenderTarget* target) ;
};
