//step 0) 임의의 정점을 선택해 비어있는 T에 포함시킴. (이제 T는 노드가 한 개인 트리)

//step 1) T 에 있는 노드와 T 에 없는 노드의 간선 중 가중치가 최소인 간선을 찾는다.

//step 2) 찾은 간선이 연결하는 두 노드 중, T에 없던 노드를 T에 포함시킨다.
//        (step1 에서 찾은 간선도 같이 T에 포함시킴)
//
// step 3) 모든 노드가 T에 포함될 때까지 1, 2를 반복한다

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define	INF 1000L

typedef struct GraphType {
	int n;		// 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

// 최소 dist[v] 값을 갖는 정점을 반환
int get_min_vertex(int n)
{
	int v, i;
	for ( i = 0; i < n; i++)
		if (!selected[i]) {
			v = i;
			break;
		}
	for (i = 0; i < n; i++)
		if (!selected[i] && (distance[i] < distance[v])) v = i;
	return (v);
}

void prim(GraphType* g, int s)
{
	int i, u, v;

	for (u = 0; u < g->n; u++)
		distance[u] = INF;
	distance[s] = 0;
	for (i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		if (distance[u] == INF) return;
		printf("정점 %d 추가 \n", u);
		for (v = 0; v < g->n; v++)
			if (g->weight[u][v] != INF)
				if (!selected[v] && g->weight[u][v] < distance[v])
					distance[v] = g->weight[u][v];
	}
}

int main(void)
{
    GraphType g;

    g.n = 7;    // 정점의 개수 설정

    // 그래프 초기화
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            g.weight[i][j] = INF;    // 초기값으로 무한대(INF) 설정
        }
    }

    // 그래프 연결 관계 설정
    g.weight[0][1] = 29;
    g.weight[0][5] = 10;
    g.weight[1][2] = 16;
    g.weight[1][6] = 15;
    g.weight[2][3] = 12;
    g.weight[3][4] = 22;
    g.weight[3][6] = 18;
    g.weight[4][5] = 27;
    g.weight[4][6] = 25;
    g.weight[5][6] = 24;

    // 선택된 정점 배열과 거리 배열 초기화
    for (int i = 0; i < g.n; i++) {
        selected[i] = FALSE;
        distance[i] = 0;
    }

    prim(&g, 0);    // 프림 알고리즘 실행

    return 0;
}