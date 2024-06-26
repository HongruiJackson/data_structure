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

struct edge {
    char a;
    char b;
    int weight;
};

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

// 构造例子无向网
Status CreateExampleUDN(ALGraph *G) {
    //1. 输入顶点数和边数
    G->vex_num = 6;
    G->arc_num = 10;
    //2. 存储顶点信息
    char chars[] = {'A','B','C','D','E','F'};
    for (int i = 0; i < G->vex_num; ++i) {
        G->vertices[i].data = chars[i];
    }
    //3. 初始化邻接矩阵
    G->graphKind = UDN;
    for (int i = 0; i < G->vex_num; ++i) {
        G->vertices[i].first_arc = NULL;
    }
    //4. 构造邻接矩阵
    struct edge edges[] = {
            {'A','B',6},{'A','C',1},{'A','D',5},
            {'C','B',5},{'D','C',5},{'B','E',3},
            {'C','E',6},{'F','C',4},{'F','D',2},
            {'F','E',6}
    };
    for (int i = 0; i < G->arc_num; ++i) {
        char a,b;
        int w;
        a = edges[i].a;
        b = edges[i].b;
        w = edges[i].weight;
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

// Prim算法
// 辅助矩阵
typedef struct {
    VertexType data;
    int low_cost;
}closeEdgeMatrix[MAX_VERTEX_NUM];
/**
 * Prim算法求最小生成树
 * @param G 图
 * @param u 起始顶点
 */
void MiniSpanTree_PRIM(ALGraph G,VertexType u) {
    closeEdgeMatrix closeEdge;
    int k = LocateVex(G, u);
    // 初始化辅助矩阵
    for (int i = 0; i < G.vex_num; ++i) {
        closeEdge[i].data = '$';
        closeEdge[i].low_cost = INT_MAX;
    }
    ArcNode * p = G.vertices[k].first_arc;
    while (p!=NULL) {
        closeEdge[p->adj_vex].data = G.vertices[k].data;
        closeEdge[p->adj_vex].low_cost = *(p->info);
        p=p->next_arc;
    }
    closeEdge[k].data = '$';
    closeEdge[k].low_cost = 0;



    for (int i = 0; i < G.vex_num-1; ++i) {

        //打印数组情况，用于检查
        for (int z = 0; z < G.vex_num; ++z) {
            printf("%c.%d ",closeEdge[z].data,closeEdge[z].low_cost);
        }

        int min = INT_MAX;
        int index = G.vex_num;
        for (int j = 0; j < G.vex_num; ++j) {
            if (closeEdge[j].low_cost!=0) {
                if(closeEdge[j].low_cost < min) {
                    index = j;
                    min = closeEdge[j].low_cost;
                }
            }
        }
        printf("%c->%c\n",closeEdge[index].data,G.vertices[index].data);
        k = index;
        closeEdge[k].data = '$';
        closeEdge[k].low_cost = 0;

        p = G.vertices[k].first_arc;
        while (p!=NULL) {
            if (*(p->info) < closeEdge[p->adj_vex].low_cost && closeEdge[p->adj_vex].low_cost != 0) {
                closeEdge[p->adj_vex].data = G.vertices[k].data;
                closeEdge[p->adj_vex].low_cost = *(p->info) ;
            }
            p = p->next_arc;
        }
    }

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
    MiniSpanTree_PRIM(G,'A');

}