/**
* Part2: 邻接表
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef int Status;
#define OK 1
#define ERROR 0

typedef int Bool;
#define true 1
#define false 0

#define MAX_VERTEX_NUM 20
typedef char VertexType;
typedef enum {DG,DN,UDG,UDN} GraphKind; //有向图、有向网、无向图、无向网
typedef int InfoType; // 弧信息

// 弧结点
typedef struct ArcNode {
    int adj_vex; // 弧指向的顶点的位置
    struct ArcNode *next_arc; // 指向下一条弧的指针
    InfoType * info; // 该弧相关的信息，例如权值
}ArcNode;

// 顶点信息
typedef struct VNode {
    VertexType data; // 顶点信息
    ArcNode *first_arc;
}VNode, AdjList[MAX_VERTEX_NUM];

// 图
typedef struct {
    AdjList  vertices;
    int vex_num;
    int arc_num;
    int graphKind;
}ALGraph;

int LocateVex(ALGraph G, VertexType vex) {
    for (int i = 0; i < G.vex_num; ++i) {
        if (G.vertices[i].data == vex) return i;
    }
    return -1;
}

// 构造无向网
Status CreateUDN(ALGraph *G) {
    //1. 输入顶点数和边数
    printf("input vex_num and arc_num with format like a,b: ");
    scanf("%d,%d",&(G->vex_num),&(G->arc_num));getchar();
    //2. 存储顶点信息
    for (int i = 0; i < G->vex_num; ++i) {
        printf("input node info(%d/%d): ",i+1,G->vex_num);
        scanf("%c", &G->vertices[i].data);getchar();
    }
    //3. 初始化邻接矩阵
    G->graphKind = UDN;
    for (int i = 0; i < G->vex_num; ++i) {
        G->vertices[i].first_arc = NULL;
    }
    //4. 构造邻接矩阵
    for (int i = 0; i < G->arc_num; ++i) {
        printf("input edges and weight with format like a,b,w (%d/%d): ",i+1,G->arc_num);
        char a,b;
        int w;
        scanf("%c,%c,%d",&a,&b,&w);getchar();
        int j = LocateVex(*G,a);
        int k = LocateVex(*G,b);
        ArcNode * newNode1 = (ArcNode*) malloc(sizeof (ArcNode));
        ArcNode * newNode2 = (ArcNode*) malloc(sizeof (ArcNode));
        newNode1->info = newNode2->info = (int *) malloc(sizeof (int ));
        newNode1->adj_vex = k;*(newNode1->info) = w;newNode1->next_arc=NULL;
        newNode2->adj_vex = j;*(newNode2->info) = w;newNode2->next_arc=NULL;
        ArcNode *p;
        if (G->vertices[j].first_arc == NULL || newNode1->adj_vex < G->vertices[j].first_arc->adj_vex) {
            newNode1->next_arc = G->vertices[j].first_arc;
            G->vertices[j].first_arc = newNode1;
        } else {
            p = G->vertices[j].first_arc;
            while (p->next_arc != NULL && p->next_arc->adj_vex < k) p=p->next_arc;
            newNode1->next_arc = p->next_arc;
            p->next_arc = newNode1;
        }

        if (G->vertices[k].first_arc == NULL || newNode2->adj_vex < G->vertices[k].first_arc->adj_vex) {
            newNode2->next_arc = G->vertices[k].first_arc;
            G->vertices[k].first_arc = newNode2;
        } else {
            p = G->vertices[k].first_arc;
            while (p->next_arc != NULL && p->next_arc->adj_vex < j) p=p->next_arc;
            newNode2->next_arc = p->next_arc;
            p->next_arc = newNode2;
        }


    }
    return OK;
}



    }
    return OK;
}

void PrintGraph(ALGraph G) {
    for (int i = 0; i < G.vex_num; ++i) {
        printf("%3c| ",  G.vertices[i].data);
        ArcNode * p = G.vertices[i].first_arc;
        while (p != NULL) {
            printf("%c_%d",G.vertices[p->adj_vex].data,*(p->info));
            if(p->next_arc!=NULL) printf(" -> ");
            p = p->next_arc;
        }
        printf("\n");
    }
}
int main() {
    ALGraph G;
    CreateExampleUDN(&G);
    PrintGraph(G);
}