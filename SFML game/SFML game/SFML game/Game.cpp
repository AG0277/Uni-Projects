#include "Game.h"

// private functions


void Game::initWindow()
{
	this->videoMode = sf::VideoMode(590, 900);
	this->window = new sf::RenderWindow(videoMode, "Bricks Breaker", sf::Style::Titlebar | sf::Style::Close);
	this->window->setVerticalSyncEnabled(false);
	ImGui::SFML::Init(*window);


	//this->window->setFramerateLimit(60);
}

void Game::initStates()
{
	//this->gui = new GUI(this->window);

	this->states.push(new MainMenu(this->window, this->videoMode, &this->states));

}


// constructor, destructor

Game::Game()
{
	initWindow();
	initStates();
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}


void Game::updateDeltaTime()
{
	this->deltaTime = 1;
	this->dt = dtClock.restart();
	//this->deltaTime = this->dtClock.getElapsedTime().asSeconds();
	//std::cout << dtClock.restart().asSeconds() << std::endl;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

bool Game::pollEvents()
{

	while (this->window->pollEvent(sfmlEvent))
	{
		ImGui::SFML::ProcessEvent(*window, sfmlEvent);
		if (sfmlEvent.type == sf::Event::Closed)
		{
			this->window->close();
			ImGui::SFML::Shutdown();
			exit(EXIT_SUCCESS);
		}
		if (sfmlEvent.type == sf::Event::KeyPressed && sfmlEvent.key.code == sf::Keyboard::Escape)
		{
			int x = 5;
			this->window->close();
			ImGui::SFML::Shutdown();
			exit(EXIT_SUCCESS);
		}
		//if (sfmlEvent.type == sf::Event::KeyPressed && sfmlEvent.key.code == sf::Keyboard::Enter)
		//	this->states.push(new GameState(this->window, this->videoMode, &this->states));
	}
	return true;
}

bool Game::update()
{
	static int j = 0;
	if (this->pollEvents())
	{
		if (this->window->hasFocus())
		{
			if (!this->states.empty())
			{
				this->states.top()->update(this->deltaTime, this->dt);
				if(j<=0)
				{
					ImVec2 buttonPos(this->window->getSize().x+200, this->window->getSize().y+200);
					ImVec2 buttonPos1(0, 0);
					ImGui::SetWindowPos(buttonPos1);
					ImGui::SetNextWindowSize(buttonPos);
				}
				j++;
				
				if (this->states.top()->getQuit())
				{
					this->states.top()->endState();
					delete this->states.top();
					this->states.pop();
				}
			}
		}
		return true;
	}
	else
	{
		this->states.top()->endState();
		delete this->states.top();
		this->states.pop();
		return false;
	}

	
}

void Game::render()
{

	this->window->clear();
	if (!this->states.empty())
		this->states.top()->render(this->window);
	this->window->display();
}
