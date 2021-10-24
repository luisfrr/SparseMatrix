#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Matrix Matrix;

struct Node
{
    int info;
    int row;
    int column;
    Node *nextColumn; // Next Column
    Node *nextRow; // Next Row
};

struct Matrix
{
    int totalRows;
    int totalColumns;
    int totalElements; // SI QUIEREN LO QUITAN
    int currentElements; // SI QUIEREN LO QUITAN
    Node *head_node;
};

// Prototypes
void create(Matrix *mx, int rows, int columns);
void insert(Matrix *mx, int row, int column, int value);
void printMatrix(Matrix *mx);
int search(Matrix *mx, int row, int column);
void assign(Matrix *mx, int row, int column, int value);
int read(Matrix *mx, int row, int column);
int deleteNode(Matrix *mx, int r, int c);

void sum(Matrix *matrixA, Matrix *matrixB, Matrix *matrixC);
void product(Matrix *matrixA, Matrix *matrixB, Matrix *matrixC);


int main()
{
    Matrix matrixA = { .totalRows = 0, .totalColumns = 0, .head_node = NULL};
    Matrix matrixB = { .totalRows = 0, .totalColumns = 0, .head_node = NULL};
    
    int totalrows, totalcolumns;
    int ro, co, newVa, opc, conter = 0;

    int data_returned, selec;

    do
    {   
        printf("\nSparce Matrix Project\n");

        printf("\t1. Create a new matrix empty.\n");
        printf("\t2. Insert a node.\n");
        printf("\t3. Delete a node.\n");
        printf("\t4. Assign a new value.\n");
        printf("\t5. Read node value.\n");
        printf("\t6. Sum two matrix.\n");
        printf("\t7. Multiply two matrix.\n");
        printf("\t8. Print the matrix.\n");
        printf("\t9. Exit.\n");
        printf("\nChoose an option: ");
        scanf_s("%d", &opc); // Save option

        switch (opc)
        {
            case 1:
                printf("\n### Create a new matrix empty ###\n");

                printf("Enter the size of your matrix A[n,m]:\n"); // MODIFICAR
                printf("N (rows): "); // MODIFICAR
                scanf_s("\n%d", &totalrows);
                printf("M (columns): "); // MODIFICAR
                scanf_s("\n%d", &totalcolumns);
                conter = conter + 1;
                
                if (conter == 1)
                {
                    create(&matrixA, totalrows, totalcolumns);
                }
                else if (conter == 2)
                {
                    create(&matrixB, totalrows, totalcolumns);
                }
                else
                {
                    printf("Operation not was possible to perform.\n"); // MODIFICAR
                }

                system("Pause");
                system("cls");
                break;

            case 2:
                printf("\n### Insert a node ###.\n\t1. Matrix A\n\t2. Matrix B\n");
                printf("Choose an option: ");
                scanf_s("%d", &selec);

                if (matrixA.totalRows == 0 && matrixB.totalRows == 0)
                {
                    printf("You need to create a matrix.\n");
                    system("Pause");
                    system("cls");
                    break;
                }

                if (selec != 1 && selec != 2)
                {
                    printf("Invalid option.\n");
                    system("Pause");
                    system("cls");
                    break;
                }

                printf("Enter the position of your value A(i,j):\n"); // MODIFICAR
                printf("Enter i: "); // MODIFICAR
                scanf_s("%d", &ro);
                printf("Enter j: "); // MODIFICAR
                scanf_s("%d", &co);
                printf("Enter Value: "); // MODIFICAR
                scanf_s("%d", &newVa);

                if (selec == 1)
                    insert(&matrixA, ro, co, newVa);
                else
                {
                    insert(&matrixB, ro, co, newVa);
                }

                fflush(stdin);
                system("Pause");
                system("cls");
                break;

            case 3:
                printf("\n### Delete a node ###.\n\t1. Matrix A\n\t2. Matrix B\n");
                printf("Choose an option: ");
                scanf_s("%d", &selec);

                if (selec != 1 && selec != 2)
                {
                    printf("Invalid option.\n");
                    system("Pause");
                    system("cls");
                    break;
                }

                printf("Enter the position to remove A(i,j):\n"); // MODIFICAR
                printf("Enter i: "); // MODIFICAR
                scanf_s("\n%d", &ro);
                printf("Enter j: "); // MODIFICAR
                scanf_s("\n%d", &co);

                if (selec == 1)
                {
                    data_returned = deleteNode(&matrixA, ro, co);
                }
                else
                {
                    data_returned = deleteNode(&matrixB, ro, co);
                }

                printf("Value deleted is : [ %d ]", data_returned);
                fflush(stdin);
                system("Pause");
                system("cls");
                break;

            case 4:
                printf("\n### Assign a new value ###.\n\t1. Matrix A\n\t2. Matrix B\n");
                printf("Choose an option: ");
                scanf_s("%d", &selec);

                if (selec != 1 && selec != 2)
                {
                    printf("Invalid option.\n"); 
                    system("Pause");
                    system("cls");
                    break;
                }

                printf("Enter the position A(i,j):\n");  // MODIFICAR
                printf("Enter i: "); // MODIFICAR
                scanf_s("\n%d", &ro);
                printf("Enter j: "); // MODIFICAR
                scanf_s("\n%d", &co);
                printf("Enter New Value: "); // MODIFICAR
                scanf_s("\n%d", &newVa);

                if (selec == 1)
                {
                    assign(&matrixA, ro, co, newVa);
                }
                else
                {
                    assign(&matrixB, ro, co, newVa);
                }

                fflush(stdin);
                system("Pause");
                system("cls");
                break;

            case 5:
                printf("\n### Read node value ###.\n\t1. Matrix A\n\t2. Matrix B\n");
                printf("Choose an option: ");
                scanf_s("%d", &selec);

                if (selec != 1 && selec != 2)
                {
                    printf("Invalid option.\n"); 
                    system("Pause");
                    system("cls");
                    break;
                }

                printf("Enter your position [row][column]:\n"); // MODIFICAR
                printf("Row: "); // MODIFICAR
                scanf_s("%d", &ro);
                printf("Column: "); // MODIFICAR
                scanf_s("%d", &co);

                if (selec == 1)
                {
                    data_returned = read(&matrixA, ro, co);
                }
                else
                {
                    data_returned = read(&matrixB, ro, co);
                }

                printf("Node value is : [%d]", data_returned); 

                system("Pause");
                system("cls");
                break;

            case 6:
                printf("\n### Sum two matrix ###.\n");

                if(matrixA.totalRows == 0 || matrixB.totalRows == 0)
                {
                    printf("You need to create some matrices.\n");
                    system("Pause");
                    system("cls");
                    break;
                }

                Matrix matrixS = { .totalRows = 0, .totalColumns = 0, .head_node = NULL};

                printf("\nMatrixA + MatrixB = MatrixC");
                sum(&matrixA, &matrixB, &matrixS);

                printf("\nMatrix A: \n");
                printMatrix(&matrixA);

                printf("\nMatrix B: \n");
                printMatrix(&matrixB);

                printf("\nMatrix C: \n");
                printMatrix(&matrixS);
                printf("\n");

                system("Pause");
                system("cls");
                break;

            case 7:
                printf("\n### Multiply two matrix ###.\n");

                if(matrixA.totalRows == 0 || matrixB.totalRows == 0)
                {
                    printf("You need to create some matrices.\n");
                    system("Pause");
                    system("cls");
                    break;
                }

                Matrix matrixP = { .totalRows = 0, .totalColumns = 0, .head_node = NULL};

                printf("\nMatrixA * MatrixB = MatrixC");
                product(&matrixA, &matrixB, &matrixP);

                printf("\nMatrix A: \n");
                printMatrix(&matrixA);

                printf("\nMatrix B: \n");
                printMatrix(&matrixB);

                printf("\nMatrix C: \n");
                printMatrix(&matrixP);
                printf("\n");

                system("Pause");
                system("cls");
                break;

            case 8:
                printf("\n### Print the matrix ###.\n\t1. Matrix A\n\t2. Matrix B\n");
                printf("Choose an option: ");
                scanf_s("%d", &selec);

                if (selec != 1 && selec != 2)
                {
                    system("cls");
                    break;
                }

                if (selec == 1)
                {
                    printMatrix(&matrixA);
                }
                else
                {
                    printMatrix(&matrixB);
                }    

                system("Pause");
                system("cls");
                break;

            case 9:
                printf("Goodbye c:\n");
                exit(0);
                break;

            default:
                printf("Invalid option :c\n");
                system("Pause");
                system("cls");
                break;
        }
    } 
    while (opc != 9); //printSpareMatrix(first_nodeA);

    return 0;
}

//void createMatrix(Matrix *mx, Node **head_node, struct matrix m_size)
void create(Matrix *mx, int rows, int columns)
{
    mx->totalRows = rows;
    mx->totalColumns = columns;
    mx->currentElements = 0;
    mx->totalElements = rows * columns;

    Node *init_node;
    Node *new_node;
    Node *aux, *prev;

    // Allocate dynamic memory
    init_node = (Node *)malloc(sizeof(Node));
    // Verify if the node has dynamic memory
    if (init_node == NULL)
    {
        printf("Dynamic memory for init node was not allocated.\n");
        return;
    }
    // Assign values [row][column][value] --> [0][0][0]
    init_node->row = 0;
    init_node->column = 0;
    init_node->info = 0;
    // Pointers initialization, node links to itself
    init_node->nextColumn = init_node;
    init_node->nextRow = init_node;
    // Head pointer links to init node which is the first node [0][0]
    //*head_node = init_node;  ELIMINAR

    mx->head_node = init_node;
    /*
    This prints the points and values of init_node to verify whether it works well
    printf("head pointer: %p\n",head_node);
    printf("Init node address: %p\n",init_node);
    printf("[%d][%d][%d]  [%p][%p]\n",init_node->row,init_node->column,init_node->info,init_node->nextRow,init_node->nextColumn);
    */

    //-------------------------------
    // Loop to insert the extra row 0
    //-------------------------------
    for (int i = 1; i <= mx->totalRows; i++)
    {

        new_node = (Node *)malloc(sizeof(Node));

        if (new_node != NULL)
        {

            new_node->info = 0;
            new_node->column = 0;
            new_node->row = i;

            if (init_node->nextRow == init_node)
            {

                new_node->nextRow = init_node->nextRow;
                new_node->nextColumn = new_node;
                init_node->nextRow = new_node;
            }
            else
            {

                aux = init_node;
                prev = init_node;
                aux = aux->nextRow;

                while (aux != init_node)
                {
                    prev = aux;
                    aux = aux->nextRow;
                }

                new_node->nextRow = prev->nextRow;
                new_node->nextColumn = new_node;
                prev->nextRow = new_node;
            }
        }
    }

    //----------------------------------
    // Loop to insert the extra column 0
    //----------------------------------

    for (int j = 1; j <= mx->totalColumns; j++)
    {

        new_node = (Node *)malloc(sizeof(Node));

        if (new_node != NULL)
        {

            new_node->info = 0;
            new_node->column = j;
            new_node->row = 0;

            if (init_node->nextColumn == init_node)
            {

                new_node->nextColumn = init_node->nextColumn;
                new_node->nextRow = new_node;
                init_node->nextColumn = new_node;
            }
            else
            {

                aux = init_node;
                prev = init_node;
                aux = aux->nextColumn;

                while (aux != init_node)
                {
                    prev = aux;
                    aux = aux->nextColumn;
                }

                new_node->nextColumn = prev->nextColumn;
                new_node->nextRow = new_node;
                prev->nextColumn = new_node;
            }
        }
    }
}

//void insert(Node **head_node, struct matrix m_size, int row, int column, int value)
void insert(Matrix *mx, int row, int column, int value)
{

    if (row > mx->totalRows || column > mx->totalColumns)
    {

        printf("You are trying to insert a node out of the size entered.\n");
        return;
    }

    Node *new_node;
    Node *tempR;
    Node *tempC;
    Node *aux, *prev;
    int cont = 0;

    new_node = (Node *)malloc(sizeof(Node));

    new_node->info = value;
    new_node->row = row;
    new_node->column = column;

    printf("\nLooking for the location... wait.\n");
    for (tempR = mx->head_node; tempR->row != row; tempR = tempR->nextRow)
    {
        for (tempC = mx->head_node; tempC->column != column; tempC = tempC->nextColumn)
        {
            cont = cont + 1;
        }
    }

    printf("Position found.\nCreating new node.\nTimes[%d]\n", cont);
    if (tempR->nextColumn == tempR && tempC->nextRow == tempC)
    {

        new_node->nextColumn = tempR->nextColumn;
        tempR->nextColumn = new_node;

        new_node->nextRow = tempC->nextRow;
        tempC->nextRow = new_node;
        printf("Node created by method one.\n");
        return;
    }
    else if (tempR->nextColumn == tempR && tempC->nextRow != tempC)
    {

        new_node->nextColumn = tempR->nextColumn;
        tempR->nextColumn = new_node;

        prev = tempC;
        aux = tempC;
        aux = aux->nextRow;

        while (aux != tempC)
        {
            if (aux->row > row)
            {
                new_node->nextRow = aux;
                tempC->nextRow = new_node;
                printf("Node created by method two(a).\n");
                return;
            }
            prev = aux;
            aux = aux->nextRow;
        }

        new_node->nextRow = prev->nextRow;
        prev->nextRow = new_node;
        printf("Node created by method two(b).\n");
        return;
    }
    else if (tempR->nextColumn != tempR && tempC->nextRow == tempC)
    {

        new_node->nextRow = tempC->nextRow;
        tempC->nextRow = new_node;

        prev = tempR;
        aux = tempR;
        aux = aux->nextColumn;

        while (aux != tempR)
        {
            if (aux->column > column)
            {
                new_node->nextColumn = aux;
                tempR->nextColumn = new_node;
                printf("Node created by method three(a).\n");
                return;
            }
            prev = aux;
            aux = aux->nextColumn;
        }

        new_node->nextColumn = prev->nextColumn;
        prev->nextColumn = new_node;
        printf("Node created by method two(b).\n");
        return;
    }
    else if (tempR->nextColumn != tempR && tempC->nextRow != tempC)
    {

        // Row--------------------------
        prev = tempR;
        aux = tempR;
        aux = aux->nextColumn;

        while (aux != tempR)
        {
            if (aux->column > column)
            {
                new_node->nextColumn = aux;
                tempR->nextColumn = new_node;

                // Column--------------------------
                prev = tempC;
                aux = tempC;
                aux = aux->nextRow;

                while (aux != tempC)
                {
                    if (aux->row > row)
                    {
                        new_node->nextRow = aux;
                        tempC->nextRow = new_node;
                        return;
                    }
                    prev = aux;
                    aux = aux->nextRow;
                }

                new_node->nextRow = prev->nextRow;
                prev->nextRow = new_node;
                printf("\nAlternative case\n");
                return;
            }

            prev = aux;
            aux = aux->nextColumn;
        }

        new_node->nextColumn = prev->nextColumn;
        prev->nextColumn = new_node;

        // Column--------------------------

        prev = tempC;
        aux = tempC;
        aux = aux->nextRow;

        while (aux != tempC)
        {
            if (aux->row > row)
            {
                new_node->nextRow = aux;
                tempC->nextRow = new_node;
                return;
            }
            prev = aux;
            aux = aux->nextRow;
        }
        new_node->nextRow = prev->nextRow;
        prev->nextRow = new_node;
    }
}

//void printSpareMatrix(struct node *head_node)
void printMatrix(Matrix *mx)
{
    Node *tempR = mx->head_node;
    Node *tempC;

    if (mx->head_node != NULL)
    {

        while (tempR->nextRow != mx->head_node)
        {
            tempC = tempR;
            do
            {
                printf("[%d][%d][%d]  ", tempC->row, tempC->column, tempC->info);
                tempC = tempC->nextColumn;
            } while (tempC != tempR);

            printf("\n");
            tempR = tempR->nextRow;
        }
        tempC = tempR;
        do
        {
            printf("[%d][%d][%d]  ", tempC->row, tempC->column, tempC->info);
            tempC = tempC->nextColumn;
        } while (tempC != tempR);
        printf("\n");
    }
}

//int searchNode(struct node *head_node, struct matrix m_size, int row, int column)
int search(Matrix *mx, int row, int column)
{

    Node *tempR = mx->head_node;
    Node *tempC;

    if (row > mx->totalRows || column > mx->totalColumns)
    {
        printf("You are trying to perform a operation outside of the matrix range.\n");
        return 0;
    }

    for (int i = 0; i <= row - 1; i++)
    {
        tempR = tempR->nextRow;
    }
    tempC = tempR;
    tempC = tempC->nextColumn;

    while (tempC != tempR)
    {
        if (tempC->column == column)
            return 1;
        tempC = tempC->nextColumn;
    }
    printf("The position typed has not a node.\n");
    return 0;
}

//void assignValue(struct node *head_node, struct matrix m_size, int row, int column, int value)
void assign(Matrix *mx, int row, int column, int value)
{
    Node *tempR = mx->head_node;
    Node *tempC;
    int pase;

    pase = search(mx, row, column);
    if (pase != 1)
        return;

    for (int i = 0; i <= row - 1; i++)
    {
        tempR = tempR->nextRow;
    }
    tempC = tempR;
    tempC = tempC->nextColumn;

    while (tempC != tempR)
    {
        if (tempC->column == column)
        {
            tempC->info = value;
            printf("Operation done.\n");
            return;
        }
        tempC = tempC->nextColumn;
    }
}

//void read(struct node *head_node, struct matrix m_size)
int read(Matrix *mx, int row, int column)
{
    Node *tempR = mx->head_node;
    Node *tempC;
    int pase;

    pase = search(mx, row, column);
    if (pase != 1)
        return 0;

    for (int i = 0; i <= row - 1; i++)
    {
        tempR = tempR->nextRow;
    }
    tempC = tempR;
    tempC = tempC->nextColumn;

    while (tempC != tempR)
    {
        if (tempC->column == column)
        {
            return tempC->info;
        }
        tempC = tempC->nextColumn;
    }

    return 0;
}

//int deleteNode(struct node **head_node, struct matrix m_size, int r, int c)
int deleteNode(Matrix *mx, int r, int c)
{

    Node *tempR;
    Node *tempC;
    Node *prev, *aux;
    int pase, data, cont = 0;

    pase = search(mx, r, c);
    if (pase != 1)
        return 0;

    for (tempR = mx->head_node; tempR->row != r; tempR = tempR->nextRow)
    {
        for (tempC = mx->head_node; tempC->column != c; tempC = tempC->nextColumn)
        {
            cont = cont + 1;
        }
    }

    printf("Temp R:[%d][%d]\nTemp C:[%d][%d]\n", tempR->row, tempR->column, tempC->row, tempC->column);

    if (tempR->nextColumn != tempR && tempC->nextRow != tempC)
    {
        aux = tempR;
        prev = tempR;
        aux = aux->nextColumn;

        while (aux != tempR)
        {
            if (aux->row == r && aux->column == c)
            {
                prev->nextColumn = aux->nextColumn;
                aux->nextColumn = aux;

                aux = tempC;
                prev = tempC;
                aux = aux->nextRow;

                while (aux != tempC)
                {
                    if (aux->row == r && aux->column == c)
                    {
                        prev->nextRow = aux->nextRow;
                        aux->nextRow = aux;
                        data = aux->info;
                        free(aux);
                        return data;
                    }

                    prev = aux;
                    aux = aux->nextRow;
                }
            }

            prev = aux;
            aux = aux->nextColumn;
        }
    }else
    {
        return 0;
    }
    return 0;
}

void sum(Matrix *matrixA, Matrix *matrixB, Matrix *matrixC)
{
    // Validación solo se puede sumar matrices del mismo orden
    if(matrixA->totalRows != matrixB->totalRows && matrixA->totalColumns && matrixB->totalColumns)
    {
        printf("\nTwo matrices have to have an equal number of rows and columns to be able to add them.\n");
        return;
    }

    int valueA = 0, valueB = 0, result = 0;

    // Se crea la matrix resultante
    create(matrixC, matrixA->totalRows, matrixA->totalColumns);

    for (int i = 1; i <= matrixC->totalRows; i++)
    {
        for (int j = 1; j <= matrixC->totalColumns; j++)
        {
            valueA = read(matrixA, i, j);
            valueB = read(matrixB, i, j);

            result = valueA + valueB;

            insert(matrixC, i, j, result);
        }
    }
    
    

    return;
}

void product(Matrix *matrixA, Matrix *matrixB, Matrix *matrixC)
{
    if (matrixA->totalColumns != matrixB->totalRows)
    {
        printf("\nThe number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return;
    }

    int valueA = 0, valueB = 0, result = 0;

    // Se crea la matrix resultante
    create(matrixC, matrixA->totalRows, matrixB->totalColumns);

    // Necesitamos hacer esto por cada columna de la segunda matriz (B)
    for (int a = 1; a <= matrixB->totalColumns; a++)
    {
        // Dentro recorremos las filas de la primera (A)
        for (int i = 1; i <= matrixA->totalRows; i++)
        {
            for (int j = 1; j <= matrixA->totalColumns; j++)
            {
                valueA = read(matrixA, i, j);
                valueB = read(matrixB, j, a);

                result += valueA * valueB;
            }
            
            insert(matrixC, i, a, result);
            result = 0;
        }
        
    }

    return;
}

