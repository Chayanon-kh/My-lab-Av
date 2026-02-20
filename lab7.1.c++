#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

struct studentNode {
    char name[ 20 ];
    int age;
    char sex;
    float gpa;
    struct studentNode *next; 
};

class LinkedList {
protected:
    struct studentNode *start, **now;

public:
    LinkedList();
    ~LinkedList();
    void InsNode( char n[], int a, char s, float g );
    void DelNode();
    void GoNext();
    virtual void ShowNode();
};

class NewList : public LinkedList {
public:
    void GoFirst();
    virtual void ShowNode();
};

int main() {
    LinkedList listA;
    NewList listB;
    LinkedList *listC;

    listA.InsNode( "one", 1, 'A', 1.1 );
    listA.InsNode( "two", 2, 'B', 2.2 );
    listA.InsNode( "three", 3, 'C', 3.3 );
    listA.GoNext();
    listA.ShowNode();

    listB.InsNode( "four", 4, 'D', 4.4 );
    listB.InsNode( "five", 5, 'E', 5.5 );
    listB.InsNode( "six", 6, 'F', 6.6 );
    listB.GoNext();
    listB.DelNode();
    listB.ShowNode();

    listC = &listA;
    listC->GoNext();
    listC->ShowNode();

    listC = &listB;
    listC->ShowNode();

    return 0;
}


LinkedList::LinkedList() {
    start = NULL;
    now = &start;
}

LinkedList::~LinkedList() {
    struct studentNode *temp;
    while (start != NULL) {
        temp = start;
        start = start->next;
        delete temp;
    }
}

void LinkedList::InsNode( char n[], int a, char s, float g ) {
    studentNode *newNode = new studentNode;
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    
    newNode->next = *now;
    *now = newNode;
}

void LinkedList::DelNode() {
    if (*now != NULL) {
        studentNode *temp = *now;
        *now = (*now)->next;
        delete temp;
    }
}

void LinkedList::GoNext() {
    if (*now != NULL && (*now)->next != NULL) {
        now = &((*now)->next);
    }
}

void LinkedList::ShowNode() {
    if (*now != NULL) {
        cout << (*now)->name << " " << (*now)->age << " " 
             << (*now)->sex << " " << fixed << setprecision(2) 
             << (*now)->gpa << endl;
    }
}

void NewList::GoFirst() {
    now = &start;
}

void NewList::ShowNode() {
    if (start != NULL && *now != NULL) {
        cout << start->name << " " << (*now)->name << endl;
    }
}