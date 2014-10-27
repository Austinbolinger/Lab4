/*
 * collision_detection.c
 *
 *  Created on: Oct 9, 2014
 *      Author: C16Austin.Bolinger
 */

#include "pong.h"

int collisionX(int x, int xVel) {
	if (x <= 0 || x >= WIDTH) { //left and right bounds
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

ball createBall(int x, int y, int xVel, int yVel) {
	ball my_ball;
	my_ball.x = x;
	my_ball.y = y;
	my_ball.xVel = xVel;
	my_ball.yVel = yVel;
	return my_ball;
}

ball moveBall(ball my_ball) {
	if (collisionX(my_ball.x, my_ball.xVel)) {
		my_ball.xVel = -my_ball.xVel;
	}
	if (collisionY(my_ball.y, my_ball.yVel)) {
		my_ball.yVel = -my_ball.yVel;
	}
	my_ball.x = my_ball.x + my_ball.xVel;
	my_ball.y = my_ball.y + my_ball.yVel;
	return my_ball;
}

