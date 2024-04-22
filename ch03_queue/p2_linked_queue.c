/**
 * Part2：单链表实现队列
 */
#include <stdio.h>
#include <stdlib.h>
#define QUEUE_MAX_SIZE 10

typedef int Status;
#define OK 0
#define Error -1

typedef int Bool;
#define true 1;
#define false 0;

typedef int ElemType;
typedef struct QNode {
    ElemType data;
    struct QNode * next;
}QNode, *QPtr;

typedef struct {
    QPtr front;
    QPtr rear;
} LinkedQueue;

// 构造空队列，带头结点
Status InitQueue(LinkedQueue * Q) {
    Q->front = Q->rear = (QPtr) malloc(sizeof (QNode));
    if (!Q->front) exit(1);
    Q->front->next = NULL;
    return OK;
}

// 销毁队列
Status DestroyQueue(LinkedQueue * Q) {
    while (Q->front) {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}

// 判空
Bool QueueEmpty(LinkedQueue Q) {
    return Q.front == Q.rear;
}

// 队列长度
int QueueLength(LinkedQueue Q) {
    int count = 0;
    QPtr ptr = Q.front;
    while (ptr != Q.rear) {
        ptr = ptr->next;
        count++;
    }
    return count;
}

// 插入元素
Status EnQueue(LinkedQueue * Q, ElemType e) {
    QNode * newNode = (QNode *) malloc(sizeof (QNode));
    if (!newNode) exit(1);
    newNode->data = e;
    newNode->next = NULL;
    Q->rear->next = newNode;
    Q->rear = newNode;
    return OK;
}

// 删除元素
Status DeQueue(LinkedQueue *Q, ElemType *e) {
    if (Q->front == Q->rear) return Error;
    QNode * freeNode = Q->front->next;
    *e = freeNode->data;
    Q->front->next = freeNode->next;
    if (freeNode == Q->rear) Q->rear = Q->front;
    free(freeNode);
    return OK;
}

int main() {
    LinkedQueue Q;
    InitQueue(&Q);
    for (int i = 0; i < 20; ++i) {
        EnQueue(&Q,i);
    }
    printf("%d\n", QueueLength(Q));
    for (int i = 0; i < 20; ++i) {
        int a;
        DeQueue(&Q,&a);
        printf("%d", a);
        printf("->");
    }
    DestroyQueue(&Q);
}