#include <stdio.h>
#include <string.h>
#include <windows.h>

void printboard(char **chboard);
void setup_board(char **chboard);

int main(void)
{
    char board[8][8];

    setup_board(board);
    printboard(board);
    return 0;
}
void printboard(char **chboard)
{
    system("cls");
    system("clear");
    printf("  ABCDEFGH\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 8; j++)
            printf("%c", chboard[i][j]);
        printf("\n");
    }
    printf("\n  abcdefgh\n\n");
    return;
}
void setup_board(char **chboard)
{
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++)
            chboard[i][j] = ' ';
    }
    for (int i = 0; i < 8; i++) {
        chboard[1][i] = 'p';
        chboard[6][i] = 'P';
    }
    chboard[0][0] = chboard[0][7] = 'r';
    chboard[7][0] = chboard[7][7] = 'R';
    chboard[0][1] = chboard[0][6] = 'h';
    chboard[7][1] = chboard[7][6] = 'H';
    chboard[0][2] = chboard[0][5] = 'b';
    chboard[7][2] = chboard[7][5] = 'B';
    chboard[0][3] = 'q';
    chboard[7][3] = 'Q';
    chboard[0][4] = 'k';
    chboard[7][4] = 'K';
    return;
}

