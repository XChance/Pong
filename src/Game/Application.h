#ifndef PONG_APPLICATION_H
#define PONG_APPLICATION_H

#include <SFML/Graphics.hpp>
#include "../Entities/Ball.h"
#include "../Entities/Paddle.h"
#include "../Entities/PaddleBot.h"

class Application {
public:
    Application();

    void run();

    const sf::RenderWindow& getWindow() const;

private:
    void update();
    void render();
    void handleInput();

    void updateText();

    void checkCollision();

    void checkReset();
    void reset();

    int playerScore, botScore;
    bool isPaused;

    sf::RenderWindow renderWindow;

    sf::Font font;

    sf::Text playerScoreText;
    sf::Text botScoreText;

    sf::Text pausedText0;
    sf::Text pausedText1;

    sf::View windowView;

    sf::RectangleShape midLine;

    Paddle paddle;
    PaddleBot bot;

    Ball *ball;
};

#endif //PONG_APPLICATION_H