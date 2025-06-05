#include <stdio.h>
#include <stdlib.h>
#include "ControlesDaTela.cpp"
#include <time.h>

void main() {
    int tecla, move = 60;
    int posAnterior = move;
    int tiroX = 0, tiroY = -1;
    int x, y;
    int lin, col;

    system("cls");
    srand(time(NULL));

    DesligaCursor();
    gotoxy(move, 28);
    printf("\x1E");

    while (1) {
        if (kbhit()) {
            tecla = getch();

            switch (tecla) {
                case 77:
                    move += 2;
                    if (move > 80)
                        move = 80;
                    break;

                case 75:
                    move -= 2;
                    if (move < 20)
                        move = 20;
                    break;

                case 32:
                    if (tiroY < 0) {
                        tiroX = move;
                        tiroY = 27;
                    }
                    break;

                default:
                    break;
            }
        }

        if (tiroY >= 0) {
            if (tiroY < 28) {
                gotoxy(tiroX, tiroY);
                printf("   ");
            }

            tiroY--;
            if (tiroY >= 0) {
                gotoxy(tiroX, tiroY);
                printf(" || ");
            }
        }

        if (move != posAnterior) {
            gotoxy(posAnterior, 28);
            printf(" ");
            gotoxy(move, 28);
            printf("\x1E");
            posAnterior = move;
        }

        if (rand() % 10 == 0) { // inimigos aparecem com menos frequência
            do {
                x = rand() % 61 + 20; // intervalo de 20 a 80
                y = rand() % 20 + 2;
            } while (y >= 26);

            gotoxy(x, y);
            printf("\x02");
        }
        Cor(0x99);
        for(lin=0;lin<19;lin++)
        {
        	for(col=0;col<29;col++)
        	{
        		gotoxy(lin,col);
        		printf("\xDB");	
			}
		}
		Cor(0xF0);
        Sleep(40);
    }
}
