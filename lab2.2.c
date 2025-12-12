#include <stdio.h>

char* reverse(char str1[]) {
    static char str2[100];   // ใช้ static เพื่อให้ส่ง pointer กลับได้
    int j = 0;

    // หาความยาว string
    while (str1[j] != '\0') {
        j++;
    }

    // กลับด้านข้อความ
    for (int i = 0; i < j; i++) {
        str2[i] = str1[j - 1 - i];
    }

    str2[j] = '\0'; // ปิดท้าย string

    return str2;
}

int main() {
    char text[50] = "I Love You";
    char *out;

    out = reverse(text);
    printf("%s\n", out);

    return 0;
}
