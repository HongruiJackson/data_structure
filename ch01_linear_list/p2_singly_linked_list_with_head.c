/**
 * Part2：带头单链表实现线性表
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
    struct LNode *next;
} LNode, *LinkedList;

/**
 * 打印信息
 * @param L
 */
void PrintInfo(LinkedList L) {
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
 * 创建线性表
 * @param L
 * @return
 */
Status InitList(LinkedList *L) {
    *L = (LinkedList) malloc(sizeof(LNode));
    (*L)->data = 0;
    (*L)->next = NULL;
    return OK;
}

/**
 * 销毁线性表释放空间
 * @param L
 */
void DestroyList(LinkedList *L) {
    LNode *cur_point = *L;
    LNode *next_point = NULL;
    while (cur_point != NULL) {
        next_point = cur_point->next;
        free(cur_point);
        cur_point = next_point;
    }
    *L = NULL;
}

/**
 * 清空线性表
 * @param L
 */
void ClearList(LinkedList *L) {
    LNode *cur_point = (*L)->next;
    LNode *next_point = NULL;
    while (cur_point != NULL) {
        next_point = cur_point->next;
        free(cur_point);
        cur_point = next_point;
    }
    (*L)->next = NULL;
}

/**
 * 判空
 * @param L
 * @return
 */
Bool ListEmpty(LinkedList L) {
    if (L->next == 0) return true
    else return false;
}

/**
 * 返回线性表长度
 * @param L
 * @return
 */
int ListLength(LinkedList L) {
    int count = 0;
    L = L->next;
    while (L != NULL) {
        count++;
        L = L->next;
    }
    return count;
}

/**
 * 获取第i个元素
 * @param L
 * @param i
 * @param e
 * @return
 */
Status GetElem(LinkedList L, int i, ElemType *e) {
//    if (i<1 || i> ListLength(L)) return Err;
//    for (int j = 0; j < i; ++j) {
//        L = L->next;
//    }
//    *e = L->data;
// 改进
    L = L->next;
    int j = 1;
    while (L && j < i) {
        L = L->next;
        j++;
    }
    if (!L || j > i) return Err;
    *e = L->data;
    return OK;
}

/**
 * 查找相同元素的自然序列号，没找到返回0
 * @param L
 * @param e
 * @return
 */
int LocateElemPosition(LinkedList L, ElemType e) {
    // 从首元元素找起
    L = L->next;
    int j = 1;
    while (L && L->data != e) {
        L = L->next;
        j++;
    }
    if (L) return j;
    return 0;
}

/**
 * 在第i个元素前(不是索引值)插入元素
 * @param L
 * @param e
 * @param i
 * @return
 */
Status ListInsert(LinkedList L, ElemType e, int i) {
    int j = 0;
    while (L && j < i - 1) { // 允许遍历到最后一个元素
        L = L->next;
        j++;
    }
    if (!L || j > i - 1) return Err;

    LNode *newNode = (LNode *) malloc(sizeof(LNode));
    newNode->data = e;
    newNode->next = L->next;
    L->next = newNode;
    return OK;
}


/**
 * 在末尾添加单个值
 * @param L
 * @param e
 * @return
 */
Status ListAdd(LinkedList L, ElemType e) {
    //1. 创建末尾的新结点
    LNode *newNode = (LNode *) malloc(sizeof(LNode));
    newNode->data = e;
    newNode->next = NULL;

    //2. 找到当前的末尾结点
    LNode *cur_point = L;
    while (cur_point->next != NULL) {
        cur_point = cur_point->next;
    }

    //3. 添加结点
    cur_point->next = newNode;
    return OK;

}

/**
 * 删除第i个元素
 * @param L
 * @param e
 * @param i
 * @return
 */
Status ListDelete(LinkedList L, ElemType *e, int i) {
    int j = 0;
    while (L->next && j < i - 1) { // 不允许遍历到最后一个元素
        L = L->next;
        j++;
    }
    if (!(L->next) || j > i - 1) return Err; // 不能是最后一个元素，不能是第0个
    LNode *free_node = L->next;
    L->next = free_node->next;
    *e = free_node->data;

    free(free_node);
    return OK;


}

/**
 * 使用链表将有序表合并到一个表当中去
 * @param LA
 * @param LB
 */
void UnionList(LinkedList LA, LinkedList LB) {
    LNode *newListPoint;
    newListPoint = LA;
    LNode *iterator_a = LA->next;
    LNode *iterator_b = LB->next;

    while (iterator_a != NULL && iterator_b != NULL) {
        if (iterator_a->data <= iterator_b->data) {
            newListPoint->next = iterator_a;
            newListPoint = iterator_a;
            iterator_a = iterator_a -> next;

        } else {
            newListPoint->next = iterator_b;
            newListPoint = iterator_b;
            iterator_b = iterator_b->next;
        }
    }
    if (iterator_a != NULL) {
        newListPoint->next = iterator_a;
    }
    if (iterator_b != NULL) {
        newListPoint->next = iterator_b;
    }

}


int main() {
    LinkedList LA = NULL;
    LinkedList LB = NULL;
    InitList(&LA);
    InitList(&LB);

    for (int i = 0; i < 10; i = i+2) {
        ListAdd(LA,i);
    }
    for (int i = 1; i < 18; i = i+2) {
        ListAdd(LB,i);
    }

    PrintInfo(LA);
    PrintInfo(LB);

    UnionList(LA,LB);
    PrintInfo(LA);


}