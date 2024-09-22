#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// Ukuran Grid
#define WIDTH 20
#define HEIGHT 20

// Arah pergerakan ular
enum Direction { UP, DOWN, LEFT, RIGHT };
enum Direction dir;

// Koordinat & Tambahan
int x,y;
int fruitX, fruitY;

int tailX[100], tailY[100];
int tail_Len;

int score;


// Setup awal game
void setup () {
	dir = RIGHT; // Mulai dengan arah ke kanan
    x = WIDTH / 2;
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score = 0;
    tail_Len = 0;
}


// Gambar Grid
void gambar() {
    system("cls"); // Membersihkan layar
	
	int i, j;
	
    // Gambar batas atas
    for (int i = 0; i < WIDTH + 2; i++) {
		printf("#");
	}
    	
    printf("\n");

    // Gambar area permainan
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0) printf("#"); // Batas kiri

            if (i == y && j == x) {
                printf("O"); // Kepala ular
            } else if (i == fruitY && j == fruitX) {
                printf("F"); // Buah
            } else {
                int isTail = 0;
                for (int k = 0; k < tail_Len; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o"); // Ekor ular
                        isTail = 1;
                    }
                }
                if (!isTail) printf(" "); // Ruang kosong
            }

            if (j == WIDTH - 1) printf("#"); // Batas kanan
        }
        printf("\n");
    }

    // Gambar batas bawah
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

    printf("Score: %d\n", score);
}


// Input
void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
        }
    }
}


// Mengupdate logika permainan
void logika() {
    // Menyimpan posisi ekor sebelumnya
    if (tail_Len > 0) {
        int prevX = tailX[0];
        int prevY = tailY[0];
        int prev2X, prev2Y;
        tailX[0] = x;
        tailY[0] = y;
        for (int i = 1; i < tail_Len; i++) {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
}
}

    // Menggerakkan kepala ular
    switch (dir) {
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
    }

    // Memeriksa apakah ular bertabrakan dengan batas
    if (x >= WIDTH) x = 0; else if (x < 0) x = WIDTH - 1;
    if (y >= HEIGHT) y = 0; else if (y < 0) y = HEIGHT - 1;

    // Memeriksa apakah ular memakan buah
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        tail_Len++;
    }

    // Memeriksa apakah ular bertabrakan dengan ekornya sendiri
    for (int i = 0; i < tail_Len; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            printf("Game Over!\n");
            exit(0);
        }
    }
}

int main() {
	setup();
	
	while (1) {
		gambar();
		input();
		logika();
		Sleep(100);
	}
	return 0;
}
