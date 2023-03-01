/* William Amador and Moises Romero
       Programming Project
             CS110                 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 50
#define HEIGHT 20

void gameover(char* name, int score);
void updgamegrid(char* name, int score);

int main() {
  // Declaring variables
  char name[20];
  int paddlePos = WIDTH / 2 - 2, ballX = WIDTH / 2, ballY = HEIGHT - 5;
  int dx = 1, dy = -1, score = 0, bricksLeft = 30;
  int i, j;
  int paddleLength = 5;
  char grid[HEIGHT][WIDTH];

// Create the game map
for (i = 0; i < HEIGHT; i++) {
  for (j = 0; j < WIDTH; j++) {
    if (i == 0 || j == 0 || i == HEIGHT - 1 || j == WIDTH - 1) {
      grid[i][j] = '#';
    } else if (i == HEIGHT - 2 && j >= paddlePos && j <= paddlePos + paddleLength - 1) {
      grid[i][j] = '=';
    } else if (i < 4 && j > 4 && j < WIDTH - 5 && (i + j) % 2 == 0) {
      grid[i][j] = '_';
      bricksLeft++;
    } else {
      grid[i][j] = ' ';
    }
  }
}

  // Placing the ball on map
  grid[ballY][ballX] = '0';

  // Print pre-game lobby
  system("cls");
  printf("Primo's Breakout Game\n");
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }

  // Primo's name
  printf("\nEnter your name: ");
  scanf("%s", name);

  // Start the game loop
  while (bricksLeft > 0) {
    // Move the ball
    ballX += dx;
    ballY += dy;

    // Check for collisions with walls and paddle
    if (ballX == 1 || ballX == WIDTH - 2) {
      dx = -dx;
    }
    if (ballY == 1) {
      dy = -dy;
    } else if (ballY == HEIGHT - 2 && ballX >= paddlePos && ballX <= paddlePos + 4) {
      dy = -dy;
      score += 0;
    } else if (ballY == HEIGHT - 2) {
      break;
    }

    // Check for collisions with bricks
if (grid[ballY][ballX] == '_') { // Check if the ball hits a brick
  grid[ballY][ballX] = ' '; // Remove the brick
  bricksLeft--;
  score += 10;
  if (ballY == 0 || ballY == HEIGHT - 1) {
    dy = -dy;
  } else {
    if (dy < 0) { // Ball is moving upwards
      dy = -dy; // Change direction
    } else { 
      dx = -dx; 
    }
  }
}

// Move the paddle
if (kbhit()) {
  char key = getch();
  if (key == 'a' && paddlePos > 1) {
    paddlePos--;
  } else if (key == 'd' && paddlePos < WIDTH - paddleLength - 1) {
    paddlePos++;
  } else if (key == '-' && paddleLength > 1) {
    paddleLength--;
  } else if (key == '+' && paddleLength < WIDTH - paddlePos - 1) {
    paddleLength++;
  }

  // Ensure paddle won't go out of the map
  if (paddlePos < 1) {
    paddlePos = 1;
  } else if (paddlePos > WIDTH - paddleLength - 1) {
    paddlePos = WIDTH - paddleLength - 1;
  }
}


   // Update the game grid
for (i = 0; i < HEIGHT; i++) {
  for (j = 0; j < WIDTH; j++) {
    if (i == HEIGHT - 2 && j >= paddlePos && j < paddlePos + paddleLength) {
      grid[i][j] = '=';
    } else if (i == ballY && j == ballX) {
      grid[i][j] = 'O';
    } else if (i == 0 || j == 0 || i == HEIGHT - 1 || j == WIDTH - 1) {
      grid[i][j] = '#';
    } else if (grid[i][j] == '_') {
      grid[i][j] = '_';
    } else {
      grid[i][j] = ' ';
    }
  }
}


// Print the updated game grid
system("cls");
printf("Primo's Breakout Game\n");
printf("Player: %s\n", name);
printf("Score: %d\n", score);
for (i = 0; i < HEIGHT; i++) {
  for (j = 0; j < WIDTH; j++) {
    printf("%c", grid[i][j]);
  }
  printf("\n");
}

// Wait
Sleep(50);
}

// Game over
	system("cls");
	gameover(name, score);
return 0;
}
void gameover(char* name, int score)
{
printf("Game over!\n");
printf("Player: %s\n", name);
printf("Score: %d\n", score);
}

void updgamegrid(char* name, int score)
{
printf("Primo's Breakout Game\n");
printf("Player: %s\n", name);
printf("Score: %d\n", score);
}
