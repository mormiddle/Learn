#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int enQueue(int* a, int rear, int data) {
    if (MAX_SIZE == rear) {
        printf("队列已满\n");
    }

    a[rear] = data;
    rear++;
    return rear;
}

int deQueue(int* a, int top, int rear) {
    if (rear == top) {
        printf("队列为空\n");
        return top;
    }

    printf("出队列元素为：%d\n", a[top]);
    top++;
    return top;
}

int main() {
    int a[MAX_SIZE];
    int top, rear;
    // 设置队头指针和队尾指针，当队列中没有元素时，队头和队尾指向同一块地址
    top = rear = 0;
    // 入队
    rear = enQueue(a, rear, 1);
    rear = enQueue(a, rear, 2);
    rear = enQueue(a, rear, 3);
    rear = enQueue(a, rear, 4);
    // 出队
    top = deQueue(a, top, rear);
    top = deQueue(a, top, rear);
    top = deQueue(a, top, rear);
    top = deQueue(a, top, rear);
    top = deQueue(a, top, rear);
    getchar();
    return 0;
}