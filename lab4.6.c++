#include <cstring>
#include <cstdio>
struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    studentNode *next;
};

void SaveNode(studentNode *child, char n[], int a, char s, float g);
void GoNext2(studentNode ***walk);

int main() {
    studentNode *start, *now1, **now2;

    start = new studentNode;
    SaveNode(start, (char*)"one", 6, 'M', 3.11);

    start->next = new studentNode;
    SaveNode(start->next, (char*)"two", 8, 'F', 3.22);

    start->next->next = new studentNode;
    SaveNode(start->next->next, (char*)"three", 10, 'M', 3.33);

    start->next->next->next = new studentNode;
    SaveNode(start->next->next->next, (char*)"four", 12, 'F', 3.44);

    now1 = start;
    now2 = &start;

    GoNext2(&now2);
    printf("%s\n", (*now2)->name);

    return 0;
}
void SaveNode(studentNode *child, char n[], int a, char s, float g) {
    strcpy(child->name, n);
    child->age = a;
    child->sex = s;
    child->gpa = g;
}
void GoNext2(studentNode ***walk) {
    *walk = &((**walk)->next);
}