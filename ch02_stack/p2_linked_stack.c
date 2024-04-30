/**
 * Part2：链表实现栈
 */
#include <stdio.h>
#include <stdlib.h>

typedef int Status;
#define OK 0
#define Error -1

typedef int Bool;
#define true 1
#define false 0

typedef int ElemType;

typedef struct StackNode {
    ElemType data;
    struct StackNode* next;
}StackNode, *LinkedStack;

// 初始化栈
Status InitStack(LinkedStack *S) {
    *S = NULL;
    return OK;
}
// 销毁栈
Status DestroyStack(LinkedStack * S) {
    StackNode * free_p;
    while (*S != NULL) {
        free_p = *S;
        *S=(*S)->next;
    }
}

// 判断栈是否为空
Bool StackEmpty(LinkedStack S) {
    if (S == NULL) return true;
    else return false;
}

// 求链表栈长度
int StackLength(LinkedStack S) {
    int count = 0;
    while (S != NULL) {
        count++;
        S=S->next;
    }
    return count;
}

// 入栈
Status Push(LinkedStack * S, ElemType e) {
    StackNode * newNode = (StackNode*) malloc(sizeof (StackNode));
    if (!newNode) exit(1);
    newNode->data = e;
    newNode->next = *S;
    *S = newNode;
    return OK;
}

// 出栈
Status Pop(LinkedStack * S, ElemType * e) {
    if (*S == NULL) return Error;
    *e = (*S)->data;
    StackNode * p = *S;
    *S = (*S)->next;
    free(p);
    return OK;
}

int main() {
    LinkedStack S;
    InitStack(&S);
    int a;
    for (int i = 0; i < 20; ++i) {
        Push(&S, i);
    }
//    DestroyStack(&S);
    while (Pop(&S,&a)!=Error) {
        printf("%d ",a);
    }

}