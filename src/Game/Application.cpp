#include "Application.h"

#include <string>
#include <iostream>

#include "../Managers/CollisionManager.h"

Application::Application(){
    renderWindow.create(sf::VideoMode(1280, 720), "Pong", sf::Style::Titlebar | sf::Style::Close);
    renderWindow.setVerticalSyncEnabled(true);
    renderWindow.setFramerateLimit(60);

    if(!font.loadFromFile("../res/Arial.ttf")){}

    playerScoreText = sf::Text(std::to_string(playerScore), font, 80);
    botScoreText = sf::Text(std::to_string(botScore), font, 80);

    pausedText0 = sf::Text("Paused", font, 60);
    pausedText1 = sf::Text("Press Esc to Unpause", font, 60);

    playerScoreText.setPosition(320, 20);
    botScoreText.setPosition(960, 20);

    pausedText0.setPosition(1280/2 - 100, 720/10);
    pausedText1.setPosition(1280/2 - 300, 720/5);

    midLine = sf::RectangleShape(sf::Vector2f(2, 720));
    midLine.setPosition(1280/2, 0);

    isPaused = true;

    ball = new Ball(renderWindow);
}

void Application::run() {
    sf::Event windowEvent;
    while (renderWindow.isOpen()) {
        if(!isPaused)
            update();
        render();

        while (renderWindow.pollEvent(windowEvent)) {
            if (windowEvent.type == sf::Event::Closed) {
                renderWindow.close();
            }
            if(windowEvent.type == (sf::Event::KeyPressed)) {
                if(windowEvent.key.code == sf::Keyboard::Escape) {
                    isPaused = !isPaused;
                }
            }
        }
    }

}

void Application::update() {
    ball->update();
    paddle.update();

    bot.checkBallPos(*ball);
    bot.update();

    checkCollision();
    checkReset();
    handleInput();

    updateText();
}

void Application::render() {
    renderWindow.clear(sf::Color(65, 70, 100));

    renderWindow.draw(midLine);

    renderWindow.draw(ball->ballShape);
    renderWindow.draw(paddle.paddleShape);
    renderWindow.draw(bot.paddleShape);

    renderWindow.draw(playerScoreText);
    renderWindow.draw(botScoreText);

    windowView = renderWindow.getDefaultView();
    renderWindow.setView(windowView);

    if(isPaused){
        renderWindow.draw(pausedText0);
        renderWindow.draw(pausedText1);
    }

    renderWindow.display();
}

void Application::checkCollision() {
    if(CollisionManager::collision(*ball, paddle)){
        sf::Vector2f temp = CollisionManager::newVel(*ball, paddle);
        ball->setVel(temp);
    }
    if(CollisionManager::collision(*ball, bot)){
        sf::Vector2f temp = CollisionManager::newVel(*ball, bot);
        ball->setVel(temp);
    }
}

void Application::checkReset() {
    if(!ball->getAlive()){
        reset();
    }
}

void Application::reset() {
    if(ball->getX() < 0){
        botScore++;
    }else{
        playerScore++;
    }

    delete(ball);
    ball = new Ball(renderWindow);
}

void Application::handleInput() {
    paddle.handleInput();
}

void Application::updateText() {
    playerScoreText.setString(std::to_string(playerScore));
    botScoreText.setString(std::to_string(botScore));
}

const sf::RenderWindow& Application::getWindow() const
{
    return renderWindow;
}

