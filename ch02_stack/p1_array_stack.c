/**
 * Part1：数组实现栈
 */
#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 10

typedef int Status;
#define OK 0
#define Error -1

typedef int Bool;
#define true 1;
#define false 0;

typedef int ElemType;

typedef struct {
    ElemType * base;
    ElemType * top;
    int stack_allocated_size;
    int stack_size;
} Stack;

// 初始化栈
Status InitStack(Stack * S) {
    S->base = (ElemType*) malloc(STACK_INIT_SIZE * sizeof (ElemType));
    if (!S->base) exit(1);
    S->top = S->base;
    S->stack_allocated_size = STACK_INIT_SIZE;
    S->stack_size = STACK_INIT_SIZE-1;
    return OK;
}
// 销毁栈
Status DestroyStack(Stack * S) {
    if (S->base) {
        free(S->base);
        S->stack_size = 0;
        S->base = S->top = NULL;
    }
    return OK;
}
// 把栈置空
Status ClearStack(Stack * S) {
    S->top = S->base;
    return OK;
}

// 判断栈是否为空
Bool StackEmpty(Stack S) {
    if (S.base == S.top) return true
    else return false;
}

// 求顺序栈长度
int StackLength(Stack S) {
    // 语法知识点，指针加减
    return S.top-S.base;
}

// 入栈
Status Push(Stack * S, ElemType e) {
    if (S->top - S->base >= S->stack_size) {
        S->base = (ElemType*) realloc(S->base, (S->stack_allocated_size+STACK_INCREMENT)* sizeof (ElemType));
        if (!S->base) exit(1);
        S->top = S->base + S->stack_size;
        S->stack_allocated_size += S->stack_allocated_size+STACK_INCREMENT;
        S->stack_size += S->stack_size+STACK_INCREMENT;
    }
    *(S->top++) = e;
    return OK;
}

// 出栈
Status Pop(Stack * S, ElemType * e) {
    if(StackEmpty(*S)) return Error;
    *e = *(--S->top);
    return OK;
}

int main() {
    Stack S;
    InitStack(&S);
    Stack * point = &S;
    for (int i = 0; i < 20; ++i) {
        Push(&S,i);
    }
    int a ;
    Pop(&S, &a);
    Pop(&S, &a);
    Pop(&S, &a);
    printf("%d", a);
}
