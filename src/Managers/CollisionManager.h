//
// Created by Xian Chance Saulter on 10/17/18.
//

#ifndef PONG_COLLISIONMANAGER_H
#define PONG_COLLISIONMANAGER_H

#include "../Entities/Ball.h"
#include "../Entities/Paddle.h"
#include "../Entities/PaddleBot.h"


static class CollisionManager {
public:
   static bool collision(Ball& ball, Paddle& paddle);
   static sf::Vector2f newVel(Ball& ball, Paddle& paddle);

    static bool collision(Ball& ball, PaddleBot& bot);
    static sf::Vector2f newVel(Ball& ball, PaddleBot& bot);
};


#endif //PONG_COLLISIONMANAGER_H
