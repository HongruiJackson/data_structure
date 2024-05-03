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

#define INFINITY (INT_MAX/2) // 最大值不便使用加法
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

void CreateExampleGraphDN(MGraph *G) {
    //1. 输入顶点数和边数
    G->vex_num = 6;
    G->arc_num = 8;
    //2. 存储顶点信息
    char chars[] = {'A','B','C','D','E','F'};
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
    G->arcs[0][2].data = 10;
    G->arcs[0][4].data = 30;
    G->arcs[0][5].data = 100;
    G->arcs[1][2].data = 5;
    G->arcs[2][3].data = 50;
    G->arcs[3][5].data = 10;
    G->arcs[4][3].data = 20;
    G->arcs[4][5].data = 60;


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

void ShortestPath_DIJ(MGraph G, char start) {
    int start_index = LocateVex(G,start);
    // 到各个点的最短路径的长度
    int *D = (int *) malloc(G.vex_num*sizeof (int));
    for (int i = 0; i < G.vex_num; ++i) {
        D[i] = INFINITY; // 到自己也记为最远，方便在min的时候方便讨论
    }

    // 从start点到各个顶点路径上的前驱节点，例如 A到C的最短是A->B->D-C，那么indexC=indexD,indexD=indexB,indexB=indexA,indexA=indexA
    int *Path = (int *) malloc(G.vex_num*sizeof (int ));
    for (int i = 0; i < G.vex_num; ++i) {
        Path[i] = -1; // -1表示不存在
    }

    // 一开始为start能够直接到达的点，故最初由路径长度和前驱结点
    for (int i = 0; i < G.vex_num; ++i) {
        if (G.arcs[start_index][i].data != INFINITY) {
            D[i] = G.arcs[start_index][i].data;
            Path[i] = start_index;
        }
    }

    //记录各点情况
    int * final = (int *) malloc(G.vex_num*sizeof (int));
    for (int i = 0; i < G.vex_num; ++i) {
        final[i] = 0;
    }
    final[start_index] = 1;
//    //数组检查
//    for (int i = 0; i < G.vex_num; ++i) {
//        printf("%d.%d.%d\n", D[i],Path[i],final[i]);
//    }

    //求解
    for (int i = 0; i < G.vex_num-1; ++i) { // 循环只需要结点数-1次
    // 求得当前D中最短的路径
        int min = INFINITY;
        int min_index = -1;
        for (int j = 0; j < G.vex_num; ++j) {
            if (!final[j])
                if(D[j] <= min) {
                    min = D[j];
                    min_index = j;
                }
        }
        final[min_index] = 1; // 标记为已“遍历”

        // 更新路径

        for (int j = 0; j < G.vex_num; ++j) {
            if(!final[j] && min +  G.arcs[min_index][j].data < D[j]) {
                D[j] =  min +  G.arcs[min_index][j].data;
                Path[j] = min_index;
            }
        }

    }


    //数组检查
//    printf("----------------------\n");
//    for (int i = 0; i < G.vex_num; ++i) {
//        printf("%d.%d.%d\n", D[i],Path[i],final[i]);
//    }

    //打印路径情况
    for (int i = 0; i < G.vex_num; ++i) {
        if (i == start_index) {
            printf("%c:self\n",G.vex[i]);
            continue;
        }
        if (Path[i] == -1) {
            printf("%c:no road\n",G.vex[i]);
            continue;
        }
        int stack[G.vex_num];
        int j=0;
        int point = i;
        while (Path[point]!=0) {
            stack[j++] = Path[point];
            point = Path[point];
        }
        stack[j++] = 0;
        printf("%c:",G.vex[i]);
        while (j!=0) {
            printf("%c->",G.vex[stack[--j]]);
        }
        printf("%c (%d)\n",G.vex[i],D[i]);


    }
}


int main() {
    MGraph G;
    CreateExampleGraphDN(&G);
    PrintGraph(G);
    ShortestPath_DIJ(G,'A');

};

