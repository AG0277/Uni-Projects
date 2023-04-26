#include "Game.h"

// private functions
void Game::initVariables()
{
	endGame = false;
}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(590, 900);
	this->window = new sf::RenderWindow(videoMode, "Bricks Breaker", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::initBlocks()
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

void Game::initPlayer()
{
	this->player = new Player(videoMode);
}

void Game::initBall()
{
	this->ball.push_back( new Ball(videoMode));
}

void Game::initBackground()
{
	//this->background = new BlockBackground;
	if (!this->worldBackgroundTexture.loadFromFile("Textures/background.png"))
		std::cout << "ERROR::FAILED TO LOAD TEXTURE BLOCK\n"; 
	this->worldBackgroud.setTexture(worldBackgroundTexture);
	this->worldBackgroud.scale(1.2f, 1.2f);
}


// constructor, destructor

Game::Game()
{
	collision = CollisionManager();
	initWindow();
	initVariables();
	initPlayer();
	initBall();
	initBackground();
	initBlocks();

}

Game::~Game()
{
	delete this->window;
	delete this->player;
	for (auto* ball : ball)
		delete ball;
	for (auto* block : block)
		delete block;
	delete this->background;
}



// functions



void Game::updateDeltaTime()
{
	this->deltaTime = this->dtClock.restart().asSeconds();
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{

	while (this->window->pollEvent(sfmlEvent))
	{
		if (sfmlEvent.type == sf::Event::Closed)
			this->window->close();
		if (sfmlEvent.type == sf::Event::KeyPressed && sfmlEvent.key.code == sf::Keyboard::Escape)
			this->window->close();
		if (sfmlEvent.type == sf::Event::MouseButtonReleased)
		{
			for (int i = 0; i < ball.size(); i++)
			{
				sf::Vector2i position = sf::Mouse::getPosition(*this->window);
				this->ball.at(i)->directions(position.x, position.y);
			}
		}
	}
}


void Game::updatePlayerPosition()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1, 0);

}

void Game::updateBallPosition()
{
	for (auto* ball : ball)
		ball->update(deltaTime);
}

void Game::updateBlock()
{
	int counter = 0;
	for (auto* block : block)
	{
		if (!block->update())
			this->block.erase(this->block.begin() + counter);
		++counter;
	}

}

void Game::collisionManager()
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
			ball.at(i)->updateDirection( changeX,changeY);
		
		}
		
	}

}

void Game::update()
{
	this->pollEvents();
	if (this->endGame == false)
	{
		this->collisionManager();
		this->player->update();
		this->updateBlock();
		this->updatePlayerPosition();
		this->updateBallPosition();

	}
}

void Game::render()
{
	this->window->clear();

	window->draw(this->worldBackgroud);
	this->player->render(this->window);
	for (auto* ball : ball)
		ball->render(this->window);
	for (auto* block : block)
		block->render(this->window);

	this->window->display();
}
