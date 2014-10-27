Lab4
====
created by Austin Bolinger
ECE 382: Lab 4
Start Date: 26 Oct 14
Edited: 26 SEP 14
End Date: 26 SEP 14

Lab 4 is C. Using Code Composer's C functionality to program pong and Etch-a-Sketch on the LCD screen.

#Objective
In this lab, I will use C to create an etch-a-sketch-type program that utilizes some subroutines from Lab 3.

#Prelab

Was turned in via hand copy

###Required Functionality
(found in prelab4 folder)

Required Functionality is an Etch-a-Sketch. Using the given code from Dr. Coulston, I was able to make an Etch-a-Sketch. It used a cursor and drew everywhere the cursor went based on input from the up/down/left/right buttons. When the aux button was pushed the mode switched from paint to erase or black to clear.

###B Functionality
This part was designed to make a block bounce around the screen. I just took code that I created from lab 3 and modified it to work for drawing a block and moving a block on the LCD. I used the same code and just wrote code in main to call up nokia. 

###A Functionality
This functionality was one player pong. I used the same code from part B but also passed in code for the paddle's location. This allowed me to know where the ball and paddle was at the same time. If the ball went off the left screen, the game ends with a clear display. If the ball hits any of the other walls or the paddle, it bounces. The Aux button is a reset button.

###Bonus Functionality
My Bonus functionality was a reset button and invert functionality. Pressing the right button changes the screen from clear to black and the ball from black to clear.

#Hardware Schematic

![MSP430G2553](http://www.kerrywong.com/blog/wp-content/uploads/2012/03/MSP430G2ExtProg3.jpg?raw=true "MSP430G2553")

![MSP430G2553 Schematic](http://cnx.org/resources/485bbea47ead3338e654ae805f15bc09/graphics3.png?raw=true "MSP430G2553 Schematic")

#CODE
###Required Functionality Code
This code involved a little bit of modification. I took the given code and added an extra loop in drawblock. I allowed the color to be selected in main.c and recognized it with a register read in nokia. This compare register to true or false allowed me to select black or clear drawing. So either FF or 00 as the display data. In main.c I added the function for when the aux button was pressed. This function changed the color setting as true black or false clear each time the button was pressed.

My biggest problem was understanding how to read a register when adding a variable to the main.c's code. After that, it was minutes before I had the code working.

###B Functionality Code
B functionality involved me adding in the pong.c and pong.h files from lab 3. As far as those two files, I only changed the width and height and took out the radius of the block. Main.c was where the magic happened. I added lines of execution code to call up nokia and pong.h. Pong.h created my ball and main.c used pong.c to move the ball around. Nokia was responsible for drawing the location of the ball.

###A Functionality Code
A functionality was pretty similar to B. It moved a collision from pong.c and used end game to test if the ball went off the screen on the left. I also added a paddle variable to the pong.c code so that the ball knew where the paddle was for collisions. Nokia handled drawing the ball again. And, it used the same code to draw a paddle but that subroutine was called drawpaddle instead of draw ball. The difference was that the paddle was thinner than the ball. 

###Bonus Functionality Code
The first big change I preformed was moving the code for button pressing from outside the delay loops to inside the loops. This allows for quicker responses to what the users inputs. Instead of holding the button down for a second in order to time the button press right, the user can push the button and expect a response much quicker. The next part involved making a invert subroutine in nokia. I just copied the code from clear display  and made a black display subroutine. Next I made a variable in main that kept track of screen black or screen clear.

#Debugging/Testing
This coding was pretty straight forward and was broken into steps that were small and allowed for testing of small functions one at a time. The main learning from this code came from main.c when I had to realize what the computer was reading. For example, one problem I had was reading the while loop without a break ever. So it never drew my block. I had accidently rearrange the code to exclude the functions of drawing block after button pressed. 

#Results
The results involved a lot of code rearranging and slight modifications in order to manipulate it to get the desired output on the LCD.

#Documentation
NONE
