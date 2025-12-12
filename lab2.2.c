#include <stdio.h>

char* reverse(char str1[]) {
    static char str2[100];
    int j = 0;
    while (str1[j] != '\0') {
        j++;
    }
    for (int i = 0; i < j; i++) {
        str2[i] = str1[j - 1 - i];
    }

    str2[j] = '\0';

    return str2;
}
int main() {
    char text[50] = "I Love You";
    char *out;

    out = reverse(text);
    printf("%s\n", out);

    return 0;
}
