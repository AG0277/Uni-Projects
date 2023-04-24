#include "CollisionManager.h"



CollisionManager::~CollisionManager()
{
}

void CollisionManager::setBackground(std::shared_ptr<Block> background)
{
    this->background = background;
}

void CollisionManager::registerObject(Ball* object) {
    objectBall.push_back(object);
}

void CollisionManager::registerObject(Block* object)
{
    objectBlock.push_back(object);
}

bool CollisionManager::handleCollisions(Block* object) {

    for (size_t i = 0; i < objectBall.size(); ++i) {
            //if (objectBall.at(i)->sprite.getGlobalBounds().intersects(object->sprite.getGlobalBounds()) && object->health <= 0)
            //{
            //    objectBlock.erase(this->objectBlock.begin());
            //    return true;
            //}
             if (objectBall.at(i)->sprite.getGlobalBounds().intersects(object->sprite.getGlobalBounds()))
                return true;
        
    }
    return false;
}