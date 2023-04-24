#include "Block.h"

void Block::initTexture()
{
	if (!this->texture.loadFromFile("Textures/block.png"))
		std::cout << "ERROR::FAILED TO LOAD TEXTURE BLOCK\n";
}
void Block::initSprite()
{
	this->sprite.setTexture(this->texture);
	sprite.scale(0.3f, 0.3f);
	//sprite.setOrigin(sprite.getTexture()->getSize().x / 2, sprite.getTexture()->getSize().y / 2);
}

Block::Block()
{
	initTexture();
	initSprite();
	this->sprite.setPosition(400, 200);
	this->health = 20;

}

Block::~Block()
{
}

void Block::updateHit()
{
	this->health -= 1;
	std::cout << health;
}

std::vector<float> Block::getSpritePosition()
{

	std::vector<float> spritePos;
	float wallPosX = this->sprite.getGlobalBounds().left;
	float wallPosY = this->sprite.getGlobalBounds().top;
	float wallWidth = this->sprite.getGlobalBounds().width;
	float wallHeight = this->sprite.getGlobalBounds().height;
	spritePos.push_back(wallPosX);
	spritePos.push_back(wallPosY);
	spritePos.push_back(wallWidth);
	spritePos.push_back(wallHeight);
	return spritePos;
}

bool Block::update()
{
	if (this->health <= 0)
		return false;
	else
		return true;

}

void Block::render(sf::RenderTarget* target)
{
	this->sprite.setColor(sf::Color::Red);
	target->draw(this->sprite);
}