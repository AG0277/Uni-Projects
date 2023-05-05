#include "Block.h"



int BlockBlue::counter = 0;
int BlockYellow::counter = 0;
void Block::updateHit()
{
	this->health -= 1;
	//std::cout << health;
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
	target->draw(this->sprite);
}


/////////////////////////////////////////////////////////////////
// Block Yellow

void BlockYellow::initTexture()
{
	if (!this->texture.loadFromFile("Textures/block.png"))
		std::cout << "ERROR::FAILED TO LOAD TEXTURE BLOCK\n";
}
void BlockYellow::initSprite()
{
	this->sprite.setTexture(this->texture);
	sprite.scale(0.4f, 0.4f);
	this->sprite.setColor(sf::Color::Yellow);
	//sprite.setOrigin(sprite.getTexture()->getSize().x / 2, sprite.getTexture()->getSize().y / 2);
}

BlockYellow::BlockYellow()
{
	initTexture();
	initSprite();
	pair.first = 0;
	pair.second = 100;
	pair = std::make_pair(pair.first + this->sprite.getGlobalBounds().width * counter, pair.second );
	counter++;
	//this->sprite.setPosition(pair.first, pair.second);
	this->health = 80;

}
/////////////////////////////////////////////////////////////////
// Block Blue
void BlockBlue::initTexture()
{
	if (!this->texture.loadFromFile("Textures/block.png"))
		std::cout << "ERROR::FAILED TO LOAD TEXTURE BLOCK\n";
}
void BlockBlue::initSprite()
{
	this->sprite.setTexture(this->texture);
	sprite.scale(0.4f, 0.4f);
	this->sprite.setColor(sf::Color::Blue);
	//sprite.setOrigin(sprite.getTexture()->getSize().x / 2, sprite.getTexture()->getSize().y / 2);
}

BlockBlue::BlockBlue()
{
	counter++;
	pair.first = 200;
	pair.second = 350;
	pair = std::make_pair(pair.first *counter, pair.second *counter);
	initTexture();
	initSprite();
	this->sprite.setPosition(pair.first, pair.second);
	this->health = 30;

}