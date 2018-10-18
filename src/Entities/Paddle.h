#ifndef PONG_PADDLE_H
#define PONG_PADDLE_H

#include "SFML/Graphics.hpp"

class Paddle {
public:
    Paddle();

    void update();
    void handleInput();

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

    bool isUp, isMoving;
};

#endif //PONG_PADDLE_H