#ifndef PONG_BALL_H
#define PONG_BALL_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>

class Ball {

public:
    Ball(sf::RenderWindow& rw);

    void update();

    sf::CircleShape ballShape;

    float getX();
    float getY();

    void setVel(sf::Vector2f& vel);

    bool getAlive();

private:
    void move();
    void checkAlive();
    void setVel();
    void playSound();

    sf::Color ballColor;

    sf::Vector2f pos;
    sf::Vector2f vel;

    sf::SoundBuffer buffer;
    sf::Sound bounce;

    int windowWidth, windowHeight;

    bool isAlive;

    const int ballSize = 10;

};

#endif //PONG_BALL_H