#include <stdio.h>
#include <stdlib.h>

typedef struct lineStack {
    int data;
    struct lineStack* next;
} LineStack;

LineStack* push(LineStack* stack, int a) {
    LineStack* line = (LineStack*)malloc(sizeof(LineStack));
    line->data = a;
    line->next = stack;
    return line;
}

LineStack* pop(LineStack* stack) {
    if (stack) {
        LineStack* p = stack;
        printf("弹出的栈数据为：%d\n", stack->data);
        stack = stack->next;
        if (stack) {
            printf("栈顶元素为：%d\n", stack->data);
        } else {
            printf("栈已空\n");
        }
        free(p);
    } else {
        printf("空栈\n");
        return stack;
    }
    return stack;
}

int main() {
    LineStack* stack = NULL;
    stack = push(stack, 1);
    stack = push(stack, 2);
    stack = push(stack, 3);
    stack = push(stack, 4);
    stack = pop(stack);
    stack = pop(stack);
    stack = pop(stack);
    stack = pop(stack);
    stack = pop(stack);

    getchar();
    return 0;
}