#include "PaddleBot.h"

PaddleBot::PaddleBot() {
    paddleShape = sf::RectangleShape(sf::Vector2f(width, height));
    paddleShape.setPosition(pos.x = 1260 - width, pos.y = 360 - height);

    vel = sf::Vector2f(0, 9);
}

void PaddleBot::update() {
    if(isMoving)
        move();
}

void PaddleBot::move() {
    if(isBallUp){
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

void PaddleBot::checkBallPos(Ball &ball) {
    if(pos.y + height/2 - 48 >= ball.getY()){
        isBallUp = true;
        isMoving = true;
    }else if(pos.y + height/2 + 48 <= ball.getY()) {
        isBallUp = false;
        isMoving = true;
    }else{
        isMoving = false;
    }

    if(ball.getX() >= 1280/4){
        isMoving = true;
    }else{
        isMoving = false;
    }

}

//getters & setters

float PaddleBot::getX() {
    return pos.x;
}

float PaddleBot::getY() {
    return pos.y;
}

int PaddleBot::getWidth() {
    return width;
}

int PaddleBot::getHeight() {
    return height;
}