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

bool CollisionManager::handleCollisions() {

    for (size_t i = 0; i < objectBall.size(); ++i) {
        for (size_t j = 0; j < objectBlock.size(); ++j) {
            if (objectBall.at(i)->sprite.getGlobalBounds().intersects(objectBlock.at(j)->sprite.getGlobalBounds()) && objectBlock.at(j)->health <= 0)
            {
                objectBlock.erase(this->objectBlock.begin() + j);
                return true;
            }
            else if (objectBall.at(i)->sprite.getGlobalBounds().intersects(objectBlock.at(j)->sprite.getGlobalBounds()))
                return true;
        }
    }
    return false;
}