#include "GameState.h"



void GameState::initBlocks()
{
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
		{
			int k = 0;
			this->block.push_back(new BlockYellow);
		}
		else
		{
			int k = 0;
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

GameState::GameState(sf::RenderWindow* window, sf::VideoMode videoMode,std::stack<States*>* states)
	:States(window,videoMode,states)
{
	initBlocks();
	collision = CollisionManager();
	initBackground();
	initPlayer();
	initBall();
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

void GameState::changeGameBoard()
{

	if (this->ballsCounter <= 0 && play == false)
	{
		for (auto* block : block)
		{
			block->getSprite()->setPosition(block->getSprite()->getGlobalBounds().left, block->getSprite()->getGlobalBounds().top + block->getSprite()->getGlobalBounds().height);
		}
	}

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
		ball.erase(ball.begin());
		ballsCounter--;
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
		if (ballsCounter > 0 && ballsCounter < 30 && canModify == true&&play == false)
		{
			if (ballsCounter == 29)
				canModify = false;
			fireBalls(Ballposition);
		}
		dt = 0;
	}
	
}

void GameState::collisionManager(const float& deltaTime)
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
		if (this->collision.handleBackground_BallCollisions(*ball, worldBackgroud, changeX, changeY, delBall))
		{
			ball->updateDirection(changeX, changeY);
			if (delBall == true)
			{
				this->ball.erase(this->ball.begin() + counter);
				ballsCounter--;
				if (this->ball.size() == 0)
				{ 
					changeGameBoard();
					play = true;
					this->ball.push_back(new Ball(videoMode,worldBackgroud));
					ballsCounter++;
					canModify = true;
				}
			}
		}
		++counter;
	}

	if (block.size() <= 0)
		std::cout << "asd";

	for (auto block : block)
	{
		if (collision.handleBackground_BlockCollisions(*block, worldBackgroud))
		{

			this->endState();
			//std::cout <<deltaTime<< " XDDDDDDDDDDDDDDDDD";
			//this->states->push(new MainMenu(this->window, this->videoMode, this->states));
		}
	}
}

void GameState::update(const float& deltaTime, sf::Time& dt)
{
	this->updateBlock();
	this->collisionManager(deltaTime);
	this->player->update();
	this->updateKeybind();
	this->updatePlayerPosition();
	this->updateBallPosition(deltaTime);
	this->updateFiredBalls(deltaTime);
	ImGui::SFML::Update(*window, dt);
	ImGui::Begin("Hello, world!");
	ImGui::Button("Look at this pretty button");
	ImGui::End();

}

void GameState::render(sf::RenderTarget* target)
{
	window->draw(this->worldBackgroud);
	this->player->render(this->window);
	for (auto* ball : ball)
		ball->render(this->window);
	for (auto* block : block)
		block->render(this->window);
	ImGui::SFML::Render(*window);

}
