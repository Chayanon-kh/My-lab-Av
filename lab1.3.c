#include <stdio.h>

int *GetSet(int s[], int *n) {
    printf("Input N: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &s[i]); 
    }

}
int main() {
    int *data , count;
    GetSet(data, &count);
       printf("Output: Set has %d members: ", count);
    for (int i = 0; i < count; i++)  {
        printf("%d ", data[i]);
    }
    return 0;

}