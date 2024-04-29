/**
* Part1: 十字链表存储稀疏矩阵
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
// 十字链表结点
typedef struct OLNode {
    int i, j; // 行、列下标
    ElemType e;
    struct OLNode *right; // 右指针
    struct OLNode *down; // 下指针
}OLNode, *OLink;

// 行列头指针
typedef struct {
    OLink * r_head; // 行指针数组
    OLink * c_head; // 列指针数组
    int mu; // 行数
    int nu; // 列数
    int tu; // 非零元个数
}CrossList;

// 构造无参矩阵
CrossList ConstructMatrix() {
    CrossList crossList;
    crossList.r_head = NULL;
    crossList.c_head = NULL;
    crossList.mu = 0;
    crossList.nu = 0;
    crossList.tu = 0;
    return crossList;
}

// 创建稀疏矩阵
Status CreateMatrix(CrossList * M) {
    // 输入行数、列数、非零元个数
    printf("--input row,col,non-zero element count--\n");
    scanf("%d,%d,%d",&(M->mu),&(M->nu),&(M->tu));

    // 检验数据是否合法
    if (M->tu > M->mu * M->nu) {
        M->mu = 0;
        M->nu = 0;
        M->tu = 0;
        printf("wrong input\n");
        return ERROR;
    }

    // 分配行列指针空间
    if(!(M->r_head = (OLink*) malloc((M->mu) * sizeof (OLink)))) exit(1);
    if(!(M->c_head = (OLink*) malloc((M->nu) * sizeof (OLink)))) exit(1);

    // 空间初始化
    for(int i = 0; i < M->mu; i++) {
        M->r_head[i] = NULL;
    }
    for(int i = 0; i < M->nu; i++) {
        M->c_head[i] = NULL;
    }

    //输入元素
    int i; // 行
    int j; // 列
    ElemType e; // 元素
    for(printf("input row,col,element(i==0 exit):"), scanf("%d,%d,%d", &i,&j,&e); i!=0;
        printf("input row,col,element(i==0 exit):"), scanf("%d,%d,%d", &i,&j,&e)) {
        // 判断位置是否合法
        if (i>M->mu || j>M->nu) {
            printf("wrong input\n");
            continue;
        }

        // 申请结点
        OLNode * p = (OLNode*) malloc(sizeof (OLNode));
        if (!p) exit(1); // 没申请到退出

        // 赋值
        p->i = i;
        p->j = j;
        p->e = e;

        // 插入十字链表
        // 行插入
        if (M->r_head[i-1] == NULL || M->r_head[i-1]->j > j) { // 在前面的地方，头插法
            p->right=M->r_head[i-1];
            M->r_head[i-1] = p;
        }
        else {
            OLNode * q = M->r_head[i-1];
            for (;(q->right) && q->right->j < j ; q=q->right);
            p->right = q->right;
            q->right = p;
        }
        // 列插入
        if (M->c_head[j-1] == NULL || M->c_head[j-1]->i>i) { // 在前面的地方，头插法
            p->down=M->c_head[j-1];
            M->c_head[j-1] = p;
        }
        else {
            OLNode * q = M->c_head[j-1];
            for (;(q->down) && q->down->i < i ; q=q->down);
            p->down = q->down;
            q->down = p;
        }

    }
    return OK;
}

// 以三元组输出数据(行遍历)
void PrintInfoTri(CrossList M) {
    for (int i = 0; i < M.mu; ++i) {
        while (M.r_head[i] != NULL) {
            printf("info:%d,%d,%d\n",M.r_head[i]->i,M.r_head[i]->j,M.r_head[i]->e );
            M.r_head[i] = M.r_head[i]->right;
        }
    }
}

int main() {
    CrossList  M = ConstructMatrix();
    CreateMatrix(&M);
    PrintInfoTri(M);
//    printf("%d,%d,%d\n", M.mu,M.nu,M.tu);
}