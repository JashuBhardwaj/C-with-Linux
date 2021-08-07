// program for multiplication of two matrises
// Author name - Jashu Bhardwaj
// Date - 27/07/2021

#include <stdio.h>


// function for multiplication of two matrises
void matrix_multiply(int mat1[][5], int mat2[][5], int res[][5]) {
    
    for(int k = 0; k < 5; k++) {
        
        for(int i = 0; i < 5; i++) {
            
            res[k][i] = 0;
            
            for(int j = 0; j < 5; j++) {
                
                res[k][i] += mat1[k][j] * mat2[j][i];
            }
        }
        
    }
}


// function for printing the matrises
void print_matrix(int res[][5]) {
    
    for(int i = 0; i < 5; i++) {
        
        for(int j = 0; j < 5; j++) {
            printf("%d ",res[i][j]);
        }
        
        printf("\n");
    }
}

int main()
{  
    
    // first matrix
   int mat1[5][5] = { { 1, 2, 3, 4, 5},
                      { 1, 2, 3, 4, 5},
                      { 1, 2, 3, 4, 5},
                      { 1, 2, 3, 4, 5},
                      { 1, 2, 3, 4, 5} };
    
    // second matrix                
   int mat2[5][5] = { { 1, 1, 1, 1, 1},
                      { 2, 2, 2, 2, 2},
                      { 3, 3, 3, 3, 3},
                      { 4, 4, 4, 4, 4},
                      { 5, 5, 5, 5, 5} };
     
     // resulting matrix                
    int res[5][5];
    
    // calling the function gor multiplication of matrises
    matrix_multiply(mat1, mat2, res);
    
    print_matrix(res);
                    

    return 0;
}

