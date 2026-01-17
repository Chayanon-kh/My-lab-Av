#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[ 20 ];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
    struct studentNode *back;
};

void ShowAll( struct studentNode *walk );
struct studentNode *AddNode( struct studentNode **walk, char n[], int a, char s, float g );
void InsNode( struct studentNode *now, char n[], int a, char s, float g, struct studentNode **begin );
void GoBack( struct studentNode **now );
void DelNode( struct studentNode **now, struct studentNode **begin );

int main() {
    struct studentNode *start, *now;
    start = NULL;

    now = AddNode( &start, "one", 6, 'M', 3.11 ); ShowAll( start );
    now = AddNode( &start, "two", 8, 'F', 3.22 ); ShowAll( start );
    
    InsNode( now, "three", 10, 'M', 3.33, &start ); ShowAll( start );
    InsNode( now, "four", 12, 'F', 3.44, &start ); ShowAll( start );
    
    GoBack( &now );

    DelNode( &now, &start ); ShowAll( start );
    DelNode( &now, &start ); ShowAll( start );
    DelNode( &now, &start ); ShowAll( start );

    return 0;
}

void ShowAll( struct studentNode *walk ) {
    while( walk != NULL ) {
        printf( "%s ", walk->name );
        walk = walk->next;
    }
    printf( "\n" );
}

struct studentNode *AddNode( struct studentNode **walk, char n[], int a, char s, float g ) {
    struct studentNode *temp = NULL;
    while( *walk != NULL ) {
        temp = *walk;
        walk = &(*walk)->next;
    }
    *walk = (struct studentNode*)malloc( sizeof( struct studentNode ) );
    strcpy( (*walk)->name, n );
    (*walk)->age = a;
    (*walk)->sex = s;
    (*walk)->gpa = g;
    (*walk)->next = NULL;
    (*walk)->back = temp;
    return *walk;
}

void InsNode( struct studentNode *now, char n[], int a, char s, float g, struct studentNode **begin ) {
    struct studentNode *newNode = (struct studentNode*)malloc( sizeof( struct studentNode ) );
    strcpy( newNode->name, n );
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;

    if( now->back != NULL ) {
        newNode->next = now;
        newNode->back = now->back;
        now->back->next = newNode;
        now->back = newNode;
    } else {
        newNode->next = now;
        newNode->back = NULL;
        now->back = newNode;
        *begin = newNode;
    }
}

void GoBack( struct studentNode **now ) {
    if( *now != NULL && (*now)->back != NULL ) {
        *now = (*now)->back;
    }
}

void DelNode( struct studentNode **now, struct studentNode **begin ) {
    if ( *now == NULL ) return;
    struct studentNode *temp;

    if( (*now)->back != NULL ) {
        (*now)->back->next = (*now)->next;
    } else {
        *begin = (*now)->next;
    }

    if( (*now)->next != NULL ) {
        (*now)->next->back = (*now)->back;
        temp = (*now)->next;
    } else {
        temp = (*now)->back;
    }

    delete( *now );
    *now = temp;
}