#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.h"
#include "Block.h"

class Block;
class Ball;
class CollisionManager {
private:
    std::vector<Ball*> objectBall;
    std::vector<Block*> objectBlock;
    std::shared_ptr<Block> background;

public:
    CollisionManager() {};
    ~CollisionManager();

    void setBackground(std::shared_ptr<Block> background);
    void registerObject(Ball* object);
    void registerObject(Block* object);

    bool handleCollisions(Block* object);



}; 