#include <stdio.h>
#include <stdlib.h>

typedef struct qnode {
    int data;
    struct qnode* next;
}QNode;

QNode* initQueue() {
    //创建一个头节点
    QNode* queue = (QNode*)malloc(sizeof(QNode));

    queue->next = NULL;
    return queue;
}

QNode* enQueue(QNode* rear, int data) {
    QNode* enElem = (QNode*)malloc(sizeof(QNode));
    enElem->data = data;
    enElem->next = NULL;
    rear->next = enElem;
    rear = enElem;
}

QNode* deQueue(QNode* top, QNode* rear) {
    QNode* p = NULL;
    if(top->next == NULL) {
        printf("队列为空\n");
        return rear;
    }

    p = top->next;
    printf("出队列元素为：%d\n", p->data);
    top->next = p->next;
    if(rear == p) {
        rear == top;
    }
    free(p);
    return rear;


}

int main() {
    QNode* queue = NULL, * top = NULL, * rear = NULL;
    queue = top = rear = initQueue();//创建头结点
    //向链队列中添加结点，使用尾插法添加的同时，队尾指针需要指向链表的最后一个元素
    rear = enQueue(rear, 1);
    rear = enQueue(rear, 2);
    rear = enQueue(rear, 3);
    rear = enQueue(rear, 4);
    //入队完成，所有数据元素开始出队列
    rear = deQueue(top, rear);
    rear = deQueue(top, rear);
    rear = deQueue(top, rear);
    rear = deQueue(top, rear);
    rear = deQueue(top, rear);
    getchar();
    return 0;
}