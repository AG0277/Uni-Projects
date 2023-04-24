#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "CollisionManager.h"

class Block
{
private:

	sf::Sprite sprite;
	sf::Texture texture;

	int health;


	void initSprite();
	void initTexture();
public:
	Block();
	virtual ~Block();

	std::vector<float> getSpritePosition();
	bool update();
	void updateHit();
	void render(sf::RenderTarget* target);

	friend class CollisionManager;
};

