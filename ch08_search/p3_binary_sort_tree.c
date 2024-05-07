/**
* Part3: 二叉排序树
*/
#include <stdio.h>
#include <stdlib.h>

typedef int Status;
#define OK 1
#define ERROR 0

typedef int Bool;
#define true 1
#define false 0

typedef int KeyType;
typedef struct {
    KeyType key;
} ElemType;
typedef struct BSTNode {
    ElemType data;
    struct BSTNode *lChild, *rChild;
}BSTNode, *BSTree;

// 只是进行查询
BSTree SearchBST_A(BSTree T,KeyType key) {
    if((!T)|| key==T->data.key) return T; // 退出递归的情况：T为null，或者找到了匹配值
    else if (key<T->data.key)
        return SearchBST_A(T->lChild,key);
    else return SearchBST_A(T->rChild,key);
    //该代码其实等价于，只是通过对||的使用简化代码
//    if(T==NULL) return NULL;
//    else if (key == T->data.key) return T;
//    else if (key<T->data.key)
//        return SearchBST_A(T->lChild,key);
//    else return SearchBST_A(T->rChild,key);
}

/**
 * 插入不成功的时候返回双亲位置，以便能够进行插入的操作，插入成功时返回位置
 * @param T 树
 * @param key 要查找的关键字
 * @param parent 双亲结点，初始为NULL
 * @param point
 * @return
 */
Bool SearchBST_B(BSTree T,KeyType key,BSTree parent,BSTree * point) {
    if (!T) {*point = parent; return false;} // 查找不成动的时候，返回双亲结点的位置，进行插入，如果是空树，那么由于初始值的设置就会变为NULL，故在插入的函数中可以进行判断，感觉二级指针可以优化
    else if (key == T->data.key) {
        *point = T;
        printf("key:%d->%p\n",key,*point); // 用于测试
        return true;
    } // 查找成功
    else if (key < T->data.key) return SearchBST_B(T->lChild, key, T,point);
    else return SearchBST_B(T->rChild, key, T,point);
}

Bool InsertBST(BSTree *T, ElemType e) {
    BSTree point;
    if (!SearchBST_B(*T,e.key,NULL,&point)){
        BSTNode * s = (BSTNode*) malloc(sizeof (BSTNode));
        s->data = e;
        s->lChild = NULL;
        s->rChild = NULL;
        if (!point) *T = s; // 空树的情况
        else if (e.key < point->data.key) point->lChild = s;
        else point->rChild = s;
        printf("key:%d->%p\n",e.key,s); // 用于测试
        return true;
    } else return false;
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


// 删除结点的操作，采用前驱结点替代
Bool Delete(BSTree *p) {
    if(!(*p)->rChild) { // 右子树为空
        BSTree temp = *p;
        *p = (*p)->lChild;
        free(temp);
    } else if(!(*p)->lChild) { // 左子树为空
        BSTree temp = *p;
        *p = (*p)->rChild;
        free(temp);
    } else {
        BSTree temp = *p; // temp保留了前驱结点的双亲结点
        BSTree s = (*p)->lChild; // 某个节点的中序遍历前驱一定在其左子树的最右侧
        while (s->rChild) {
            temp = s;
            s=s->rChild;
        }
        (*p)->data.key = s->data.key;
        if (temp != *p) temp->rChild = s->lChild; // 被删除结点左子树的右子树不为空的时候，
        else temp->lChild = s->lChild; // 被删除结点左子树的右子树为空的时候，
    }
    return true;
}

Bool DeleteBST(BSTree *T, KeyType key) {
    if(!T) return false;
    else {
        if((*T)->data.key == key) return Delete(T);
        else if ((*T)->data.key > key) return DeleteBST(&(*T)->lChild,key);
        else return DeleteBST(&(*T)->rChild,key);
    }
}
int main() {
    BSTree T = NULL;
    ElemType e = {45};
    InsertBST(&T,e);
    ElemType ele[] = {{3},{7},{98},{46},{39},{61},{1}};
    for (int i = 0; i < 7; ++i) {
        InsertBST(&T,ele[i]);
    }
    visitTreeByRecursion(T,LDR);
    printf("\n");
    visitTreeByRecursion(T,DLR);
//    DeleteBST(&T,45);
    DeleteBST(&T,7);
    printf("\n");
    visitTreeByRecursion(T,LDR);
    printf("\n");
    visitTreeByRecursion(T,DLR);

}
