/**
* Part3: 数组构建哈夫曼树
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef int Status;
#define OK 0
#define ERROR -1

typedef int Bool;
#define true 1
#define false 0

typedef struct {
    unsigned int weight;
    unsigned int parent, lChild, rChild;
}HTNode, *HuffmanTree;

typedef struct {
    HuffmanTree T;
    int node_count;
}*HuffmanStruct, Huf;

// 初始化结点，n为初始结点数
void InitNode(HuffmanStruct huffmanStruct, int n, int * w) {
    huffmanStruct->T = (HuffmanTree) malloc((2*n)*sizeof (HTNode));
    huffmanStruct->node_count = n;
    for (int i = 0; i < 2 * n; ++i) {
        if (i>=1 && i<=n) {
            huffmanStruct->T[i].weight = w[i-1];
        } else {
            huffmanStruct->T[i].weight = 0;
        }
        huffmanStruct->T[i].parent = 0;
        huffmanStruct->T[i].lChild = 0;
        huffmanStruct->T[i].rChild = 0;
    }
}

// 打印表结构
void PrintTable(HuffmanStruct huffmanStruct) {
    for (int i = 0; i < (huffmanStruct->node_count)*2; ++i) {
        printf("(%02d) | %02d | %02d | %02d | %02d |\n",i,huffmanStruct->T[i].weight,
               huffmanStruct->T[i].parent,huffmanStruct->T[i].lChild,huffmanStruct->T[i].rChild);
    }
}

void Select(HuffmanStruct huffmanStruct, int *a, int *b, int n) {
    int data_a = INT_MAX;
    int data_b = INT_MAX;
    for (int i = 1; i < n; ++i) {
        if (huffmanStruct->T[i].parent != 0) continue;
        int data = huffmanStruct->T[i].weight;
        if (data > data_b && data < data_a) {
            *a = i;
            data_a = data;
        } else if (data < data_b){
            *a = *b;
            data_a = data_b;
            *b = i;
            data_b = data;
        };
    }
}

void CreateHuffmanTree(HuffmanStruct huffmanStruct) {
    int a = 0;
    int b = 0;
    for (int i = huffmanStruct->node_count+1; i < 2 * huffmanStruct->node_count; ++i) {
        Select(huffmanStruct,&a,&b,i);
        huffmanStruct->T[i].lChild = b;
        huffmanStruct->T[i].rChild = a;
        huffmanStruct->T[i].weight = huffmanStruct->T[a].weight + huffmanStruct->T[b].weight;
        huffmanStruct->T[a].parent = i;
        huffmanStruct->T[b].parent = i;
    }

}


int main() {
    HuffmanStruct huffmanStruct = (HuffmanStruct) malloc(sizeof (Huf));
    int a[] = {7,19,2,6,32,3,21,10};
    InitNode(huffmanStruct,8,a);
    CreateHuffmanTree(huffmanStruct);
    PrintTable(huffmanStruct);

}