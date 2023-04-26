#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.h"
#include "Block.h"

class Block;
class Ball;
class CollisionManager {

public:
    bool handleCollisions(Ball& ball, Block& block, bool& changeX, bool& changeY);
    bool handleBackgroundCollisions(Ball& ball, sf::Sprite& worldbackground, bool& changeX, bool& changeY);
}; 