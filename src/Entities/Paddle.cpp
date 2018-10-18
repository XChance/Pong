#include "Paddle.h"

Paddle::Paddle() {
    paddleShape = sf::RectangleShape(sf::Vector2f(width, height));
    paddleShape.setPosition(pos.x = 20, pos.y = 360 - height);

    vel = sf::Vector2f(0, 9);
}

void Paddle::update() {
    if(isMoving)
        move();
}

void Paddle::move() {
    if(isUp) {
        pos.y -= vel.y;
    }else{
        pos.y += vel.y;
    }

    if(pos.y < 0){
        pos.y = 0;
    }else if(pos.y > 720 - height){
        pos.y = 720 - height;
    }

    paddleShape.setPosition(pos);
}

void Paddle::handleInput() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        isUp = true;
        isMoving = true;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        isUp = false;
        isMoving = true;
    }else{
        isMoving = false;
    }
}

//getters & setters

float Paddle::getX() {
    return pos.x;
}

float Paddle::getY() {
    return pos.y;
}

int Paddle::getWidth() {
    return width;
}

int Paddle::getHeight() {
    return height;
}