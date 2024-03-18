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
    for(int i = 2; i <=5; i++) {
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
        if(NULL == temp->next){
            printf("%d\n", temp->data);
        }
        else {
            printf("%d <-> ", temp->data);
        }
        temp = temp->next;
    }
}

//删除结点的函数，data为要删除结点的数据域的值
Line* delLine(Line* head, int data) {
    Line* temp = head;
    while(temp) {
        if(data == temp->data) {
            //删除表头结点
            if(NULL == temp->prior) {
                head = head->next;
                if(head) {
                    head->prior = NULL;
                    temp->next = NULL;
                }
                free(temp);
                return head;
            }
            //删除表中结点
            if(temp->prior && temp->next) {
                temp->next->prior = temp->prior;
                temp->prior->next = temp->next;
                free(temp);
                return head;
            }
            //删除表尾结点
            if(NULL == temp->next) {
                temp->prior->next = NULL;
                temp->prior = NULL;
                free(temp);
                return head;
            }
        }
        temp = temp->next;
    }
    printf("表中没有目标元素，删除失败\n");
    return head;
}

//head为原双链表，elem表示被查找元素
int selectElem(Line* head, int elem) {
    //新建一个指针t，初始化为头指针 head
    Line* t = head;
    int i = 1;
    while(t) {
        if(elem == t->data) {
            return i;
        }
        i++;
        t = t->next;
    }
    return -1;
}

//更新函数，其中，add 表示要修改的元素，newElem 为新数据的值
void amendElem(Line* p, int oldElem, int newElem) {
    Line* temp = p;
    int find = 0;
    while(temp) {
        if(oldElem == temp->data) {
            find = 1;
            break;
        }
        temp = temp->next;
    }

    if(1 == find) {
        temp->data = newElem;
        return;
    }
    //查找失败，输出提示信息
    printf("链表中未找到目标元素，更改失败\n");
}

//释放链表中结点占用的内存空间
void free_line(Line* head) {
    Line* temp = head;
    while(temp) {
        head = head->next;
        free(temp);
        temp = head;
    }
}

int main() {
    //创建一个头指针
    Line* head = NULL;
    //调用链表创建函数
    head = initLine(head);
    printf("创建好的双向链表为:\n");
    display(head);
    printf("删除元素 2:\n");
    head = delLine(head, 2);
    display(head);
    printf("元素 3 的位置是：%d\n", selectElem(head, 3));
  
    printf("表中的元素 3 改为 6:\n");
    amendElem(head, 3, 6);
    display(head);
    free_line(head);
    getchar();
    return 0;
}