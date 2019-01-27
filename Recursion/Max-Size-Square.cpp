#include <iostream>

using namespace std;

#define ROW 6
#define COL 5

int getSquareSize(int matrix[ROW][COL], int squareSize, int rowIndex, int colIndex)
{
    if(squareSize - 1 + rowIndex >= ROW ||
       squareSize - 1 + colIndex >= COL)
        return squareSize - 1;
    for(int r = 0; r < squareSize; r ++)
    {
        for(int c = 0; c < squareSize; c ++)
        {
            if(matrix[rowIndex + r][colIndex + c] != 1)
            {
                return squareSize - 1;
            }
        }
    }
    return getSquareSize(matrix, squareSize + 1, rowIndex, colIndex);
}
void printTable(int table[ROW][COL])
{
    for(int i = 0; i < ROW; i ++)
    {
        for(int j = 0; j < COL; j ++)
        {
            cout << table[i][j] << " ";

        }
        cout << endl;
    }
    cout << endl;
}
void fillHashTable(int hashTable[ROW][COL], int squareSize, int rowIndex, int colIndex)
{
    for(int i = 0; i < squareSize; i ++)
        for(int j = 0; j < squareSize; j ++)
            hashTable[rowIndex + i][colIndex + j] = 1;
    printTable(hashTable);
}
int getSquareSizeUtil(int matrix[ROW][COL])
{
    int biggest_square = 0;
    int hashTable[ROW][COL] = {0};
    for(int i = 0; i < ROW; i ++)
    {
        for(int j = 0; j < COL; j ++)
        {
            if(matrix[i][j] == 1 && hashTable[i][j] == 0)
            {
                int current_square = getSquareSize(matrix, 2, i, j);
                if(current_square > biggest_square)
                    biggest_square = current_square;
                fillHashTable(hashTable, current_square, i, j);
            }
        }
    }
    return biggest_square;
}
int main()
{
    int matrix[ROW][COL] =  {{0, 1, 1, 0, 1},
                            {1, 1, 0, 1, 0},
                            {0, 1, 1, 1, 0},
                            {1, 1, 1, 1, 0},
                            {1, 1, 1, 1, 1},
                            {0, 0, 0, 0, 0}};
    cout << getSquareSizeUtil(matrix);
    return 0;
}
/*
{{1,1,1,1},
{1,0,1,1},
{1,1,1,1},
{1,1,1,1}};



*/
