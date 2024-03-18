//内容：双向链表的基本操作
#include <stdio.h>
#include <stdlib.h>

typedef struct line {
    struct line* prior;
    int data;
    struct line* next;
}Line;

Line* initLine(Line* head) {
    Line* list = NULL;
    head = (Line*)malloc(sizeof(Line));
    head->prior = NULL;
    head->next = NULL;
    head->data = 1;
    list = head;
    for(int i = 2; i <= 5; i++) {
        Line* body = (Line*)malloc(sizeof(Line));
        body->prior = NULL;
        body->next = NULL;
        body->data = i;
        list->next = body;
        body->prior = list;
        list = body;
    }
    return head;
}

void display(Line* head) {
    Line* temp = head;
    while(temp) {
        if(NULL == temp->next) {
            printf("%d\n", temp->data);
        }
        else {
            printf("%d <-> ", temp->data);
        }
        temp = temp->next;
    }
}

void free_line(Line* head) {
    Line* temp = head;
    while(temp) {
        head = head->next;
        free(temp);
        temp = head;
    }
}

int main() {
    Line* head = NULL;
    head = initLine(head);
    display(head);
    printf("链表中第 4 个节点的直接前驱是：%d", head->next->next->next->prior->data);
    free_line(head);
    getchar();
    return 0;
}