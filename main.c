#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Matrix Matrix;

struct Node
{
    int info;
    int rowIndex;
    int colIndex;
    Node *nextColumn; // Next Column
    Node *nextRow; // Next Row
};

struct Matrix
{
    int totalRows;
    int totalColumns;
    int totalElements;
    int currentElements;
    Node **rowPtr;
    Node **colPtr;
};

void createMatrix(Matrix *mx, int totalRows, int totalColumns);
void insertNode(Matrix *mx, int rowIndex, int colIndex, int nonZeroValue);
int deleteNode(Matrix *mx, int rowIndex, int colIndex);
void assingInfo(Matrix *mx, int rowIndex, int colIndex, int nonZeroValue);
int readNode(Matrix *mx, int rowIndex, int colIndex);
void Sum();
void Product();

int main()
{
    printf("Sparse Matrix Project v1.1.0\n");

    Matrix sparceMatrix;

    createMatrix(&sparceMatrix, 3, 3);

    insertNode(&sparceMatrix, 1, 1, 3);
    insertNode(&sparceMatrix, 1, 3, 2);
    insertNode(&sparceMatrix, 2, 1, -1);
    insertNode(&sparceMatrix, 3, 3, 5);

    //Uncomment when everything works correctly
    /*
    int option = 0;
    int rows, columns, rowIndex, columnIndex, nonZeroValue;
    int deletedValue, readValue, sumValue, productValue;

    while (option != 9)
    {
        
        printf("\n\n1. Create a new matrix.\n");
        printf("2. Insert a node given its row and column.\n");
        printf("3. Delete a node given its row and column.\n");
        printf("4. Assign a new value at a given row and column.\n");
        printf("5. Read the value of a cell at a given row and column.\n");
        printf("6. Sum.\n");
        printf("7. Product.\n");
        printf("8. Exit.\n");
        printf("\nChoose an option: ");
        scanf_s("%d", &option);
        
        switch (option)
        {
            case 1:
                printf("\nCreate a new matrix.\n");
                printf("\nEnter a number of rows: ");
                scanf_s("%d", &rows);
                printf("\nEnter a number of columns: ");
                scanf_s("%d", &columns);
                createMatrix(&sparceMatrix, rows, columns);
                printf("\nMatrix created successfuly.");
                break;
            case 2:
                printf("\nInsert a node given its row and column.\n");
                printf("\nEnter row index: ");
                scanf_s("%d", &rowIndex);
                printf("\nEnter column index: ");
                scanf_s("%d", &columnIndex);
                printf("\nEnter a non zero value: ");
                scanf_s("%d", &nonZeroValue);
                insertNode(&sparceMatrix, rowIndex, columnIndex, nonZeroValue);
                printf("\nNode inserted successfuly.");
                break;
            //case 3:
            //    printf("\nDelete a node given its row and column.\n");
            //    printf("\nEnter row index: ");
            //    scanf_s("%d", &rowIndex);
            //    printf("\nEnter column index: ");
            //    scanf_s("%d", &columnIndex);
            //    deletedValue = deleteNode(&sparceMatrix, rowIndex, columnIndex);
            //    printf("\nNode with value %d deleted successfuly.", deletedValue);
            //    break;
            //case 4:
            //    printf("\nAssign a new value at a given row and column.\n");
            //    printf("\nEnter row index: ");
            //    scanf_s("%d", &rowIndex);
            //    printf("\nEnter column index: ");
            //    scanf_s("%d", &columnIndex);
            //    printf("\nEnter a non zero value: ");
            //    scanf_s("%d", &nonZeroValue);
            //    assingInfo(&sparceMatrix, rowIndex, columnIndex, nonZeroValue);
            //    printf("\nNode info updated successfuly.");
            //    break;
            //case 5:
            //    printf("\nRead the value of a cell at a given row and column.\n");
            //    printf("\nEnter row index: ");
            //    scanf_s("%d", &rowIndex);
            //    printf("\nEnter column index: ");
            //    scanf_s("%d", &columnIndex);
            //    readValue = readNode(&sparceMatrix, rowIndex, columnIndex);
            //    printf("\nNode (%d,%d): %d.", rowIndex, columnIndex, readValue);
            //    break;
            //case 6:
            //    printf("\nSum.\n");
            //    sumValue= 0;
            //    printf("\nSum matrix result is: %d", sumValue);
            //    break;
            //case 7:
            //    printf("\nProduc.\n");
            //    productValue = 0;
            //    printf("\nProduc matrix result is: %d", productValue);
            //    break;
            case 8:
                printf("\nGoodbye c:\n");
                exit(0);
                break;

            
            default:
                printf("\nWrong option :c\n");
                break;
        }
    }
    */
    return 0;
}

void createMatrix(Matrix *mx, int totalRows, int totalColumns)
{
    mx->totalRows = totalRows;
    mx->totalColumns = totalColumns;
    mx->currentElements = 0;
    mx->totalElements = totalRows * totalColumns;
    mx->rowPtr = (Node **)calloc(1, (sizeof(Node) * totalRows));
    mx->colPtr = (Node **)calloc(1, (sizeof(Node) * totalColumns));

    // create rows headnodes
    for (int i = 0; i <= totalRows; i++)
        mx->rowPtr[i] = (Node *)calloc(1, sizeof(Node));

    // create columns headnodes
    for (int i = 0; i <= totalColumns; i++)
        mx->colPtr[i] = (Node *)calloc(1, sizeof(Node));

    // initialize and link rows headnodes together
    for (int i = 0; i <= totalRows; i++)
    {
        mx->rowPtr[i]->rowIndex = i;

        if (i == 0) // the first pointer
        {
            mx->rowPtr[i]->nextRow = mx->rowPtr[i + 1];
            mx->rowPtr[i]->nextColumn = mx->colPtr[i + 1]; //nextColumn column, just once
        }
        else if (i == totalRows) // the last pointer 
        {
            mx->rowPtr[i]->nextRow = mx->rowPtr[0]; // come back to the first
            mx->rowPtr[i]->nextColumn = mx->rowPtr[i]; // nextColumn column point to the current row
        }
        else
        {
            mx->rowPtr[i]->nextRow = mx->rowPtr[i + 1]; // nextColumn row
            mx->rowPtr[i]->nextColumn = mx->rowPtr[i]; // nextColumn column point to the current row
        }
    }

    // initialize and link columns headnodes together
    for (int i = 0; i <= totalColumns; i++)
    {
        mx->colPtr[i]->colIndex = i;

        if (i == 0) // the first pointer
        {
            mx->colPtr[i]->nextColumn = mx->colPtr[i + 1];
            mx->colPtr[i]->nextRow = mx->rowPtr[i + 1]; //nextColumn row, just once
        }
        else if (i == totalColumns) // the last pointer 
        {
            mx->colPtr[i]->nextColumn = mx->colPtr[0]; // come back to the first
            mx->colPtr[i]->nextRow = mx->colPtr[i]; // nextColumn row point to the current column
        }
        else
        {
            mx->colPtr[i]->nextColumn = mx->colPtr[i + 1]; // nextColumn column
            mx->colPtr[i]->nextRow = mx->colPtr[i]; // nextColumn row point to the current column
        }
    }

    return;
}

void insertNode(Matrix *mx, int rowIndex, int colIndex, int nonZeroValue)
{
    if (nonZeroValue == 0)
    {
        printf("Value can not be zero. Try with a valid value.");
        return;
    }

    if (rowIndex > mx->totalRows)
    {
        printf("The row index is out of range");
        return;
    }

    if (colIndex > mx->totalColumns)
    {
        printf("The column index is out of range");
        return;
    }

    if(mx->currentElements == mx->totalElements)
    {
        printf("You can not insert more nodes. The matrix is full.");
        return;
    }

    Node *newNode = (Node *)calloc(1, sizeof(Node));

    newNode->rowIndex = rowIndex; // 1
    newNode->colIndex = colIndex; // 1
    newNode->info = nonZeroValue;
    
    Node *currentNode = (Node *)calloc(1, sizeof(Node));
    Node *tempNext = (Node *)calloc(1, sizeof(Node));

    // Recorrer las filas hasta encontrar el correcto
    for (int i = 0; i <= mx->totalRows; i++) // Recorrer row headnodes
    {
        
        if(mx->rowPtr[i]->rowIndex == rowIndex) // find row head 
        {
            currentNode = mx->rowPtr[i]; // in this moment row headnode

            //if(mx->rowPtr[i]->)

            //while (currentNode->nextColumn != mx->)

            
            
        }
    }
    
    //Recorrer las filas
        //Variable temporal columnas
    //Encontrar la fila correcta
    //Recorrer las columnas

    return;
}


