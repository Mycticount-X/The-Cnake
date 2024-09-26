#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define HEIGHT 20
#define WIDTH 20

int x, y, appleX, appleY, score, gameover;
int tailX[100], tailY[100];
int tailLen;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum eDirection dir;

// Setup
void setup () {
	gameover = 0;
	dir = STOP;
	x = HEIGHT / 2;
	y = WIDTH / 2;
	appleX = rand() % WIDTH;
	appleY = rand() % HEIGHT;
	score = 0;
}

// Area Permainan
void screen () {
	system("cls");
	
	printf(" ");
	for (int i = 0; i < WIDTH + 2; i++) {
		printf("#");
	}
	printf("\n");
	
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (j == 0) printf(" #");
			
			if (i == appleY && j == appleX) printf("*"); // Apple
			else if (i == y && j == x) printf("O"); // Kepala Ular
			else {
                int print = 0;
                for (int k = 0; k < tailLen; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o"); // Snake tail
                        print = 1;
                    }
                }
                if (!print)
                    printf(" ");
            }
			if (j == WIDTH - 1)
                printf("#");
        }
        printf("\n");
		
		
	}
	printf(" ");
	for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    printf(" Score: %d\n", score);
}

// Game Over
void screen_gameover () {
	// ASCII Art for "GAME OVER"
    printf("\n");
    printf("  #####     #    #     # #######    ####### #     # ####### ######  \n");
    printf(" #     #   # #   ##   ## #          #     # #     # #       #     # \n");
    printf(" #        #   #  # # # # #          #     # #     # #       #     # \n");
    printf(" #  #### #     # #  #  # #####      #     # #     # #####   ######  \n");
    printf(" #     # ####### #     # #          #     #  #   #  #       #   #   \n");
    printf(" #     # #     # #     # #          #     #   # #   #       #    #  \n");
    printf("  #####  #     # #     # #######    #######    #    ####### #     # \n");
    printf("\n");

    printf("\n");
    printf(" === Game Over! ===\n Final Score: %d\n", score);
    printf(" Credit: Mycticount Xeta Ahlovely");
    
    
}

// Input WASD
void input () {
	if (_kbhit()) {
		switch (_getch()) {
			case 'w':
				if (dir != DOWN)
					dir = UP;
				break;
			case 'a':
				if (dir != RIGHT)
					dir = LEFT;
				break;
			case 's':
				if (dir != UP)
					dir = DOWN;
				break;
			case 'd':
				if (dir != LEFT)
					dir = RIGHT;
				break;
		}
	}
}

// Mekanisme Dunia
void logic () {
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < tailLen; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
	}
	
	switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    
    // Batasan
    if (x >= WIDTH) x = 0; else if (x < 0) x = WIDTH - 1;
    if (y >= HEIGHT) y = 0; else if (y < 0) y = HEIGHT - 1;

    for (int i = 0; i < tailLen; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameover = 1;
    }

    if (x == appleX && y == appleY) {
        score += 10;
        appleX = rand() % WIDTH;
        appleY = rand() % HEIGHT;
        tailLen++;
    }
}



int main () {
	srand(time(0));
	setup();
	while (!gameover) {
		screen();
		input();
		logic();
		Sleep(100);
	}
	
	system ("cls");
	screen_gameover();
	return 0;
}
