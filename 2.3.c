#include <stdio.h>

void explode(const char *s, char sp, char out[][10], int *n) {
    int i, j = 0, k = 0;
    *n = 0;

    for (i = 0; s[i]; i++) {
        if (s[i] == sp) {
            out[k][j] = '\0';
            k++; j = 0; (*n)++;
        } else {
            out[k][j++] = s[i];
        }
    }
    out[k][j] = '\0';
    (*n)++;
}

int main() {
    char out[20][10];
    int num;

    explode("I/Love/You", '/', out, &num);

    for (int i = 0; i < num; i++){
        printf("%s\n", out[i]);}
    printf("count = %d\n", num);
    return 0;
}
