#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <math.h>

void printboard(char chboard[][8]);
void setup_board(char chboard[][8]);
int chkmove_peasant(char chboard[][8], int rowfrom, int columnfrom, int rowto, int columnto);
int chkmove_horse(char chboard[][8], int rowfrom, int columnfrom, int rowto, int columnto);
int motion(char chboard[][8], int rowfrom, int columnfrom, int rowto, int columnto);

int main(void)
{
    char cmd[6];
    char board[8][8];
    int rwfr, colfr, rwto, colto;

    setup_board(board);
    printboard(board);
    printf("Type movenemt in a format like 'a2a3'! ");
    gets(cmd);
    rwfr = cmd[1] - 49;
    rwto = cmd[3] - 49;
    colfr = cmd[0] - 97;
    colto = (int)cmd[2] - 97;
    if (motion(board, rwfr, colfr, rwto, colto))
        puts("Invalid movement!");
    return 0;
}
void printboard(char chboard[][8])
{
    system("cls");
    system("clear");
    printf("  abcdefgh\n\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 8; j++)
            printf("%c", chboard[i][j]);
        printf(" %d\n", i + 1);
    }
    printf("\n  ABCDEFGH\n\n");
    return;
}
void setup_board(char chboard[][8])
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
int chkmove_peasant(char chboard[][8], int rowfrom, int columnfrom, int rowto, int columnto)
{
    if (abs(rowfrom - rowto) > 2 || abs(columnfrom - columnto) > 1)
        return -1;
    if (chboard[rowfrom][columnfrom] == 'p' && rowto - rowfrom == 2 && rowfrom == 1)
        return 0;
    if (chboard[rowfrom][columnfrom] == 'p' && (rowto - rowfrom > 1 || rowto - rowfrom < 0))
        return -1;
    if (chboard[rowfrom][columnfrom] == 'P' && rowfrom - rowto == 2 && rowfrom == 6)
        return 0;
    if (chboard[rowfrom][columnfrom] == 'P' && (rowfrom - rowto > 1 || rowfrom - rowto < 0))
        return -1;
    if (columnfrom == columnto && chboard[rowto][columnto] != ' ')
        return -1;
    return 0;
}
int chkmove_horse(char chboard[][8], int rowfrom, int columnfrom, int rowto, int columnto)
{
    if (abs(rowfrom - rowto) == 1 && abs(columnfrom - columnto) == 2)
        return 0;
    if (abs(rowfrom - rowto) == 2 && abs(columnfrom - columnto) == 1)
        return 0;
    return -1;
}
int motion(char chboard[][8], int rowfrom, int columnfrom, int rowto, int columnto)
{
    if (rowfrom)
    if (chboard[rowfrom][columnfrom] > 64 && chboard[rowfrom][columnfrom] < 91)
            if (chboard[rowto][columnto] > 64 && chboard[rowto][columnto] < 91)
                return -1;
    if (chboard[rowfrom][columnfrom] > 96 && chboard[rowfrom][columnfrom] < 123)
            if (chboard[rowto][columnto] > 96 && chboard[rowto][columnto] < 123)
                return -1;
    switch (chboard[rowfrom][columnfrom]) {
    case 'p':
    case 'P':
        if (chkmove_peasant(chboard, rowfrom, columnfrom, rowto, columnto) != 0) {
            return -1;
        } else {
            chboard[rowto][columnto] = chboard[rowfrom][columnfrom];
            chboard[rowfrom][columnfrom] = ' ';
        }
        break;
    case 'h':
    case 'H':
        if (chkmove_horse(chboard, rowfrom, columnfrom, rowto, columnto) != 0) {
            return -1;
        } else {
            chboard[rowto][columnto] = chboard[rowfrom][columnfrom];
            chboard[rowfrom][columnfrom] = ' ';
        }
        break;
    case 'r':
    case 'R':
        chboard[rowto][columnto] = chboard[rowfrom][columnfrom];
        chboard[rowfrom][columnfrom] = ' ';
        break;
    case 'b':
    case 'B':
        chboard[rowto][columnto] = chboard[rowfrom][columnfrom];
        chboard[rowfrom][columnfrom] = ' ';
        break;
    case 'k':
    case 'K':
        chboard[rowto][columnto] = chboard[rowfrom][columnfrom];
        chboard[rowfrom][columnfrom] = ' ';
        break;
    case 'q':
    case 'Q':
        chboard[rowto][columnto] = chboard[rowfrom][columnfrom];
        chboard[rowfrom][columnfrom] = ' ';
        break;
    default:
        return -1;
    }
    printboard(chboard);
    return 0;
}
