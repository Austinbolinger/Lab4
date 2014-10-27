#include <msp430g2553.h>
#include "pong.h"

extern void init();
extern void initNokia();
extern void clearDisplay();
extern void drawBlock(unsigned char row, unsigned char col, unsigned char color);
extern void delay_20ms();

#define		TRUE			1
#define		FALSE			0
#define		WIDTH			11
#define		HEIGHT			8
#define		UP_BUTTON		(P2IN & BIT5)
#define		DOWN_BUTTON		(P2IN & BIT4)
#define		AUX_BUTTON		(P2IN & BIT3)
#define		LEFT_BUTTON		(P2IN & BIT2)
#define		RIGHT_BUTTON	(P2IN & BIT1)

void main() {

	unsigned char x, y, button_press, color;

	// === Initialize system ================================================
	IFG1 = 0; /* clear interrupt flag1 */
	WDTCTL = WDTPW + WDTHOLD; /* stop WD */
	button_press = FALSE;

	init();
	initNokia();
	clearDisplay();
	x = 5;
	y = 4;
	color = 1;
	drawBlock(y, x, color);

	static ball your_ball = { 1, 1, 1, 1 }; //create a ball

	while (1) {

		int i;
		int j;
		for (i = 0; i < 500; i++) { //delay
			//delay_20ms();
			for (j = 0; j < 1279; j++)
				;
		}

		clearDisplay();

		your_ball = moveBall(your_ball); //move ball forever
		drawBlock(your_ball.y, your_ball.x, color);

		if (AUX_BUTTON == 0) {
			while (AUX_BUTTON == 0)
				;
			your_ball.y = 4;
			your_ball.x = 5;
			your_ball.yVel = 1;
			your_ball.xVel = 1;
			drawBlock(your_ball.y, your_ball.x, color);

			button_press = TRUE;
		}

		if (button_press) {
			button_press = FALSE;
		}
	}
}
