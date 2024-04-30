#include <stdio.h>
#include <stdlib.h>
enum definition {DLR, LDR, LRD}; // 先序、中序、后序
typedef struct BiNode{
    char data;
    struct BiNode *lChild, *rChild;
}BiNode, *BiTree;