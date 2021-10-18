#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;
typedef struct Matrix Matrix;

struct Node
{
    int info;
    int rowIndex;
    int colIndex;
    Node *next; // Next Column
    Node *down; // Next Row
};

struct Matrix
{
    int totalRows;
    int totalColumns;
    Node **rowPtr;
    Node **colPtr;
};

void createMatrix(Matrix *mx, int totalRows, int totalColumns);
void insertNode(Matrix *matrix, int rowIndex, int colIndex, int nonZeroValue);
int deleteNode(Matrix *matrix, int rowIndex, int colIndex);
void assingInfo(Matrix *matrix, int rowIndex, int colIndex, int nonZeroValue);
int readNode(Matrix *matrix, int rowIndex, int colIndex);
void Sum();
void Product();

int main()
{
    printf("Sparse Matrix Project 1.1.0\n");

    Matrix sparceMatrix;

    createMatrix(&sparceMatrix, 3, 3);


    return 0;
}


void createMatrix(Matrix *mx, int totalRows, int totalColumns)
{
    mx->totalRows = totalRows;
    mx->totalColumns = totalColumns;
    mx->rowPtr = (Node **)calloc(1, (sizeof(Node) * totalRows));
    mx->colPtr = (Node **)calloc(1, (sizeof(Node) * totalColumns));

    // initialize head rows
    for (int i = 0; i <= totalRows; i++)
        mx->rowPtr[i] = (Node *)calloc(1, sizeof(Node));
    
    // point header rows to next node
    for (int i = 0; i <= totalRows; i++)
    {
        if(i == totalRows) // the last pointer come back to the first
        {
            mx->rowPtr[i]->rowIndex = i;
            mx->rowPtr[i]->down = mx->rowPtr[0];
        }
        else
        {
            mx->rowPtr[i]->rowIndex = i;
            mx->rowPtr[i]->down = mx->rowPtr[i + 1];
        }
    }

    // initialize head columns
    for (int i = 0; i <= totalColumns; i++)
        mx->colPtr[i] = (Node *)calloc(1, sizeof(Node));

    // point header columns to next node
    for (int i = 0; i <= totalColumns; i++)
    {
        if(i == totalColumns) // the last pointer come back to the first
        {
            mx->colPtr[i]->colIndex = i;
            mx->colPtr[i]->next = mx->colPtr[0];
        }
        else
        {
            mx->colPtr[i]->colIndex = i;
            mx->colPtr[i]->next = mx->colPtr[i + 1];
        }
    }

    return;
}


