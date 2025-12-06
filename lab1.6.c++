#include <stdio.h>

int *GetMatrix(int *row, int *col){
    int *Pvar;
    printf("How many row, col ? :");
    scanf("%d %d", row, col);
    Pvar = new int[ *row * *col];
    return Pvar;
}

int main(){
    int *data, m , n;
    data = GetMatrix(&m, &n);

    printf("\nMatrix Input\n");
    for(int i = 0; i < m; i++){
        printf("%d row\n",i+1);
        for(int j = 0; j < n; j++){
            printf("%d col number: ",j+1);
            scanf("%d", &data[ i * n + j]);
        }
    }
    return 0;
}

