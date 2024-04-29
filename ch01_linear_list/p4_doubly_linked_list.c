/**
 * Part4：双向链表，非循环
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
    struct LNode *prior;
    struct LNode *next;
} LNode, *DuLinkedList;

/**
 * 创建线性表
 * @param L
 * @return
 */
Status InitList(DuLinkedList *L) {
    *L = (DuLinkedList) malloc(sizeof(LNode));
    (*L)->data = 0;
    (*L)->prior = NULL;
    (*L)->next = NULL;
    return OK;
}

/**
 * 末尾添加元素
 * @param L
 * @param e
 */
void ListAdd(DuLinkedList L, ElemType e) {
    LNode *newNode = (LNode *) malloc(sizeof(LNode));
    while (L->next != NULL) L = L->next;
    newNode->data = e;
    newNode->prior = L;
    newNode->next = NULL;
    L->next = newNode;

}

/**
 * 打印元素信息
 * @param L
 */
void PrintInfo(DuLinkedList L) {
    //1. 定位首元位置（因为是带头结点的）
    LNode *cur_point = L->next;
    printf("\n______\n");
    printf("ele\n");
    while (cur_point != NULL) {
        printf("%d", cur_point->data);
        if (cur_point->next == NULL) break;
        printf("->");
        cur_point = cur_point->next;
    }
    printf("\n");
}

/**
 * 在第i个位置之前插入元素e，插入位置不能为0或大于长度+1
 * @param L
 * @param i
 * @param e
 */
Status ListInsert(DuLinkedList  L, int i, ElemType e) {
    int j = 0;
    //为了能够在末尾插入，还是需要定位到前一个结点
    while(L && j < i - 1) { // 允许遍历到最后一个元素
        L = L ->next;
        j++;
    }
    if (!L || j > i -1) return Err;
    LNode * newNode = (LNode *) malloc(sizeof(LNode));
    newNode->data = e;
    newNode->next = L->next;
    if (L->next != NULL) L->next->prior = newNode; // 如果是末尾节点的话，它的下一个“结点NULL”是没有前驱结点，需要特殊讨论
    newNode->prior = L;
    L->next = newNode;

    return OK;
}


/**
 * 删除第i个位置的元素
 * @param L
 * @param i
 * @param e
 */
Status ListDelete(DuLinkedList  L, int i) {
    int j = 0;
    while(L && j < i) {
        L = L ->next;
        j++;
    }
    if (!L || j > i) return Err;

    L->prior->next = L->next;
    if (L->next != NULL) L->next->prior = L->prior;
    free(L);
    return OK;
}

int main() {
    DuLinkedList L;
    InitList(&L);

    ListAdd(L, 1);
    ListAdd(L, 2);
    ListAdd(L, 3);
    ListAdd(L, 4);
    ListAdd(L, 5);
    ListAdd(L, 6);
    ListInsert(L,5,7);
    ListDelete(L,7);
    ListDelete(L,1);
    ListDelete(L,2);
    PrintInfo(L);
}