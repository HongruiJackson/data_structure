/**
 * Part1：数组实现循环队列
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
typedef struct {
    ElemType * base;
    int front;
    int rear;
} Queue;
// 初始化队列
Status InitQueue(Queue * Q) {
    Q->base = (ElemType *) malloc (QUEUE_MAX_SIZE * sizeof (ElemType));
    if (!Q->base) exit(1);
    Q->rear = Q->front = 0;
    return OK;
}
// 销毁队列
Status DestroyQueue(Queue * Q) {
    free(Q->base);
    Q->front = 0;
    Q->rear = 0;
    return OK;
}
// 清除队列
Status ClearQueue(Queue * Q) {
    Q->rear = Q->front = 0;
    return OK;
}
// 判空
Bool QueueEmpty(Queue Q) {
    return Q.front == Q.rear;
}

// 队列长度
int QueueLength(Queue Q) {
    return (Q.rear-Q.front + QUEUE_MAX_SIZE) % QUEUE_MAX_SIZE;
}

// 插入元素
Status EnQueue(Queue * Q, ElemType e) {
    // 此处选用的是牺牲一个空间来判断是否为满
    if ((Q->rear+1) % QUEUE_MAX_SIZE == Q->front) return Error;
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear+1) % QUEUE_MAX_SIZE;
    return OK;
}

// 删除元素
Status DeQueue(Queue * Q, ElemType * e) {
    // 此处选用的是牺牲一个空间来判断是否为满
    if (Q->rear == Q->front) return Error;
    *e = Q->base[Q->front];
    Q->front = (Q->front+1) % QUEUE_MAX_SIZE;
    return OK;
}

int main() {
    Queue Q;
    InitQueue(&Q);
    for (int i = 0; i < 20; ++i) {
        EnQueue(&Q,i);
    }
    for (int i = 0; i < 20; ++i) {
        int a;
        DeQueue(&Q,&a);
        printf("%d", a);
        printf("->");
    }
    DestroyQueue(&Q);
}
