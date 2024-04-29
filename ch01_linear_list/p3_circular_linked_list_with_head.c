/**
 * Part3：带头循环链表，尾指针
 */
#include <stdio.h>
#include <stdlib.h>

typedef int Bool;
#define OK 0
#define Err -1

typedef int Status;
#define true 1
#define false 0

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkedListTail;

/**
 * 创建线性表
 * @param L
 * @return
 */
Status InitList(LinkedListTail *L) {
    *L = (LinkedListTail) malloc(sizeof(LNode));
    (*L)->data = 0;
    (*L)->next = *L;
    return OK;
}

/**
 * 插入尾部
 * @param L
 * @param e
 * @return
 */
Status ListAdd(LinkedListTail *L, ElemType e) {
    LNode *newNode = (LNode *) malloc(sizeof(LNode));
    newNode->data = e;
    newNode->next = (*L)->next;
    (*L)->next = newNode;
    *L = newNode;
    return OK;
}

/**
 * 打印信息
 * @param L
 */
void PrintInfo(LinkedListTail L) {
    //1. 定位首元位置（因为是带头结点的）
    LNode * cur_point = L ->next ->next;
    printf("\n______\n");
    printf("ele\n");
    while (cur_point != L->next) {
        printf("%d",cur_point->data);
        if (cur_point->next == L->next) break;
        printf("->");
        cur_point = cur_point->next;
    }
    printf("\n");
}

/**
 * 将B接到A的后面
 * @param A
 * @param B
 */
void ConnectLinkedList(LinkedListTail * A, LinkedListTail * B) {
    // A的头结点
    LNode * head_A = (*A)->next;

    // A的尾巴指向B的首元结点
    (*A) -> next = (*B)->next->next;

    // 释放B的头结点
    free((*B)->next);

    // B的尾巴接回A的头结点
    (*B)->next = head_A;

    // A的尾巴移到B尾巴的位置
    *A = *B;
}

int main() {
    LinkedListTail LA = NULL;
    LinkedListTail LB = NULL;
    InitList(&LA);
    ListAdd(&LA,1);
    ListAdd(&LA,2);
    ListAdd(&LA,3);
    ListAdd(&LA,4);
    ListAdd(&LA,6);
    PrintInfo(LA);
    InitList(&LB);
    ListAdd(&LB,1);
    ListAdd(&LB,2);
    ListAdd(&LB,3);
    ListAdd(&LB,4);
    ListAdd(&LB,6);
    PrintInfo(LB);
    ConnectLinkedList(&LA, &LB);
    PrintInfo(LA);
}