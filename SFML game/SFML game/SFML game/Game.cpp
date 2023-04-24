#include "Game.h"

// private functions
void Game::initVariables()
{
	endGame = false;
}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(900, 450);
	this->window = new sf::RenderWindow(videoMode, "Bricks Breaker", sf::Style::Titlebar | sf::Style::Close);
}

void Game::initBlocks()
{
	for (int i=0;i<2;i++)
	{
		this->block.push_back(new BlockYellow);
		this->block.push_back(new BlockBlue);
		//collision.registerObject(this->block.back());
	}
}

void Game::initPlayer()
{
	this->player = new Player(videoMode);
}

void Game::initBall()
{
	this->ball = new Ball(videoMode);
	collision.registerObject(this->ball);
}

void Game::initBackground()
{
	//std::shared_ptr<Block> background = std::make_shared<Block>();
	//collision.setBackground(background);
}


// constructor, destructor

Game::Game()
{
	collision = CollisionManager();
	initWindow();
	initVariables();
	initPlayer();
	initBall();
	initBlocks();

}

Game::~Game()
{
	delete this->window;
	delete this->player;
	delete this->ball;
	for (auto* block : block)
		delete block;
}



// functions



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
			sf::Vector2i position = sf::Mouse::getPosition(*this->window);
			this->ball->directions(position.x, position.y);
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
	this->ball->update();
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
	for (int i=0;i<block.size();i++)
		if (this->collision.handleCollisions(block.at(i)))
		{
			block.at(i)->updateHit();
			ball->updateDirection(block.at(i)->getSpritePosition());
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

	this->player->render(this->window);
	this->ball->render(this->window);
	for (auto* block : block)
		block->render(this->window);

	this->window->display();
}
