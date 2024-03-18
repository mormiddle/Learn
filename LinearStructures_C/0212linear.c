//内容：静态链表的实现
#include <stdio.h>
#define maxSize 6
typedef struct {
    int data;
    int cur;
} component;
// 将结构体数组中所有分量链接到备用链表中
void reserveArr(component* array);
// 初始化静态链表
int initArr(component* array);
// 输出函数
void displayArr(component* array, int body);
// 从备用链表上摘下空闲节点的函数
int mallocArr(component* array);
int main() {
    component array[maxSize];
    int body = initArr(array);
    printf("静态链表为：\n");
    displayArr(array, body);
    getchar();
    return 0;
}
// 创建备用链表
void reserveArr(component* array) {
    for (int i = 0; i < maxSize; i++) {
        array[i].cur = i + 1;
        array[i].data = -1;
    }
    array[maxSize - 1].cur = 0;
}
// 提取分配空间
int mallocArr(component* array) {
    int i = array[0].cur; // 即将被使用的索引i
    if (array[0].cur) {
        array[0].cur = array[i].cur; // 更新索引，因为i已经被使用，所以指向i的下一个节点
    }
    return i;
}
// 初始化静态链表
int initArr(component* array) {
    reserveArr(array);
    int body = mallocArr(array);
    int tempBody = body;
    for(int i = 1; i < 4; i++) {
        int j = mallocArr(array);
        array[tempBody].cur = j;
        array[j].data = i;
        tempBody = j;
    }
    array[tempBody].cur = 0;
    return body;
}
void displayArr(component* array, int body) {
    int tempBody = body;  // tempBody准备做遍历使用
    while (array[tempBody].cur) {
        printf("%d,%d ", array[tempBody].data, array[tempBody].cur);
        tempBody = array[tempBody].cur;
    }
    printf("%d,%d\n", array[tempBody].data, array[tempBody].cur);
}