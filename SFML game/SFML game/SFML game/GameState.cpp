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
	this->ball.push_back(new Ball(videoMode,worldBackgroud));
	ballsCounter++;
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
	initBackground();
	initPlayer();
	initBall();
	initBlocks();
	play = true;
	canModify = true;

}

GameState::~GameState()
{
	delete this->player;
	for (auto* ball : ball)
		delete ball;
	for (auto* block : block)
		delete block;
}

void GameState::fireBalls(sf::Vector2i position)
{

		this->ball.push_back(new Ball(videoMode,worldBackgroud));
		ballsCounter++;
		this->ball.at(ballsCounter-1)->directions(position.x, position.y);
}

void GameState::GameBoard()
{

	if (this->ballsCounter <= 0 && play == false)
	{
		for (auto* block : block)
		{
			block->getSprite()->setPosition(block->getSprite()->getGlobalBounds().left, block->getSprite()->getGlobalBounds().top + block->getSprite()->getGlobalBounds().height);
		}
	}

}

void GameState::endState()
{

}

void GameState::updateKeybind()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1, 0);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && this->play == true)
		for (int i = 0; i < ball.size(); i++)
		{
			this->Ballposition = sf::Mouse::getPosition(*this->window);
			this->ball.at(i)->directions(Ballposition.x, Ballposition.y);
		}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->play == true)
	{
		Ballposition = sf::Mouse::getPosition(*this->window);
		fireBalls(Ballposition);
		this->play = false;
	}
}

void GameState::updatePlayerPosition()
{

}

void GameState::updateBallPosition(const float& deltaTime)
{
	int counter = 0;
	for (auto* ball : ball)
	{
		ball->update(deltaTime);
	}
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
		if (ballsCounter-1 > 0 && ballsCounter < 30 && canModify == true)
		{
			if (ballsCounter == 29)
				canModify = false;
			fireBalls(Ballposition);
			dt = 0;
		}
	}
	
}

void GameState::collisionManager()
{
	int counter = 0;

	for (auto ball:ball)
	{

		for (int j = 0; j < block.size(); j++)
		{
			bool changeX = false;
			bool changeY = false;

			if (this->collision.handleCollisions(*ball, *block.at(j), changeX, changeY))
			{
				ball->updateDirection(changeX, changeY);
				block.at(j)->updateHit();
			}
		}
		bool changeX = false;
		bool changeY = false;
		bool delBall = false;
		if (this->collision.handleBackgroundCollisions(*ball, worldBackgroud, changeX, changeY, delBall))
		{
			ball->updateDirection(changeX, changeY);
			if (delBall == true)
			{
				this->ball.erase(this->ball.begin() + counter);
				ballsCounter--;
				if (this->ball.size() == 0)
				{ 
					GameBoard();
					play = true;
					this->ball.push_back(new Ball(videoMode,worldBackgroud));
					ballsCounter++;
					canModify = true;
				}
			}
		}
		++counter;
	}

}

void GameState::update(const float& deltaTime)
{
	this->collisionManager();
	this->player->update();
	this->updateBlock();
	this->updateKeybind();
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
