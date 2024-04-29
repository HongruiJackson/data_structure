/**
* Part1: 顺序存储表示二叉树树
*/
#include <stdio.h>
#include <stdlib.h>

typedef int Status;
#define OK 0
#define ERROR -1

typedef int Bool;
#define true 1
#define false 0

typedef int ElemType;
#define INIT_SIZE 10
typedef struct {
    ElemType * root; // 根结点
    int space; // 空间总数
} SqBiTree;

// 初始化树
Status InitTree(SqBiTree * T) {
    T->root = (ElemType * ) malloc(INIT_SIZE * sizeof(ElemType));
    if(!T->root) {
        printf("\n[Error] no enough memory\n");
        exit(1);
    }
    for (int i = 0; i < INIT_SIZE; ++i) {
        T->root[i] = 0;
    }
    T->space = INIT_SIZE;
    return OK;
}

// 往结点中添加数据，输入为大于等于1的数字
Status Assign(SqBiTree * T, int index, ElemType e) {
    int position = index -1;
    if (index >= T->space) {
        ElemType * new_root = (ElemType *) realloc(T->root,index * sizeof (ElemType));
        if(!new_root) {
            printf("\n[Error] no enough memory\n");
            exit(1);
        }
        for (int i = T->space; i < index; ++i) {
            T->root[i] = 0;
        }
        T->root = new_root;
        T->space = index;
    }
    T->root[position] = e;
    return OK;
}




int main() {
    SqBiTree T;
    InitTree(&T);
    Assign(&T,17,12);
    printf("%d",T.root[16]);
}