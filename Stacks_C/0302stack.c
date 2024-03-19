#include <stdio.h>
#include <stdlib.h>

int push(int* a, int top, int elem) {
    a[++top] = elem;
    return top;
}

int pop(int* a, int top) {
    if (-1 == top) {
        printf("空栈\n");
        return -1;
    }
    printf("弹栈元素：%d\n", a[top]);
    top--;
    return top;
}

int main() {
    int a[100];
    int top = -1;
    top = push(a, top, 1);
    top = push(a, top, 2);
    top = push(a, top, 3);
    top = push(a, top, 4);
    top = pop(a, top);
    top = pop(a, top);
    top = pop(a, top);
    top = pop(a, top);
    top = pop(a, top);

    getchar();
    return 0;
}