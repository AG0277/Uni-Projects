#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "CollisionManager.h"

class Block
{
protected:

	sf::Sprite sprite;
	sf::Texture texture;
	std::pair<int, int> pair;

	int health;

	virtual void initSprite() = 0;
	virtual void initTexture() = 0;
public:

	virtual std::vector<float> getSpritePosition();
	virtual bool update();
	virtual void updateHit();
	virtual void render(sf::RenderTarget* target);

	friend class CollisionManager;
};

class BlockYellow :public Block
{
private:
	void initTexture();
	void initSprite();
	static int counter;
public:
	BlockYellow();
	~BlockYellow();

};


class BlockBlue :public Block
{
private:
	void initTexture();
	void initSprite();
	static int counter;
public:
	BlockBlue();
	~BlockBlue() { counter--; };

};


