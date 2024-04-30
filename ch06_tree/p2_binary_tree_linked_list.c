/**
* Part2: 单链表表示二叉树
*/

#include <stdio.h>
#include <stdlib.h>
#include "p2_2_stack.h"

typedef int Status;
#define OK 0
#define ERROR -1

typedef int Bool;
#define true 1
#define false 0

int a = 0;

// 用于构造一棵树
void exampleTree(BiTree T) {
    T->data = 'A';//root是A
    BiNode * B = (BiNode *) malloc(sizeof (BiNode));
    B->data = 'B';
    BiNode * G = (BiNode *) malloc(sizeof (BiNode));
    G->data = 'G';
    BiNode * C = (BiNode *) malloc(sizeof (BiNode));
    C->data = 'C';
    BiNode * E = (BiNode *) malloc(sizeof (BiNode));
    E->data = 'E';
    BiNode * H = (BiNode *) malloc(sizeof (BiNode));
    H->data = 'H';
    BiNode * J = (BiNode *) malloc(sizeof (BiNode));
    J->data = 'J';
    BiNode * D = (BiNode *) malloc(sizeof (BiNode));
    D->data = 'D';
    BiNode * F = (BiNode *) malloc(sizeof (BiNode));
    F->data = 'F';
    BiNode * I = (BiNode *) malloc(sizeof (BiNode));
    I->data = 'I';
    BiNode * K = (BiNode *) malloc(sizeof (BiNode));
    K->data = 'K';
    BiNode * L = (BiNode *) malloc(sizeof (BiNode));
    L->data = 'L';
    T->lChild = B;
    T->rChild = G;
    B->lChild = C;
    B->rChild = E;
    G->lChild = H;
    G->rChild = J;
    C->lChild = NULL;
    C->rChild = D;
    E->lChild = F;
    E->rChild = NULL;
    H->lChild = I;
    H->rChild = NULL;
    J->lChild = NULL;
    J->rChild = K;
    D->lChild = NULL;
    D->rChild = NULL;
    F->lChild = NULL;
    F->rChild = NULL;
    I->lChild = NULL;
    I->rChild = NULL;
    K->lChild = L;
    K->rChild = NULL;
    L->lChild = NULL;
    L->rChild = NULL;

}

// 转成mermaid的语法
// live editor: https://mermaid.live/edit#pako:eNpt0csKgkAUgOFXkbNWyO65q7wrbapV02LQMQUvYSMR4rt3BMFmclbz_RzOYqaFqIoZGJDk1TtKac2Vi0lKZTh7TdMOIp2RB-RRpDXyiJzdTtcwvIvxZ7-J1OWZPs7laGG0RS7kGRvjciqu5OhgdEX6I12kJ3Itb_AwbqbiVo4-xt1UDEYGyFCk_vd2YV_1yTo8F6hQsLqgWYw_2vYzBHjKCkbAwGvMEtrknAApOxylDa_OnzICg9cNU6F5xpQzM6OPmhZgJDR_se4LRkCBMw
void PrintTree(BiTree T) {
    if (T == NULL) return;
    else {
        if (T->lChild!=NULL) printf("\t%c---%c\n",T->data,T->lChild->data);
        else printf("\t%c---%d[NULL]\n",T->data,a++);
        if (T->rChild!=NULL) printf("\t%c---%c\n",T->data,T->rChild->data);
        else printf("\t%c---%d[NULL]\n",T->data,a++);
        PrintTree(T->lChild);
        PrintTree(T->rChild);
    }
}

// 递归遍历
void visitTreeByRecursion(BiTree T, enum definition method) {
    if (T==NULL) return;
    else {
        switch (method) {
            case DLR:
                printf("%c ", T->data);
                visitTreeByRecursion(T->lChild, method);
                visitTreeByRecursion(T->rChild, method);
                break;
            case LDR:
                visitTreeByRecursion(T->lChild, method);
                printf("%c ", T->data);
                visitTreeByRecursion(T->rChild, method);
                break;
            case LRD:
                visitTreeByRecursion(T->lChild, method);
                visitTreeByRecursion(T->rChild, method);
                printf("%c ", T->data);
                break;
        }
    }
}

// 非递归前序遍历
void visitTreeByNonRecursionPre(BiTree T) {
    LinkedStack S;
    InitStack(&S); // 初始化栈
    Push(&S,T); // 压入根
    BiNode * p; // 接弹出的地址
    printf("Preorder traversal: ");
    while (!StackEmpty(S)) {
        Pop(&S,&p);
        printf("%c ",p->data);
        if(p->rChild != NULL) Push(&S,p->rChild);
        if(p->lChild != NULL) Push(&S,p->lChild);
    }
    printf("\n");
    DestroyStack(&S);
}

// 非递归中序遍历
void visitTreeByNonRecursionIn(BiTree T) {
    LinkedStack S;
    InitStack(&S); // 初始化栈
    Push(&S,T); // 压入根
    BiNode * p; // 接弹出或查看的地址
    printf("Inorder traversal: ");
    while (!StackEmpty(S)) {
        while (GetTop(&S ,&p) && p) Push(&S, p->lChild);
        Pop(&S,&p); // 我们是将所有存在的结点左结点放了进去，故我们需要把叶子节点的“左结点NULL”给弹出去
        if(!StackEmpty(S)) {
            Pop(&S,&p);
            printf("%c ",p->data);
            Push(&S,p->rChild); // 必须有，即使是NULL也需要
        }
    }
    printf("\n");
    DestroyStack(&S);
}

// 非递归后序遍历
void visitTreeByNonRecursionPost(BiTree T) {
    LinkedStack S;
    InitStack(&S); // 初始化栈
    BiNode * p; // 接弹出或查看的地址
    BiNode * last = NULL; // 上一次访问的地址
    printf("Postorder traversal: ");
    if (T == NULL) {
        printf("\n");
        DestroyStack(&S);
        return;
    }

    // 先走到最左的结点，将沿途的点给压栈
    while(T) {
        Push(&S,T);
        T=T->lChild;
    }

    //
    while (!StackEmpty(S)) {
        GetTop(&S,&p);
        // 判断栈顶的情况
        // 访问栈顶的情况
        if ((p->lChild == NULL && p->rChild == NULL) || last == p->rChild || (p->rChild==NULL && last==p->lChild)) {
            printf("%c ", p->data);
            last = p;
            Pop(&S,&p);
        } else { // 进入右子树的情况
            // 移入该右子树的最左侧
            BiNode * temp = p->rChild;
            while (temp) {
                Push(&S,temp);
                temp = temp->lChild;
            }
        }

    }


    printf("\n");
    DestroyStack(&S);
}

// 深度计算
int Depth(BiTree T) {
    if (T==NULL) return 0;
    else {
        int m = Depth(T->lChild);
        int n = Depth(T->rChild);
        if (m > n) return (m+1);
        else return (n+1); // +1是加上自己作为子树的根
    }
}

// 结点总数计算，自己的左子树的结点数加上右子树的结点树加上自己本身
int NodeCount(BiTree T) {
    if (T==NULL) return 0;
    else {
        return NodeCount(T->lChild) + NodeCount(T->rChild) + 1;
    }
}

// 统计叶子节点
int LeafCount(BiTree T) {
    if(T==NULL) return 0;
    if (T->lChild == NULL && T->rChild == NULL) return 1;
    else return LeafCount(T->lChild) + LeafCount(T->rChild);
}

int main() {
    BiTree T = (BiTree) malloc(sizeof (BiNode));
    exampleTree(T);
    // 测试三种递归遍历
    printf("Preorder traversal: ");
    visitTreeByRecursion(T ,DLR);
    printf("\n");
    visitTreeByNonRecursionPre(T);

    printf("Inorder traversal: ");
    visitTreeByRecursion(T ,LDR);
    printf("\n");
    visitTreeByNonRecursionIn(T);

    printf("Postorder traversal: ");
    visitTreeByRecursion(T ,LRD);
    printf("\n");
    visitTreeByNonRecursionPost(T);

    printf("depth: %d\n", Depth(T));
    printf("node count: %d\n", NodeCount(T));
    printf("leaf count: %d\n", LeafCount(T));

//    printf("\nflowchart TD\n");
//    PrintTree(T);

}