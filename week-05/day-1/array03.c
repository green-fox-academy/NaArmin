#include <stdio.h>

char table[8][8];

void printtable();

int main(void)
{

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++){
            if ((i + j) % 2 == 0)
                table[i][j] = 'X';
            else
                table[i][j] = ' ';
        }
    }
    printtable();
    for (int i = 0; i < 8; i++) {
            table[1][i] = 'P';
            table[6][i] = 'P';
    }
    table[0][0] = table[7][0] = table[7][7] = table[0][7] = 'R';
    table[0][1] = table[0][6] = table[7][1] = table[7][6] = 'H';
    table[7][2] = table[7][5] = table[0][2] = table[0][5] = 'B';
    table[7][3] = table[0][4] = 'K';
    table[7][4] = table[0][3] = 'Q';
    printtable();
    table[5][2] = 'H';
    table[7][1] = ((7 + 1) % 2 == 0) ? 'X' : ' ';
    printtable();
    return 0;
}
void printtable()
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            printf("%c ", table[i][j]);
        printf("\n");
    }
    printf("\n");
}

