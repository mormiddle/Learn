//内容：链表的反转 
#include <stdio.h>
#include <stdlib.h>

typedef struct Link {
    int elem;
    struct Link* next;
} link;

link* initLink();
void display(link* p);
// 迭代反转链表
link* iteration_reverse(link* head);
// 递归反转链表
link* recursive_reverse(link* head);
// 头插法反转链表
link* head_reverse(link* head);
// 就地逆置法反转链表
link* local_reverse(link* head);

int main() {
    link* head1 = initLink();
    display(head1);
    head1 = iteration_reverse(head1);
    printf("使用迭代反转链表：\n");
    display(head1);

    head1 = initLink();
    head1 = recursive_reverse(head1);
    printf("使用递归反转链表: \n");
    display(head1);

    head1 = initLink();
    head1 = head_reverse(head1);
    printf("使用头插法反转链表：\n");
    display(head1);

    head1 = initLink();
    head1 = local_reverse(head1);
    printf("使用就地逆置法反转链表：\n");
    display(head1);  
    
    getchar();
    return 0;
}

link* initLink() {
    link* p = (link*)malloc(sizeof(link));
    p->elem = 1;
    p->next = NULL;
    link* temp = p;
    for (int i = 2; i < 5; i++) {
        link* a = (link*)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        temp->next = a;
        temp = a;
    }
    return p;
}

void display(link* p) {
    link* temp = p;
    while (temp) {
        printf("%d ", temp->elem);
        temp = temp->next;
    }
    printf("\n");
}

link* iteration_reverse(link* head) {
    if(NULL == head || NULL == head->next)
    {
        return head;
    }
    link* big = NULL;
    link* mid = head;
    link* end = head->next;
    while(1) {
        //将当前节点指向左边
        mid->next = big;
        //如果当前节点的右边到null，说明当前节点已经是最后一个节点
        //那就跳出循环
        if(NULL == end) {
            break;
        }
        //将三个指针整体向右移动
        big = mid;
        mid = end;
        end = end->next;
    }
    head = mid;
    return head;

}

link* recursive_reverse(link* head) {
    if(NULL == head || NULL == head->next) {
        return head;
    }
    else {
        //循环到最后一层后，输出是尾节点，而尾节点就是新链表的首结点
        link* new_head = recursive_reverse(head->next);

        //下面的步骤是循环跳出之后，第一个跳出层的操作，也是每一层的操作，用第一层来理解
        //因为最后一层的时候head是最后一个节点，所以第一次跳出的时候head是倒数二个节点。
        //将head后的节点指向head，但是head指向空（方便下一层继续指向，到最后一次跳出之后，新的尾节点直接指向空)
        head->next->next = head;
        head->next = NULL;

        //每一层的head都是不一样的，但是返回给上一层的是new_head，并且new_head也是幅值给new_head，所以new_head一直是新的首结点（原来的尾节点）
        return new_head;
    }

}

link* head_reverse(link* head) {
    if(NULL == head || NULL == head) {
        return NULL;
    }
    // new_head是新的链表
    // temp属于临时指针，用来存储需要存放进new_head是新的链表的节点
    link* new_head = NULL;
    link* temp = NULL;
    //当老链表没有节点时，不再进行转移
    while(head != NULL) {
        //临时指针存储需要放入新链表的节点
        temp = head;
        //旧链表舍弃已经放入临时指针的节点，直接指向下一个节点
        head = head->next;

        //需要接入的节点指向新链表的头节点
        temp->next = new_head;
        //更新头结点
        new_head = temp;
    }
    return new_head;
}

link* local_reverse(link* head) {
    if(NULL == head || NULL == head->next) {
        return head;
    }
    //beg是旧链表的表头
    link* beg = head;
    //end是需要插入新表头的节点
    link* end = head->next;
    while(end != NULL) {
        //删除旧链表中end代表的节点
        beg->next = end->next;
        //将end的下一位设置为原来的头结点，这个时候end成为新的头结点
        end->next = head;
        head = end;

        //end接续指向下一个需要插入新表的节点
        end = beg->next;
    }
    return head;
}