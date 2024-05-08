/**
* Part1: 直接插入排序
*/
#include<stdio.h>
#include<stdlib.h>
# define MAXSIZE 20
typedef int KeyType;

typedef struct {
    KeyType key;
}RecordType;

typedef struct {
    RecordType r [MAXSIZE+1]; //r[0]一般作为哨兵或缓冲区
    int length; // 顺序表长度
}SqList;

/**
 * 初始化顺序表
 * @param sqList
 */
void InitSqlList(SqList* sqList) {
    int num;
    int count = 0;
    do {
        printf("input data:");
        scanf("%d",&num);
        getchar();
        if (num < 0 || count > 20) break;
        sqList->r[++count].key = num;
    } while (1);
    sqList->length = count;
}

/**
 * 直接插入排序
 * @param sqList
 */
void InsertSort(SqList* sqList) {
    for (int i = 2; i <= sqList->length; ++i) {
        // 设置哨兵
        sqList->r[0] = sqList->r[i];
        int j;
        for (j = i-1;sqList->r[j].key > sqList->r[0].key ; --j) {
            sqList->r[j+1] = sqList->r[j];
        }
        sqList->r[j+1] = sqList->r[0];
    }
}

void PrintInfo(SqList sqList) {
    for (int i = 1; i <= sqList.length; ++i) {
        printf("%d ",sqList.r[i].key);
    }
    printf("\n");
}

int main() {
    SqList sqList;
    InitSqlList(&sqList);
    InsertSort(&sqList);
    PrintInfo(sqList);
};