//step 0) ������ ������ ������ ����ִ� T�� ���Խ�Ŵ. (���� T�� ��尡 �� ���� Ʈ��)

//step 1) T �� �ִ� ���� T �� ���� ����� ���� �� ����ġ�� �ּ��� ������ ã�´�.

//step 2) ã�� ������ �����ϴ� �� ��� ��, T�� ���� ��带 T�� ���Խ�Ų��.
//        (step1 ���� ã�� ������ ���� T�� ���Խ�Ŵ)
//
// step 3) ��� ��尡 T�� ���Ե� ������ 1, 2�� �ݺ��Ѵ�

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define	INF 1000L

typedef struct GraphType {
	int n;		// ������ ����
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

// �ּ� dist[v] ���� ���� ������ ��ȯ
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
		printf("���� %d �߰� \n", u);
		for (v = 0; v < g->n; v++)
			if (g->weight[u][v] != INF)
				if (!selected[v] && g->weight[u][v] < distance[v])
					distance[v] = g->weight[u][v];
	}
}

int main(void)
{
    GraphType g;

    g.n = 7;    // ������ ���� ����

    // �׷��� �ʱ�ȭ
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            g.weight[i][j] = INF;    // �ʱⰪ���� ���Ѵ�(INF) ����
        }
    }

    // �׷��� ���� ���� ����
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

    // ���õ� ���� �迭�� �Ÿ� �迭 �ʱ�ȭ
    for (int i = 0; i < g.n; i++) {
        selected[i] = FALSE;
        distance[i] = 0;
    }

    prim(&g, 0);    // ���� �˰��� ����

    return 0;
}