#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

void ShowAll(struct studentNode *walk) {
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}


struct studentNode* AddNode(struct studentNode **start,
                            char name[], int age, char sex, float gpa) {
    struct studentNode *newNode, *walk;

    newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = NULL;

    if (*start == NULL) {
        *start = newNode;
    } else {
        walk = *start;
        while (walk->next != NULL) {
            walk = walk->next;
        }
        walk->next = newNode;
    }
    return newNode;
}


struct studentNode* FindNode(struct studentNode *start, char name[]) {
    struct studentNode *walk = start;
    while (walk != NULL) {
        if (strcmp(walk->name, name) == 0) {
            return walk; 
        }
        walk = walk->next;
    }
    return NULL; 
}

void EditNode(struct studentNode *node,
              char name[], int age, char sex, float gpa) {
    if (node != NULL) {
        strcpy(node->name, name);
        node->age = age;
        node->sex = sex;
        node->gpa = gpa;
    }
}

int main() {
    struct studentNode *start = NULL, *now;

    AddNode(&start, "one", 6, 'M', 3.11);
    AddNode(&start, "two", 8, 'F', 3.22);
    AddNode(&start, "three", 10, 'M', 3.33);
    ShowAll(start);

   
    now = FindNode(start, "two");
    if (now != NULL) {
        printf("Found: %s\n", now->name);
       
        EditNode(now, "two", 9, 'F', 3.99);
    }

    ShowAll(start);

    return 0;
}
