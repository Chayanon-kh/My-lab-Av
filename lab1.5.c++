#include <stdio.h>

void GetMatrix(int **value, int *row, int *col){
    int *var;
    printf("row, col ? : ");
    scanf("%d %d", row, col);
    var = new int[ *row * *col];
    for(int i = 0; i < *row; i++)
        for(int j = 0; j < *col; j++){
            printf("value[%d][%d] = ", i, j);
            scanf("%d", &var[ i * * col + j]);
        }
    *value = var;
  
}

int main(){
    int *data, m, n;
    GetMatrix(&data, &m, &n);
    return 0;
}

