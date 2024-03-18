#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node* next;
}person;

person* initLink(int n) {
    person* body = NULL;
    person* cyclic = NULL;
    person* head = (person*)malloc(sizeof(person));
    head->number = 1;
    head->next = NULL;
    cyclic = head;
    for(int i = 2; i <= n; i++) {
        body = (person*)malloc(sizeof(person));
        body->number = i;
        body->next = NULL;
        cyclic->next = body;
        cyclic = body;
    }
    cyclic->next = head;
    return head;
}

void findAndKillK(person* head, int k, int m) {
    int i;
    person* tail = head;
    person* p = head;

    //找到尾节点，tail始终在p前面一个节点
    while(tail->next != head) {
        tail = tail->next;
    }

    //找到第一个为k的节点
    while(p->number != k) {
        tail = p;
        p = p->next;
    }
}


int main() {

    getchar();
    return 0;
}