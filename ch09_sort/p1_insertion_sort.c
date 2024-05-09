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
 *
 * @param sqList
 */
void InitExampleList(SqList * sqList) {
    //0位置为哨兵
    int array[] = {-1,38,65,97,38,13,27,90,43,39,59};
    for (int i = 0; i <= 10; ++i) {
        sqList->r[i].key = array[i];
    }
    sqList->length = 10;
}

/**
 * 直接插入排序
 * @param sqList
 */
void StraightInsertSort(SqList* sqList) {
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

void BinaryInsertSort(SqList* sqList) {
    int low;
    for (int i = 2; i <= sqList->length; ++i) {
        low = 1;
        int high = i-1;
        sqList->r[0].key = sqList->r[i].key;
        while (low <= high) {
            int mid = (low+high)/2;
            if (sqList->r[mid].key == sqList->r[0].key) {
                low = mid+1;
                break;
            } else if (sqList->r[mid].key < sqList->r[0].key) low = mid+1;
            else high = mid -1;
        }
        for (int j = i-1; j >= low ; --j) {
            sqList->r[j+1] = sqList->r[j];
        }
        sqList->r[low].key = sqList->r[0].key;

    }
}

void PrintInfo(SqList sqList, char name[]) {
    printf("%s: ",name);
    for (int i = 1; i <= sqList.length; ++i) {
        printf("%d ",sqList.r[i].key);
    }
    printf("\n");
}

int main() {
    SqList sqList;
    InitExampleList(&sqList);
    PrintInfo(sqList,"original");
    StraightInsertSort(&sqList);
    PrintInfo(sqList,"straight_insertion_sort");

    InitExampleList(&sqList);
    BinaryInsertSort(&sqList);
    PrintInfo(sqList, "binary_insertion_sort");
};