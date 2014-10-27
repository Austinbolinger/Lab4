#include <msp430g2553.h>
#include "pong.h"

extern void init();
extern void initNokia();
extern void clearDisplay();
extern void drawBlock(unsigned char row, unsigned char col, unsigned char color);
extern void delay_20ms();
extern void drawPaddle(unsigned char yPaddle, unsigned char xPaddle,
		unsigned char color);
extern void blackDisplay();

#define		TRUE			1
#define		FALSE			0
#define		UP_BUTTON		(P2IN & BIT5)
#define		DOWN_BUTTON		(P2IN & BIT4)
#define		AUX_BUTTON		(P2IN & BIT3)
#define		LEFT_BUTTON		(P2IN & BIT2)
#define		RIGHT_BUTTON	(P2IN & BIT1)

void main() {

	unsigned int x, y, xPaddle, yPaddle, button_press, color, screen;

	// === Initialize system ================================================
	IFG1 = 0; /* clear interrupt flag1 */
	WDTCTL = WDTPW + WDTHOLD; /* stop WD */
	button_press = FALSE;

	init();
	initNokia();
	clearDisplay();
	x = 1;
	y = 1;
	color = 1;
	xPaddle = 0;
	screen = 0;

	drawBlock(y, x, color);

	static ball your_ball = { 2, 2, 1, 1, 1, 0 }; //create a ball

	while (1) {

		int i;
		int j;
		for (i = 0; i < 4; i++) { //delay
			//delay_20ms();
			for (j = 0; j < 16000; j++) {
				if (UP_BUTTON == 0) {
					while (UP_BUTTON == 0)
						;
					if (your_ball.yPaddle >= 1)
						your_ball.yPaddle = your_ball.yPaddle - 1;
					button_press = TRUE;
				} else if (DOWN_BUTTON == 0) {
					while (DOWN_BUTTON == 0)
						;
					if (your_ball.yPaddle <= 5)
						your_ball.yPaddle = your_ball.yPaddle + 1;
					button_press = TRUE;
				}

				else if (LEFT_BUTTON == 0) {
					while (LEFT_BUTTON == 0)
						;
					if (screen) {
						screen = FALSE;
					} else {
						screen = TRUE;
					}
				}

				else if (AUX_BUTTON == 0) {
					while (AUX_BUTTON == 0)
						;
					your_ball.y = 2;
					your_ball.x = 2;
					your_ball.yVel = 1;
					your_ball.xVel = 1;
					your_ball.color = 1;

					button_press = TRUE;
				}
				if (button_press) {
					button_press = FALSE;
					clearDisplay();
					drawBlock(your_ball.y, your_ball.x, color);
					drawPaddle(your_ball.yPaddle, xPaddle, color);
					drawPaddle(your_ball.yPaddle + 1, xPaddle, color);
				}

			}

		}

		clearDisplay();

		your_ball = moveBall(your_ball);

		if (your_ball.color == 2) {
			while (1) {
				clearDisplay();
				if (AUX_BUTTON == 0) {
					while (AUX_BUTTON == 0)
						;
					your_ball.y = 2;
					your_ball.x = 2;
					your_ball.yVel = 1;
					your_ball.xVel = 1;
					your_ball.color = 1;

					button_press = TRUE;
					break;
				}
			}
		}

		if (screen == 1) {
			color = 0;
			blackDisplay();
		} else {
			color = 1;
		}

		drawBlock(your_ball.y, your_ball.x, color);
		drawPaddle(your_ball.yPaddle, xPaddle, color);
		drawPaddle(your_ball.yPaddle + 1, xPaddle, color);

	}
}
