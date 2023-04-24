#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "CollisionManager.h"

class Ball
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float speed;
	sf::Vector2f direction;

	void initSprite();
	void initTexture();
public:
	Ball(sf::VideoMode videoMode);
	~Ball();

	void directions(int x, int y);
	void updateDirection(std::vector<float> spritePos);
	void render(sf::RenderTarget* target);
	void update();
	friend class CollisionManager;
};

