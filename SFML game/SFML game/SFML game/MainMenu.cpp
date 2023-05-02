#include "MainMenu.h"


void MainMenu::initBackground()
{

	if (!worldBackgroundTexture.loadFromFile("Textures/MainMenuBackground.png"))
		std::cout << "ERROR::FAILED TO LOAD TEXTURE BLOCK\n";
	worldBackgroud.setTexture(worldBackgroundTexture);
	this->worldBackgroud.scale(1.2f, 1.2f);
}

MainMenu::MainMenu(sf::RenderWindow* window, sf::VideoMode videoMode, std::stack<States*>* states):States(window,videoMode,states)
{
	this->initBackground();
}


void MainMenu::updateKeybind()
{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			this->states->push(new GameState(this->window, this->videoMode, this->states));

		}
	

}

void MainMenu::update(const float& deltaTime, sf::Time& dt)
{
	updateKeybind();
	ImGui::SFML::Update(*window, dt);
	ImGui::Begin("Hello, world!");
	ImGui::Button("Look at this pretty button");
	ImGui::End();
}

void MainMenu::render(sf::RenderTarget* target)
{
	window->draw(this->worldBackgroud);
	ImGui::SFML::Render(*window);
}
