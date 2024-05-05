/**
* Part1: 顺序查找
*/
#include <stdio.h>
#include <stdlib.h>

int main() {

    int array[] = {0,4,6,8,89,32,56,28,34};
    int length = 8;// 0索引的位置不存放要查找元素的内容，而是用来存放哨兵
    int key = 32;
    array[0] = key;
    int i = length;
    for (; array[i]!=key; --i);
    printf("index:%d",i);

}