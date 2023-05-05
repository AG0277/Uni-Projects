#include "GameState.h"



void GameState::initBlocks()
{
		for (int j = 0; j < map.size(); j++)
		{
			for (int k = 0; k < 13; k++)
			{
				if (map.at(j).at(k) == 'g')
				{
					this->block.push_back(new BlockYellow);
					this->block.at(this->block.size() -1)->getSprite()->setPosition(this->block.at(0)->getSprite()->getGlobalBounds().width * k+12, this->block.at(0)->getSprite()->getGlobalBounds().height * j);
					map.at(j).at(k) = ' ';
				}
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
}

void GameState::initBackground()
{

	if (!this->worldBackgroundTexture.loadFromFile("Textures/background.png"))
		std::cout << "ERROR::FAILED TO LOAD TEXTURE background\n";
	this->worldBackgroud.setTexture(worldBackgroundTexture);
	if (!this->framebackgroundtex.loadFromFile("Textures/background1.png"))
		std::cout << "ERROR::FAILED TO LOAD TEXTURE frame\n";
	this->framebackground.setTexture(framebackgroundtex);
}
void GameState::initFont()
{
	if (!font.loadFromFile("font/arial.ttf"))
		std::cout << "ERROR::FAILED TO LOAD FONT\n";
	text.setFont(font);
}

GameState::GameState(sf::RenderWindow* window, sf::VideoMode videoMode,std::stack<States*>* states)
	:States(window,videoMode,states)
{
	map = {
"#############",
"#           #",
"gg g gggggggggg",
"#  gg g     #",
"# g  gg gg g#",
"#           #",
"#           #",
"#           #",
"#           #",
"#           #",
"#           #",
"#  g g      #",
"#           #",
"#           #",
"#############",
	};
	initBlocks();
	collision = CollisionManager();
	initBackground();
	initPlayer();
	initBall();
	initFont();
	colisionON = true;
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
		ballsPushed++;
		this->ball.at(ballsCounter - 1)->directions(position.x, position.y);

}

void GameState::changeGameBoard()
{
	for (auto* block : block)
		{
			block->getSprite()->setPosition(block->getSprite()->getGlobalBounds().left, block->getSprite()->getGlobalBounds().top + block->getSprite()->getGlobalBounds().height);
		}
}

void GameState::updateKeybind()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{

	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right) )
		for (int i = 0; i < ball.size(); i++)
		{
			this->Ballposition = sf::Mouse::getPosition(*this->window);
			this->ball.at(i)->directions(Ballposition.x, Ballposition.y);
		}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&& canModify == true)
	{
		Ballposition = sf::Mouse::getPosition(*this->window);
		ball.erase(ball.begin());
		canModify = false;
		fireBalls(Ballposition);
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
		if (ballsPushed > 0 && ballsPushed < 30&& canModify==false )
		{

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
		bool doublecolision = false;
		if (colisionON == true)
			for (int j = 0; j < block.size(); j++)
			{
				bool changeX = false;
				bool changeY = false;
				if (this->collision.handleCollisions(*ball, *block.at(j), changeX, changeY))
				{
					if (doublecolision == false)
						ball->updateDirection(changeX, changeY);
					block.at(j)->updateHit();
					doublecolision = true;
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
				counter--;
				ballsCounter--;
				if (this->ball.size() == 0 && canModify == false)
				{
					changeGameBoard();
					this->ball.push_back(new Ball(videoMode, worldBackgroud));
					canModify = true;
					ballsPushed = 0;
					colisionON = true;
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
		}
	}
}

void GameState::updateGUI()
{
	if (this->gui->createButton("PULL BALLS", 200, 100, 300, 797))\
	{
		colisionON = false;
		for (int i = 0; i < ball.size(); i++)
		{
			ball.at(i)->directions(400, 800);
		}
	}
}
void GameState::update(const float& deltaTime, sf::Time& dt)
{
	this->collisionManager(deltaTime);
	this->updateBlock();
	this->updateKeybind();
	this->updatePlayerPosition();
	this->updateBallPosition(deltaTime);
	this->updateFiredBalls(deltaTime);
	ImGui::SFML::Update(*window, dt);
	this->updateGUI();
}

void GameState::render(sf::RenderTarget* target)
{
	window->draw(this->worldBackgroud);
	window->draw(this->framebackground);
	for (auto* ball : ball)
		ball->render(this->window);
	for (auto* block : block)
	{
		block->render(this->window);
		text.setString(std::to_string(block->getHealth()));
		text.setPosition(block->getSprite()->getGlobalBounds().left+ block->getSprite()->getGlobalBounds().width/4, block->getSprite()->getGlobalBounds().top+ block->getSprite()->getGlobalBounds().height/4);
		window->draw(text);
			
	}
	ImGui::SFML::Render(*window);

}
