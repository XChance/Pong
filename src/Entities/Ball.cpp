#include "Ball.h"

#include <iostream>

Ball::Ball(sf::RenderWindow& rw){
    windowWidth = rw.getSize().x, windowHeight = rw.getSize().y;

    pos.x = 1280/2 - ballSize, pos.y = 720/2 - ballSize/2;
    setVel();

    ballColor = sf::Color::White;
    ballShape = sf::CircleShape(ballSize);
    ballShape.setFillColor(ballColor);
    ballShape.setPosition(pos);

    if(!buffer.loadFromFile("../res/PONG_BOUNCE.wav")){}
    bounce.setBuffer(buffer);
    bounce.setVolume(80);

    isAlive = true;
}

void Ball::update() {
    move();
    checkAlive();
}

void Ball::move() {
    if(ballShape.getPosition().y > windowHeight - ballSize * 2 || ballShape.getPosition().y < 0){
        playSound();
        vel.y = -vel.y;
        pos.y += vel.y;
    }

    pos += vel;

    ballShape.setPosition(pos);
}

void Ball::setVel() {
    int temp = std::rand() % 4 + 1;

    if(temp == 1){
        vel.x = (rand() % 5 + 8);
        vel.y = (rand()% 5 + 8);
    }else if(temp == 2){
        vel.x = -(rand() % 5 + 8);
        vel.y = -(rand()% 5 + 8);
    }else if(temp == 3){
        vel.x = -(rand() % 5 + 8);
        vel.y = (rand()% 5 + 8);
    }else {
        vel.x = (rand() % 5 + 8);
        vel.y = -(rand() % 5 + 8);
    }
}

void Ball::checkAlive() {
    if(ballShape.getPosition().x > windowWidth + ballSize){
        isAlive = false;
    }

    if(ballShape.getPosition().x < -ballSize * 2){
        isAlive = false;
    }
}

void Ball::playSound(){
    if(bounce.getStatus() != sf::Sound::Status::Playing){
        bounce.play();
    }
}

//getters / setters

void Ball::setVel(sf::Vector2f &vel) {
    playSound();
    this->vel.x = vel.x;
    this->vel.y = vel.y;
}

float Ball::getX() {
    return pos.x;
}

float Ball::getY() {
    return pos.y;
}

bool Ball::getAlive() {
    return isAlive;
}