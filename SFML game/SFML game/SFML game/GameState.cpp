#include "GameState.h"

int GameState::ballsCounter = 0;
float GameState::dt = 0;
void GameState::initBlocks()
{
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
		{
			this->block.push_back(new BlockYellow);
		}
		else
		{
			this->block.push_back(new BlockBlue);
		}
	}
}

void GameState::initPlayer()
{
	this->player = new Player(videoMode);
}

void GameState::initBall()
{
	this->ball.push_back(new Ball(videoMode));
}

void GameState::initBackground()
{
	if (!this->worldBackgroundTexture.loadFromFile("Textures/background.png"))
		std::cout << "ERROR::FAILED TO LOAD TEXTURE BLOCK\n";
	this->worldBackgroud.setTexture(worldBackgroundTexture);
	this->worldBackgroud.scale(1.2f, 1.2f);
}


GameState::GameState(sf::RenderWindow* window, sf::VideoMode videoMode)
	:States(window,videoMode)
{
	collision = CollisionManager();
	initPlayer();
	initBall();
	initBackground();
	initBlocks();

}

GameState::~GameState()
{
	delete this->player;
	for (auto* ball : ball)
		delete ball;
	for (auto* block : block)
		delete block;
	delete this->background;
}

void GameState::fireBalls(sf::Vector2i position)
{

		this->ball.push_back(new Ball(videoMode));
		ballsCounter++;
		this->ball.at(ballsCounter)->directions(position.x, position.y);
}



void GameState::endState()
{

}

void GameState::updateKeybind()
{
}

void GameState::updatePlayerPosition()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1, 0);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		for (int i = 0; i < ball.size(); i++)
		{
			this->Ballposition = sf::Mouse::getPosition(*this->window);
			this->ball.at(i)->directions(Ballposition.x, Ballposition.y);
		}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		Ballposition = sf::Mouse::getPosition(*this->window);
		fireBalls(Ballposition);
	}

}
void GameState::updateBallPosition(const float& deltaTime)
{
	for (auto* ball : ball)
		ball->update(deltaTime);
}

void GameState::updateBlock()
{
	int counter = 0;
	for (auto* block : block)
	{
		if (!block->update())
			this->block.erase(this->block.begin() + counter);
		++counter;
	}

}

void GameState::updateFiredBalls(const float& deltaTime)
{

	float temp = videoMode.width/20;
	this->dt = (dt+temp) ;
	if (dt > 100)
	{
		if (ballsCounter > 0 && ballsCounter < 120)
		{
			fireBalls(Ballposition);
			dt = 0;
		}
	}
	
}

void GameState::collisionManager()
{
	int counter = 0;

	for (int i = 0; i < ball.size(); i++)
	{

		for (int j = 0; j < block.size(); j++)
		{
			bool changeX = false;
			bool changeY = false;

			if (this->collision.handleCollisions(*ball.at(i), *block.at(j), changeX, changeY))
			{
				ball.at(i)->updateDirection(changeX, changeY);
				block.at(j)->updateHit();
			}
		}
		bool changeX = false;
		bool changeY = false;
		if (this->collision.handleBackgroundCollisions(*ball.at(i), worldBackgroud, changeX, changeY))
		{
			ball.at(i)->updateDirection(changeX, changeY);

		}

	}

}

void GameState::update(const float& deltaTime)
{

this->collisionManager();
this->player->update();
this->updateBlock();
this->updatePlayerPosition();
this->updateBallPosition(deltaTime);
this->updateFiredBalls(deltaTime);
}

void GameState::render(sf::RenderTarget* target)
{
	window->draw(this->worldBackgroud);
	this->player->render(this->window);
	for (auto* ball : ball)
		ball->render(this->window);
	for (auto* block : block)
		block->render(this->window);
}
