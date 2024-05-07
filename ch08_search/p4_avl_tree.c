/**
* Part4: 二叉平衡树
*/
#include <stdio.h>
#include <stdlib.h>

typedef int Status;
#define OK 1
#define ERROR 0
#define EXIT 0;

typedef int Bool;
#define true 1
#define false 0

typedef int KeyType;
typedef struct {
    KeyType key;
} ElemType;
typedef struct BSTNode {
    ElemType data; // 数据
    int bf; // 结点的平衡因子
    struct BSTNode *lChild, *rChild; // 左、右孩子结点
}BSTNode, *BSTree;

// LL型，直接右旋处理，参数为失衡结点
void R_Rotate(BSTree *p) {
    BSTNode *lc = (*p)->lChild; // 左子树根结点lc
    (*p)->lChild = lc->rChild; // lc的右子树成为原失衡结点的左子树
    lc->rChild = *p; // 右旋上升
    *p = lc; // 解二级指针，重新赋值
}

// RR型，直接左旋处理
void L_Rotate(BSTree *p) {
    BSTNode * rc = (*p)->rChild;
    (*p)->rChild = rc->lChild;
    rc->lChild = *p;
    *p = rc;
}

// 左子树高度-右子树高度
#define LH 1 //左高
#define EH 0 //等高
#define RH -1 //右高

// 左平衡旋转处理，新的结点，在最小失衡结点的左侧的情况
void LeftBalance(BSTree *T) {
    BSTNode *lc = (*T)->lChild; // 左子树根结点lc
    switch (lc->bf) { // 检查左子树平衡度
        case LH: // LL型
            (*T)->bf = lc->bf = EH;// 平衡因子修改
            R_Rotate(T);
            break; //右旋
        case RH: // LR型
            BSTNode *rd = lc->rChild; // 左子树lc的右子树根
            switch (rd->bf) {
                case LH:
                    (*T)->bf = RH;
                    lc->bf = EH;
                    break;
                case EH:
                    (*T)->bf = lc->bf = EH;
                    break;
                case RH:
                    (*T)->bf = EH;
                    lc->bf = LH;
                    break;
            }
            rd->bf = EH;
            L_Rotate(&(*T)->lChild);
            R_Rotate(T);
            break;
    }
}

// 右平衡旋转处理
void RightBalance(BSTree *T) {
    BSTNode *rc = (*T)->rChild; // 右子树根结点rc
    switch (rc->bf) { // 检查左子树平衡度
        case RH: // RR型 右边的右边更高了
            (*T)->bf = rc->bf = EH;// 平衡因子修改
            L_Rotate(T);
            break; //左旋
        case LH: // RL型
            BSTNode *ld = rc->lChild; //右子树rc的右子树根
            switch (ld->bf) {
                case LH:
                    (*T)->bf = EH;
                    rc->bf = RH;
                    break;
                case EH:
                    (*T)->bf = rc->bf = EH;
                    break;
                case RH:
                    (*T)->bf = LH;
                    rc->bf = EH;
                    break;
            }
            ld->bf = EH;
            R_Rotate(&(*T)->rChild);
            L_Rotate(T);
            break;
    }
}




/**
 * 存在元素则不再进行插入
 * @param T 树，实际上是二级指针
 * @param e 要插入的元素
 * @param taller 记录是否有长高
 * @return
 */
Status InsertAVL(BSTree *T, ElemType e, Bool * taller) {
    if(!(*T)) { // 插入新的结点，由于是二级指针，故空树的时候和普通的叶子是没有什么区别的，
        *T = (BSTree) malloc(sizeof (BSTNode));
        (*T) -> data = e;
        (*T)->lChild = (*T)->rChild = NULL;
        (*T)->bf = EH; //两边都是NULL，显然等高
        *taller = true; // 新增了一个结点，树可能长高也可能不长高，交给上一层结点去判断
    } else {
        // 1. 情况一：树中已经有相同关键字的结点
        if (e.key == (*T)->data.key) { //相等的情况
            *taller = false; // 树没有变化
            return EXIT; // 退出
        }

        // 2. 情况二：当前结点的关键字大于要查询的元素关键字，故在左子树继续找
        if (e.key < (*T)->data.key) {
            if (!InsertAVL(&(*T)->lChild,e,taller)) return EXIT; // 在左子树递归当中找到了，不进行插入
            if (*taller) {
                switch ((*T)->bf) { // 递归回溯的时候检查结点，最小的失衡点
                    case LH: // 原本左子树比右子树高1，现在又taller了，意味着不平衡了，故需要左平衡处理，注意，此时的点肯定是插在左子树上的
                        LeftBalance(T);
                        *taller = false; // 已经平衡处理了，再往上回溯就代表没有长高了
                        break;
                    case EH: // 原本左右子树是等高的，现在taller了，那么左边就更高一点了
                        (*T)->bf = LH;
                        *taller = true;
                        break;
                    case RH: // 原本右子树比左子树高1，现在左边多了一个，那么该结点下的高度就平衡了
                        (*T)->bf = EH;
                        *taller = false; // 已经平衡，再往上回溯就代表没有长高了
                        break;
                }
            }
        }

        // 3. 情况二：当前结点的关键字小于要查询的元素关键字，故在右子树继续找
        if (e.key > (*T)->data.key) {//注意，此时的点肯定是插在右子树上的
            if (!InsertAVL(&(*T)->rChild,e,taller)) return EXIT; // 在右子树递归当中找到了，不进行插入
            if (*taller) {
                switch ((*T)->bf) { // 递归回溯的时候检查结点，最小的失衡点
                    case LH: // 原本左子树比右子树高1，现在又taller了，现在右边多了一个，那么该结点下的高度就平衡了
                        (*T)->bf = EH;
                        *taller = false; // 已经平衡处理了，再往上回溯就代表没有长高了
                        break;
                    case EH: // 原本左右子树是等高的，现在taller了，那么右边就更高一点了
                        (*T)->bf = RH;
                        *taller = true;
                        break;
                    case RH: // 原本右子树比左子树高1，现在又taller了，意味着不平衡了，故需要右平衡处理，注意，此时的点肯定是插在右子树上的
                        RightBalance(T);
                        *taller = false; // 已经平衡，再往上回溯就代表没有长高了
                        break;
                }
            }
        }
    }
    return OK;

}

// 递归遍历
enum definition {DLR, LDR, LRD}; // 先序、中序、后序
void visitTreeByRecursion(BSTree T, enum definition method) {
    if (T==NULL) return;
    else {
        switch (method) {
            case DLR:
                printf("%d ", T->data.key);
                visitTreeByRecursion(T->lChild, method);
                visitTreeByRecursion(T->rChild, method);
                break;
            case LDR:
                visitTreeByRecursion(T->lChild, method);
                printf("%d ", T->data.key);
                visitTreeByRecursion(T->rChild, method);
                break;
            case LRD:
                visitTreeByRecursion(T->lChild, method);
                visitTreeByRecursion(T->rChild, method);
                printf("%d ", T->data.key);
                break;
        }
    }
}
void visitTree(BSTree T) {
    printf("DLR: ");
    visitTreeByRecursion(T, DLR);
    printf("\n");
    printf("LDR: ");
    visitTreeByRecursion(T, LDR);
    printf("\n");

}


int main() {
    BSTree T = NULL;
    ElemType ele[] = {{3},{7},{98},{46},{39},{45},{1}};
    Bool taller = false;
    for (int i = 0; i < 7; ++i) {
        printf("%d---\n",i);
        InsertAVL(&T,ele[i],&taller);
        visitTree(T);
    }

}