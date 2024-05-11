/**
* Part3: 选择排序
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
 * 初始化一个数组
 * @param sqList
 */
void InitExampleList(SqList * sqList) {
    int array[] = {89,38,65,97,38,13,27,90,43,39,59};
    for (int i = 0; i < 11; ++i) {
        sqList->r[i].key = array[i];
    }
    sqList->length = 11;
}

/**
 * 简单选择排序
 * @param sqList
 */
void SimpleSelectionSort(SqList * sqList) {
    for (int i = 0; i < sqList->length-1; ++i) {
        int min_index = i;
        for (int j = i+1; j < sqList->length; ++j) {
            if (sqList->r[min_index].key > sqList->r[j].key) min_index = j;
        }
        if (min_index != i) {
            int temp = sqList->r[i].key;
            sqList->r[i].key = sqList->r[min_index].key;
            sqList->r[min_index].key = temp;
        }
    }
}


void PrintInfo(SqList sqList, char name[]) {
    printf("%s: ",name);
    for (int i = 0; i < sqList.length; ++i) {
        printf("%d ",sqList.r[i].key);
    }
    printf("\n");
}

int main() {
    SqList sqList;
    InitExampleList(&sqList);
    SimpleSelectionSort(&sqList);
    PrintInfo(sqList, "simple selection sort");
}