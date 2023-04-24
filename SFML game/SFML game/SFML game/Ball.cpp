#include "Ball.h"

void Ball::initSprite()
{
	this->sprite.setTexture(this->texture);
	sprite.scale(0.03f, 0.03f);
	sprite.setOrigin(sprite.getTexture()->getSize().x / 2, sprite.getTexture()->getSize().y / 2);
}
void Ball::initTexture()
{
	if (!this->texture.loadFromFile("Textures/ball.png"))
		std::cout << "ERROR::FAILED TO LOAD TEXTURE BALL\n";
}

Ball::Ball(sf::VideoMode videoMode)
{
	initTexture();
	initSprite();
	this->sprite.setPosition(videoMode.width / 2 - videoMode.width * 0.05, videoMode.height * 0.75);
	this->speed = 1;
}

Ball::~Ball()
{
}

void Ball::directions(int x, int y)
{
	sf::Vector2f ballpos = this->sprite.getPosition();
	float angle = std::atan2f(-(ballpos.y - y), -(ballpos.x - x));
	direction.x = std::cos(angle);
	direction.y = std::sin(angle);

}

void Ball::updateDirection(std::vector<float> spritePos)
{
	if (sprite.getPosition().y <spritePos.at(1) + spritePos.at(3) && sprite.getPosition().y  > spritePos.at(1))
		direction.x = -direction.x;
	else if (sprite.getPosition().x < spritePos.at(0) + spritePos.at(2) && sprite.getPosition().x  >spritePos.at(0))
		direction.y = -direction.y;
	else
	{
		direction.x = -direction.x;
		direction.y = -direction.y;
	}

}

void Ball::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

void Ball::update()
{

	this->sprite.move(direction.x * this->speed, direction.y * this->speed);

}
