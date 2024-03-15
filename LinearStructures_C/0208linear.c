

#include <stdio.h>
#include <stdlib.h>

typedef enum bool
{
    False = 0,
    True = 1
}bool;

typedef struct Link {
    int elem;
    struct Link* next;
}link;

bool LinkIntersect(link * L1, link * L2);

int main() {
    // Create test data
    link* L1 = (link*)malloc(sizeof(link));
    link* L2 = (link*)malloc(sizeof(link));
    link* common = (link*)malloc(sizeof(link));
    link* temp = NULL;

    L1->elem = 1;
    L1->next = (link*)malloc(sizeof(link));
    L1->next->elem = 2;
    L1->next->next = (link*)malloc(sizeof(link));
    L1->next->next->elem = 3;
    L1->next->next->next = NULL;

    L2->elem = 4;
    L2->next = (link*)malloc(sizeof(link));
    L2->next->elem = 5;
    L2->next->next = (link*)malloc(sizeof(link));
    L2->next->next->elem = 6;
    L2->next->next->next = NULL;

    common->elem = 7;
    common->next = (link*)malloc(sizeof(link));
    common->next->elem = 8;
    common->next->next = (link*)malloc(sizeof(link));
    common->next->next->elem = 9;
    common->next->next->next = NULL;

    // Connect the lists
    // L1->next->next->next = common;
    // L2->next->next->next = common;

    // Test the LinkIntersect function
    bool result = LinkIntersect(L1, L2);
    if (result) {
        printf("The lists intersect.\n");
    } else {
        printf("The lists do not intersect.\n");
    }

    getchar(); 
    return 0;
}

bool LinkIntersect(link * L1, link * L2) {
    link* plong = L1;
    link* pshort = L2;
    link* temp = NULL;
    int num1 = 0, num2 = 0, step = 0;

    while(plong) {
        num1++;
        plong = plong->next;
    }

    while(pshort) {
        num2++;
        pshort = pshort->next;
    }

    plong = L1;
    pshort = L2;
    step = num1 - num2;
    if(num1 < num2) {
        plong = L2;
        pshort = L1;
        step = num2 - num1;
    }

    temp = plong;
    while(step) {
        temp = temp->next;
        step--;
    }

    while(temp && pshort) {
        if(temp == pshort) {
            return True;
        }
        temp = temp->next;
        pshort = pshort->next;
    }
    return False;
}