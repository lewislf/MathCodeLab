#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int row;
    int column;
    int ** elements;
    int flag;
} tMatrix;

void readMatriz(tMatrix *matriz);
void sumMatrices(tMatrix *matrizA, tMatrix *matrizB, tMatrix *matrizResult);
void subMatrices(tMatrix *matrizA, tMatrix *matrizB, tMatrix *matrizResult);
void multMatrices(tMatrix *matrizA, tMatrix *matrizB, tMatrix *matrizResult);
void build_matrix_result(tMatrix *matrizResult, int row, int column);
void imprimeMatriz(tMatrix *matrizResult);
void fix_memory_leak(tMatrix *matriz);


int main(){
    tMatrix matrizA, matrizB, matrizResult;
    int option, i;

    
    readMatriz(&matrizA);
    readMatriz(&matrizB);       
    
    imprimeMatriz(&matrizA);
    imprimeMatriz(&matrizB);

    printf("Matrices Operations\n"
            "1) Sum\n"
            "2) Subtraction\n"
            "3) Multiplication\n"
            "Choose an option: \n");
    scanf("%d", &option);

    printf("%d\n", option);

    switch (option)
     {
        case 1:
            sumMatrices(&matrizA, &matrizB, &matrizResult);
            break;
        case 2:
            subMatrices(&matrizA, &matrizB, &matrizResult);
            break;
        case 3:
            multMatrices(&matrizA, &matrizB, &matrizResult);  
            break; 
     }

    if(matrizResult.flag)
    {
        imprimeMatriz(&matrizResult);
        fix_memory_leak(&matrizA);
        fix_memory_leak(&matrizB);
        fix_memory_leak(&matrizResult);
    }   

    return 0;
}

void readMatriz(tMatrix *matriz){
    int i, j;
    
    printf("Enter the number of rows and columns of Matrix ");
    scanf("%d %d", &matriz->row, &matriz->column);

    matriz->flag = 1;

    matriz->elements = (int **)malloc(matriz->row * sizeof(int *));

    for(i = 0; i < matriz->row; i++)
    {
        matriz->elements[i] = (int *)malloc(matriz->column * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");

    for(i = 0; i < matriz->row; i++)
    {
        for(j = 0; j < matriz->column; j++)
        {
            scanf("%d", &matriz->elements[i][j]);
        }
    }
}

void sumMatrices(tMatrix *matrizA, tMatrix *matrizB, tMatrix *matrizResult){

    if(matrizA->row != matrizB->row || matrizA->column != matrizB->column){
        printf("\nMatrices dimensions don't match for addition.\n");
        matrizResult->flag = 0;
        return;
    }

    build_matrix_result(matrizResult, matrizA->row, matrizA->column);

    for (int i = 0; i < matrizA->row; i++)
    {
        for(int j = 0; j < matrizA->column; j++)
        {
            matrizResult->elements[i][j] = matrizA->elements[i][j] + matrizB->elements[i][j];
        }
    }
}

void subMatrices(tMatrix *matrizA, tMatrix *matrizB, tMatrix *matrizResult){
    if(matrizA->row != matrizB->row || matrizA->column != matrizB->column){
        printf("\nMatrices dimensions don't match for addition.\n");
        matrizResult->flag = 0;
        return;
    }

    build_matrix_result(matrizResult, matrizA->row, matrizA->column);

    for (int i = 0; i < matrizA->row; i++)
    {
        for(int j = 0; j < matrizA->column; j++)
        {
            matrizResult->elements[i][j] = matrizA->elements[i][j] - matrizB->elements[i][j];
        }
    }
}

void multMatrices(tMatrix *matrizA, tMatrix *matrizB, tMatrix *matrizResult){
    if(matrizA->column != matrizB->row)
    {
        printf("\nMatrices dimensions don't match for multiplication. The number of 'column' in the"
                " first Matriz A should be equal to the number of 'row' in the second Matriz B\n");
        matrizResult->flag = 0;
        return;
    }

    build_matrix_result(matrizResult, matrizA->row, matrizB->column);

    for(int i = 0; i < matrizA->row; i++)
    {
        for(int j = 0; j < matrizB->column; j++)
        {
            matrizResult->elements[i][j] = 0;
            for(int k = 0; k < matrizA->column; k++)
            {
                matrizResult->elements[i][j] += matrizA->elements[i][k] * matrizB->elements[k][j];
            }
        }
    }
}

void fix_memory_leak(tMatrix *matriz)
{
    for(int i = 0; i < matriz->row; i++)
    {
        free(matriz->elements[i]);
    }

    free(matriz->elements);
}

void build_matrix_result(tMatrix *matrizResult, int row, int column){

    matrizResult->row = row;
    matrizResult->column = column;
    matrizResult->elements = (int **)malloc(matrizResult->row * sizeof(int *));

    for(int i = 0; i < matrizResult->row; i++){
        matrizResult->elements[i] = (int *)malloc(matrizResult->column * sizeof(int));
    }
}

void imprimeMatriz(tMatrix *matrixResult){
    int i, j;

    printf("\nMatriz Result:\n");
    for(i = 0; i < matrixResult->row; i++)
    {
        for(j = 0; j < matrixResult->column; j++)
        {
            printf("%d ", matrixResult->elements[i][j]);
        }
        printf("\n");
    }    
}



