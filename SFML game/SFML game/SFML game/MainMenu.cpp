#include "MainMenu.h"


void MainMenu::initBackground()
{

	if (!worldBackgroundTexture.loadFromFile("Textures/MainMenuBackground.png"))
		std::cout << "ERROR::FAILED TO LOAD TEXTURE BLOCK\n";
	worldBackgroud.setTexture(worldBackgroundTexture);
	this->worldBackgroud.scale(1.2f, 1.2f);
}

MainMenu::MainMenu(sf::RenderWindow* window, sf::VideoMode videoMode):States(window,videoMode)
{
	this->initBackground();
}


void MainMenu::updateKeybind()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		this->endState();
}

void MainMenu::update(const float& deltaTime)
{
	updateKeybind();
}

void MainMenu::render(sf::RenderTarget* target)
{
	window->draw(this->worldBackgroud);
}
