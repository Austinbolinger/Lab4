/*
 * collision_detection.h
 *
 *  Created on: Oct 9, 2014
 *      Author: C16Austin.Bolinger
 */

#ifndef PONG_H_
#define PONG_H_

#define WIDTH 11
#define HEIGHT 7

typedef struct ball{// a ball structure or object
    int x;
    int y;
    int xVel;
    int yVel;
    int yPaddle;
    int color;
}ball;

 ball createBall(int x, int y, int xVel, int yVel, int color, int yPaddle);

 ball moveBall(ball my_ball);

 int collisionX(int x, int xVel,int y, int yPaddle);
 int collisionY(int y, int yVel);
 int endGame(int x, int y, int yPaddle, int color);

#endif /* COLLISION_DETECTION_H_ */
