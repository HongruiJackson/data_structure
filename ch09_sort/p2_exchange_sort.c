/**
* Part2: 交换排序
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
 *
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
 * 冒泡排序
 * @param sqList
 */
void BubbleSort(SqList * sqList) {
    for (int i = 0; i < sqList->length-1; ++i) {
        for (int j = 0; j < sqList->length-1-i; ++j) {
            if (sqList->r[j].key > sqList->r[j+1].key) {
                int temp = sqList->r[j].key;
                sqList->r[j].key = sqList->r[j+1].key;
                sqList->r[j+1].key = temp;
            }
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
    BubbleSort(&sqList);
    PrintInfo(sqList, "bubble_sort");

}