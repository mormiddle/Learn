#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct lineStack {
    int top;
    int* items;
} LineStack;

// 初始化栈
void initLineStack(LineStack* stack);
// 入栈
void push(LineStack* stack, int elem);
// 出栈
int pop(LineStack* stack);
// 将元素压入栈底
void insertAtBottom(LineStack* stack, int item);
// 逆序栈
void reverseStack(LineStack* stack);

int main() {
    LineStack s;
    initLineStack(&s);
    push(&s, 1);  // 1
    push(&s, 2);  // 1 2
    push(&s, 3);  // 1 2 3
    push(&s, 4);  // 1 2 3 4
                  // 逆序栈
    reverseStack(&s);  // 4 3 2 1
    // 将逆序后的栈内元素全部出栈，出栈顺序是 1 2 3 4
    while (s.top != -1) {
        printf("%d ", pop(&s));
    }
    free(s.items);
    getchar();
    return 0;
}

void initLineStack(LineStack* stack) {
    stack->items = (int*)malloc(MAX_SIZE * sizeof(int));
    stack->top = -1;
}

void push(LineStack* stack, int elem) {
    if (MAX_SIZE - 1 == stack->top) {
        printf("stack is full\n");
    } else {
        stack->items[++stack->top] = elem;
    }
}

int pop(LineStack* stack) {
    if (-1 == stack->top) {
        printf("stack is empty\n");
        return -1;
    } else {
        return stack->items[stack->top--];
    }
}

void insertAtBottom(LineStack* stack, int item) {
    // 当栈为空时，直接将元素入栈
    if (-1 == stack->top) {
        push(stack, item);
    } else {
        // ① 取栈底元素
        int topitem = pop(stack);
        insertAtBottom(stack, item);
        // ② 将之前的元素逐个入栈
        push(stack, topitem);
    }
}

void reverseStack(LineStack* stack) {
    if (stack->top != -1) {
        // ① 不断地取栈顶元素
        int topitem = pop(stack);
        reverseStack(stack);
        // ② 将取出的栈顶元素依次压入栈底
        insertAtBottom(stack, topitem);
    }
}