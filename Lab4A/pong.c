/*
 * collision_detection.c
 *
 *  Created on: Oct 9, 2014
 *      Author: C16Austin.Bolinger
 */

#include "pong.h"

int collisionX(int x, int xVel, int y, int yPaddle) {
	if (x >= WIDTH) { //left and right bounds
		return 1;
	} else if (x == 0 && (y == yPaddle || y == yPaddle + 1)) {
		return 1;
	} else {
		return 0;
	}
}
int collisionY(int y, int yVel) {
	if (y <= 0 || y >= HEIGHT) { //up and down bounds
		return 1;
	} else {
		return 0;
	}
}

ball createBall(int x, int y, int xVel, int yVel, int color, int yPaddle) {
	ball my_ball;
	my_ball.x = x;
	my_ball.y = y;
	my_ball.xVel = xVel;
	my_ball.yVel = yVel;
	my_ball.color = color;
	my_ball.yPaddle = yPaddle;
	return my_ball;
}

ball moveBall(ball my_ball) {
	if (endGame(my_ball.x, my_ball.y, my_ball.yPaddle, my_ball.color)) {
		my_ball.color = 2;
	}
	if (collisionX(my_ball.x, my_ball.xVel, my_ball.y, my_ball.yPaddle)) {
		my_ball.xVel = -my_ball.xVel;
	}
	if (collisionY(my_ball.y, my_ball.yVel)) {
		my_ball.yVel = -my_ball.yVel;
	}

	my_ball.x = my_ball.x + my_ball.xVel;
	my_ball.y = my_ball.y + my_ball.yVel;
	return my_ball;
}

int endGame(int x, int y, int yPaddle, int color) {
	if (x < 0) {
		return 1;
	} else {
		return 0;
	}
}
