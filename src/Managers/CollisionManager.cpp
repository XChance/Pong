#include "CollisionManager.h"
#include <math.h>

bool CollisionManager::collision(Ball &ball, Paddle &paddle) {
    if (ball.getX() <= paddle.getX() + paddle.getWidth() && ball.getX() >= paddle.getX()
            && ball.getY() >= paddle.getY() - 15 && ball.getY() <= paddle.getY() + paddle.getHeight() + 15) {
        return true;
    } else {
        return false;
    }
}

sf::Vector2f CollisionManager::newVel(Ball &ball, Paddle &paddle) {
        float relativeIntersectY = (paddle.getY() +(paddle.getHeight()/2)) - ball.getY();

        float normalizedRelativeIntersectionY = (relativeIntersectY/(paddle.getHeight()/2));
        float bounceAngle = normalizedRelativeIntersectionY *  1.0472;

        float ballxVel = 19 * cos(bounceAngle);
        float ballyVel = 19 * -sin(bounceAngle);

        return {ballxVel, ballyVel};
    }

bool CollisionManager::collision(Ball &ball, PaddleBot &bot) {
    if (ball.getX() >= bot.getX() && ball.getX() <= bot.getX() + bot.getWidth()
        && ball.getY() >= bot.getY() && ball.getY() <= bot.getY() + bot.getHeight()) {
        return true;
    } else {
        return false;
    }
}

sf::Vector2f CollisionManager::newVel(Ball &ball, PaddleBot &bot) {
    float relativeIntersectY = (bot.getY() +(bot.getHeight()/2)) - ball.getY();

    float normalizedRelativeIntersectionY = (relativeIntersectY/(bot.getHeight()/2));
    float bounceAngle = normalizedRelativeIntersectionY *  1.0472;

    float ballxVel = 19 * -cos(bounceAngle);
    float ballyVel = 19 * -sin(bounceAngle);

    return {ballxVel, ballyVel};
}