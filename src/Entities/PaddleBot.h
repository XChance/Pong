#ifndef PONG_PADDLEBOT_H
#define PONG_PADDLEBOT_H

#include "SFML/Graphics.hpp"
#include "Ball.h"

class PaddleBot {
public:
    PaddleBot();

    void update();

    void checkBallPos(Ball& ball);

    sf::RectangleShape paddleShape;

    float getX();
    float getY();

    int getWidth();
    int getHeight();

private:
    void move();

    sf::Vector2f pos;
    sf::Vector2f vel;

    const int width = 20, height = 140;

    bool isBallUp, isMoving;
};

#endif //PONG_PADDLEBOT_H
