#include "CollisionManager.h"



bool CollisionManager::handleCollisions(Ball& ball, Block& block, bool& changeX, bool& changeY) {

    bool checkX = false;
    bool checkY = false;
    float radius = ball.getSprite().getGlobalBounds().width / 2;
    if (block.getSprite()->getGlobalBounds().intersects(ball.getSprite().getGlobalBounds()))
    {

        if (ball.getSprite().getPosition().y + radius >= block.getSpritePosition().at(1) + block.getSpritePosition().at(3) || ball.getSprite().getPosition().y - radius <= block.getSpritePosition().at(1))
        {
            changeY = true;
            checkX = true;

        }
        if(ball.getSprite().getPosition().x + radius >= block.getSpritePosition().at(0) + block.getSpritePosition().at(2) || ball.getSprite().getPosition().x - radius <= block.getSpritePosition().at(0))
        {
            changeX = true;
            checkY = true;
        }
        if (checkY || checkX == true)
        {
            return true;
        }

    }


    
    return false;
}

bool CollisionManager::handleBackground_BallCollisions(Ball& ball, sf::Sprite& worldbackground, bool& changeX, bool& changeY,bool& delBall)
{
    bool checkX = false;
    bool checkY = false;
    float radius = ball.getSprite().getGlobalBounds().width / 2;
    if (ball.getSprite().getPosition().y - radius <= worldbackground.getGlobalBounds().top)
    {
        changeY = true;
        checkY = true;
        ball.setPosition(ball.getSprite().getPosition().x, worldbackground.getGlobalBounds().top+ radius *1.4);

        //return true;
        
    }
    else if(ball.getSprite().getPosition().y + radius >= worldbackground.getGlobalBounds().top + worldbackground.getGlobalBounds().height)
    {
       // changeY = true;
        checkY = true;
        //ball.setPosition(ball.getSprite().getPosition().x, worldbackground.getGlobalBounds().top+worldbackground.getGlobalBounds().height- radius * 1.4);
        delBall = true;


    }


    if (ball.getSprite().getPosition().x + radius >= worldbackground.getGlobalBounds().left + worldbackground.getGlobalBounds().width )
    {
        changeX = true;
        checkX = true;
       ball.setPosition(worldbackground.getGlobalBounds().left + worldbackground.getGlobalBounds().width - radius*1.4, ball.getSprite().getPosition().y);
        //return true;
        
    }
    else if(ball.getSprite().getPosition().x - radius - 5 <= worldbackground.getGlobalBounds().left)
    {
        changeX = true;
        checkX = true;
        ball.setPosition(worldbackground.getGlobalBounds().left + radius * 1.4, ball.getSprite().getPosition().y);
        //return true;

    }
    if(checkY ||checkX ==true)
    {
        return true;
    }

    return false;
}

bool CollisionManager::handleBackground_BlockCollisions(Block& block, sf::Sprite& worldbackground)
{
    int k = block.getSprite()->getGlobalBounds().top;
    int h= block.getSprite()->getGlobalBounds().height;
    int y = worldbackground.getGlobalBounds().top + worldbackground.getGlobalBounds().height;
    if (block.getSprite()->getGlobalBounds().top + block.getSprite()->getGlobalBounds().height >= worldbackground.getGlobalBounds().top + worldbackground.getGlobalBounds().height)
    {
        return true;
    }
    return false;
}

