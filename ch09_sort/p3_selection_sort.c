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

void PrintInfo(SqList sqList, char name[]);
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

void HeapAdjust(SqList * sqList, int s, int m) {
    // (s,m]索引的结点满足大顶堆，s不一定满足
    int rc = sqList->r[s].key;
    for (int i = 2*s+1; i < m; i = 2*i+1) { // i是左孩子，// 根据索引值的不同此处i和m的设置和变化会有些许不同
        // 首先比较左右子树的根的大小，为了防止没有右子树的情况，i最大只能为m-2
        if (i<m-1 && sqList->r[i].key < sqList->r[i+1].key) i++;
        // 本就是大于等于的情况意味着不需要交换位置
        if (rc >= sqList->r[i].key) break;
        sqList->r[s] = sqList->r[i];
        s = i;// 找下一个子树的情况
    }
    sqList->r[s].key = rc; // 最后空出来的位置
}

void HeapSort(SqList * sqList) {
    for (int i = (sqList->length-2)/2; i >=0 ; --i) {
        HeapAdjust(sqList,i,sqList->length);
    }
    PrintInfo(*sqList, "heap");
    for (int i = sqList->length-1; i >0 ; --i) {
        int temp = sqList->r[i].key;
        sqList->r[i].key = sqList->r[0].key;
        sqList->r[0].key = temp;
        HeapAdjust(sqList,0,i);
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

    InitExampleList(&sqList);
    HeapSort(&sqList);
    PrintInfo(sqList, "heap sort");
}