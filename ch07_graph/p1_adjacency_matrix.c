/**
* Part1: 邻接矩阵（数组表示法）
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

#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20
typedef int VRType;
typedef char VertexType;
typedef enum {DG,DN,UDG,UDN} GraphKind; //有向图、有向网、无向图、无向网
typedef struct ArcCell {
    VRType data;
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
    VertexType vex[MAX_VERTEX_NUM];// 顶点向量存储顶点
    AdjMatrix arcs; // 邻接矩阵
    int vex_num; // 顶点数
    int arc_num; // 边数、弧数
    GraphKind graphKind; // 图的类型
}MGraph;

int LocateVex(MGraph G, VertexType vex) {
    for (int i = 0; i < G.vex_num; ++i) {
        if (G.vex[i] == vex) return i;
    }
    return -1;
}

// 构造无向网
Status CreateUDN(MGraph *G) {
    //1. 输入顶点数和边数
    printf("input vex_num and arc_num with format like a,b: ");
    scanf("%d,%d",&(G->vex_num),&(G->arc_num));getchar();
    //2. 存储顶点信息
    for (int i = 0; i < G->vex_num; ++i) {
        printf("input node info(%d/%d): ",i+1,G->vex_num);
        scanf("%c", &G->vex[i]);getchar();
    }
    //3. 初始化邻接矩阵
    G->graphKind = UDN;
    for (int i = 0; i < G->vex_num; ++i) {
        for (int j = 0; j < G->vex_num; ++j) {
            G->arcs[i][j].data = INFINITY;
        }
    }
    //4. 构造邻接矩阵
    for (int i = 0; i < G->arc_num; ++i) {
        printf("input edges and weight with format like a,b,w (%d/%d): ",i+1,G->arc_num);
        char a,b;
        int w;
        scanf("%c,%c,%d",&a,&b,&w);getchar();
        int j = LocateVex(*G,a);
        int k = LocateVex(*G,b);
        G->arcs[j][k].data = G->arcs[k][j].data = w;
    }
    return OK;
}

// 打印矩阵
void PrintGraph(MGraph G) {
    printf("   |");
    for (int i = 0; i < G.vex_num; ++i) {
        printf("%3c|", G.vex[i]);
    }
    printf("\n");
    for (int i = 0; i < G.vex_num; ++i) {
        printf("%3c|", G.vex[i]);
        for (int j = 0; j < G.vex_num; ++j) {
            if(G.arcs[i][j].data == INFINITY) printf(" --|");
            else printf("%3d|",G.arcs[i][j].data);
        }
        printf("\n");
    }
}

void CreateExampleGraph(MGraph *G) {
    //1. 输入顶点数和边数
    G->vex_num = 9;
    G->arc_num = 17;
    //2. 存储顶点信息
    char chars[] = {'A','B','C','D','E','F','G','H','I'};
    for (int i = 0; i < G->vex_num; ++i) {
        G->vex[i] = chars[i];
    }
    //3. 初始化邻接矩阵
    G->graphKind = UDN;
    for (int i = 0; i < G->vex_num; ++i) {
        for (int j = 0; j < G->vex_num; ++j) {
            G->arcs[i][j].data = INFINITY;
        }
    }
    //4. 构造邻接矩阵
    G->arcs[0][1].data = G->arcs[1][0].data = 7;
    G->arcs[1][2].data = G->arcs[2][1].data = 7;
    G->arcs[1][4].data = G->arcs[4][1].data = 5;
    G->arcs[1][5].data = G->arcs[5][1].data = 6;
    G->arcs[2][3].data = G->arcs[3][2].data = 3;
    G->arcs[2][4].data = G->arcs[4][2].data = 2;
    G->arcs[3][4].data = G->arcs[4][3].data = 5;
    G->arcs[3][5].data = G->arcs[5][3].data = 7;
    G->arcs[3][7].data = G->arcs[7][3].data = 4;
    G->arcs[3][8].data = G->arcs[8][3].data = 10;
    G->arcs[4][6].data = G->arcs[6][4].data = 2;
    G->arcs[4][7].data = G->arcs[7][4].data = 1;
    G->arcs[5][7].data = G->arcs[7][5].data = 3;
    G->arcs[5][8].data = G->arcs[8][5].data = 9;
    G->arcs[6][7].data = G->arcs[7][6].data = 3;
    G->arcs[6][8].data = G->arcs[8][6].data = 9;
    G->arcs[7][8].data = G->arcs[8][7].data = 6;

}

// 深度优先遍历
void DFS(MGraph G, int v, int visited[]) {
    printf("%c ",G.vex[v]);
    visited[v] = 1;
    for (int i = 0; i < G.vex_num; ++i) {
        if((G.arcs[v][i].data!=INFINITY)&&(!visited[i])) DFS(G,i,visited);
    }
}

void DFSTraverse(MGraph G, int start) {
    int visited[G.vex_num];
    for (int i = 0; i < G.vex_num; ++i) {
        visited[i] = 0;
    }
    DFS(G,start,visited); // 如果是非连通图，需要在此处进行修改
    printf("\n");
}


int main() {
    MGraph G;
    CreateExampleGraph(&G);
    PrintGraph(G);
    DFSTraverse(G,0);
};

