#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 10
#define LIST_INCREMENT 10

#define OK 0
#define Err -1

#define true 1;
#define false 0;

typedef int Bool;
typedef int Status;
typedef int ElemType;

typedef struct {
    ElemType* elem;
    int length;
    int list_size;
} SqlList;
/**
 * 打印线性表信息
 */
void PrintInfo(SqlList L) {
    printf("\n_____________\n");
    printf("ele:\n");
    for (int i = 0; i < L.length; ++i) {
        printf("%d", L.elem[i]);
        if (i == L.length-1) {
            printf("\n");
            break;
        }
        printf("->");
    }
    printf("length:%d\n",L.length);
    printf("list_size:%d\n",L.list_size);
}

/**
 * 创建线性表
 * @param L
 * @return
 */
Status InitList(SqlList* L) {
    L->elem = (ElemType*) malloc(LIST_INIT_SIZE * sizeof (SqlList));
    if(! L->elem) return Err;
    L->length = 0;
    L->list_size = LIST_INIT_SIZE;
    return OK;
}
/**
 * 销毁线性表释放空间
 * @param L
 */
void DestroyList(SqlList* L) {
    if (L->elem) free(L->elem);
}
/**
 * 清空线性表
 * @param L
 * @return
 */
 void ClearList(SqlList* L) {
     L->length = 0;
 }

 /**
  * 判空
  * @param L
  * @return
  */
 Bool ListEmpty(SqlList L) {
     if (L.length == 0) return true
     else return false;
 }

 /**
  * 返回线性表长度
  * @param L
  * @return
  */
 int ListLength(SqlList L) {
     return L.length;
 }

 /**
  * 获取第i个元素
  * @param L 线性表
  * @param i 第i个元素
  * @return 状态
  */
 Status GetElem(SqlList L,int i, ElemType* e) {
     if (i<1 || i>L.length) return Err;
     *e = L.elem[i-1];
     return OK;
 }

 /**
  * 查找相同元素的自然序列号
  * @param L
  * @param e
  * @return
  */
 int LocateElem(SqlList L, ElemType e) {
    //这里采用比较简单的遍历算法
     for (int i = 0; i < L.length; ++i) {
         if (L.elem[i] == e) return i+1;
     }
     return 0;
 }

 /**
  * 获取某个元素的前驱
  * @param L
  * @param cur_e
  * @param pre_e
  * @return
  */
 Status PriorElem(SqlList L, ElemType cur_e, ElemType* pre_e) {
     // 获取当前元素的位置
     int cur_location = LocateElem(L,cur_e);
     // 如果没有找到、或者是开始元素，则返回错误
     if (cur_location == 0 || cur_location == 1) return Err;
     GetElem(L,cur_location-1, pre_e);
     return OK;
 }

/**
* 获取某个元素的后继
* @param L
* @param cur_e
* @param next_e
* @return
*/
Status NextElem(SqlList L, ElemType cur_e, ElemType* next_e) {
    // 获取当前元素的位置
    int cur_location = LocateElem(L,cur_e);
    // 如果没有找到、或者是最后一个元素，则返回错误
    if (cur_location == 0 || cur_location == L.length) return Err;
    GetElem(L,cur_location+1, next_e);
    return OK;
}

/**
 * 在第i个元素前(不是索引值)插入元素
 * @param L
 * @param i
 * @param e
 * @return
 */
Status ListInsert(SqlList* L, ElemType e,int i ) {
    int position;// 插入的位置，不是索引值
    //1. 判断i值，即插入位置合不合法，如果i为0，默认插入到末尾
    if (i==0) position = L->length + 1;
    else if (i<1 || i>L->length+1) return Err;
    else position = i;
    //2. 当空间已经满了，则要进行扩容
    if (L->length >= L->list_size) {
        ElemType* new_base = (ElemType*) realloc(L->elem,(L->list_size+LIST_INCREMENT) * sizeof (ElemType));
        if (! new_base) return Err;
        L->elem = new_base;
        L->list_size = L->list_size+LIST_INCREMENT;
    }
    //3. 位置后移
    for (int j = L->length-1; j >=position -1 ; j--) {
        L->elem[j+1] = L->elem[j];
    }
    //4. 插入合适的位置
    L->elem[position-1] = e;
    //5. 更新长度
    L->length++;
    return OK;
}

/**
 * 删除指定位置的元素
 * @param L 线性表
 * @param e 用来接收删除的元素
 * @param i 元素位置
 * @return
 */
Status ListDelete(SqlList* L, ElemType* e,int i) {
    int position; // 元素位置，从1开始，不是索引值
    //1. 判断i值，即插入位置合不合法，如果i为0，默认删除末尾的元素
    if (i==0) position = L->length;
    else if (i<1 || i>L->length+1) return Err;
    else position = i;
    //2. 获取元素
    *e = L->elem[position-1];

    //3. 移动位置
    for (int j = position; j < L->length ; j++) {
        L->elem[j - 1] = L->elem[j];
    }
    //4. 更新长度
    L->length--;
    return OK;

}



int main() {
    SqlList list;
    InitList(&list);

    for (int i = 0; i < 20; ++i) {
        ListInsert(&list,i,0);
    }
    PrintInfo(list);
    ListInsert(&list,100,4);
    ListInsert(&list,200,19);
    PrintInfo(list);

    ElemType e;
    printf("\n_____________\n");
    for (int i = 0; i < 10; ++i) {
        ListDelete(&list,&e,0);
        printf("e:%d",e);
    }
    ListDelete(&list,&e,4);
    PrintInfo(list);

    DestroyList(&list);

}