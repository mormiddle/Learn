#include <stdio.h>
#include <stdlib.h>

typedef struct Link {
    int elem;
    struct Link* next;
} link;

link* initLInk();
// 链表插入的函数，p是链表，elem是插入的结点的数据域，add是插入的位置
link* inserElem(link* p, int elem, int add);
// 删除结点的函数，p代表操作链表，add代表删除节点的位置
link* delElem(link* p, int add);
// 查找结点的函数，elem为目标结点的数据域的值
int selectElem(link* p, int elem);
// 更新结点的函数，newElem为新的数据域的值
link* amendElem(link* p, int add, int newElem);
void display(link* p);

int main() {
    // 初始化链表（1，2，3，4）
    printf("初始化链表为： \n");
    link* p = initLInk();
    display(p);

    printf("在第4的位置插入元素5: \n");
    p = inserElem(p, 5, 4);
    display(p);

    printf("删除元素3:\n");
    p = delElem(p, 3);
    display(p);

    printf("查找元素2的位置为: \n");
    int address = selectElem(p, 2);
    if(address == -1) {
        printf("没有该元素");
    }
    else {
        printf("元素2的位置为: %d\n", address);
    }

    printf("更改第3的位置上的数据为7: \n");
    p =amendElem(p, 3, 7);
    display(p);

    getchar();
    return 0;
}

link* initLInk() {
    link* p = (link*)malloc(sizeof(link));
    link* temp = p;
    for(int i = 1; i < 5; i++) {
        link* a = (link*)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        temp->next = a;
        temp =a;
    }

    return p;
}

link* inserElem(link* p, int elem, int add) {
    link* temp = p;
    for(int i = 1; i < add; i++) {
        temp = temp->next;
        if(NULL == temp) {
            printf("插入的位置不存在\n");
            return p;
        }
    }

    link* c = (link*)malloc(sizeof(link));
    c->elem = elem;
    c->next = temp->next;
    temp->next = c;
    return p;

}

link* delElem(link*p, int add) {
    link* temp = p;
    for(int i = 1; i < add; i++) {
        temp = temp->next;
        if(NULL == temp->next) {
            printf("删除的位置不存在\n");
            return p;
        }
    }

    link* del = temp->next;
    temp->next = temp->next->next;
    free(del);
    return p;
}

int selectElem(link* p, int elem) {
    link* temp = p;
    int i = 1;
    while(temp->next) {
        temp = temp->next;
        if(elem == temp->elem) {
            return i;
        }
        i++;
    }
    return -1;
}

link* amendElem(link* p, int add, int newElem) {
    link* temp = p;
    for(int i = 1; i < add; i++) {
        temp = temp->next;
        if(NULL == temp->next) {
            printf("需要替换的位置不存在\n");
            return p;
        }
    }

    temp = temp->next;
    temp->elem = newElem;
    return p;
}

void display(link* p) {
    link* temp = p;
    while(temp->next) {
        temp = temp->next;
        printf("%d ", temp->elem);
    }
    printf("\n");
}