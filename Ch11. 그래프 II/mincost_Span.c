#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS	65 //maximum heap size+1
#define HEAP_FULL(hn)	(hn == MAX_ELEMENTS-1)
#define HEAP_EMPTY(hn)	(!hn)

#define N_NODES	7		// No. of nodes in the Graph.
int	parent[N_NODES];	// Sets of nodes.

typedef struct edge {
	int i, j;
	int cost;
} Edge;

Edge heap[MAX_ELEMENTS]; 
int	heapN = 0;			// Num of Elements in heap

void push_min_heap(Edge item, int* n)
{		// 노드 수가 *n인 max heap에 item 값을 추가
	int i;
	if (HEAP_FULL(*n)) {
		fprintf(stderr, "The heap is full.\n");
		exit(1);
	}
	i = ++(*n);
	while ((i != 1) && (item.cost < heap[i / 2].cost)) {
		heap[i] = heap[i / 2];	  // parent의 값을 아래로 이동
		i /= 2;		// 한 레벨 위로 이동
	}
	heap[i] = item;
}

Edge pop_min_heap(int* n)
{
	int parent, child;
	Edge item, temp;

	if (HEAP_EMPTY(*n))
	{
		fprintf(stderr, "The heap is empty\n");
		exit(1);
	}
	item = heap[1];
	temp = heap[(*n)--];		// 제일 마지막 원소를 비교 대상으로…
	parent = 1; child = 2;	// root node부터 시작
	while (child <= *n) {
		if ((child < *n) && (heap[child].cost > heap[child + 1].cost))
			child++;	// 두 개의 children 중에 큰 쪽과 비교
		if (temp.cost <= heap[child].cost)
			break;	// 더 이상 내려갈 필요없음
		heap[parent] = heap[child];	// child의 데이터를 위로 이동
		parent = child;		// 아래로 내려가자
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}

void union2(int i, int j)
{
	/* i와 j를 root로 하는 트리에 대해 가중 규칙을 적용한 union. 	   parent[i] = -count[i] and parent[j] = -count[j] */

	int temp = parent[i] + parent[j];
	if (parent[i] > parent[j]) {  // i의 개수 < j의 개수
		parent[i] = j; 	// j가 새로운 root로
		parent[j] = temp;
	}
	else {
		parent[j] = i; 	// i가 새로운 root로
		parent[i] = temp;
	}
}

int find2(int i)   //collapsingFind()
{	 /* i를 포함하고 있는 트리의 루트를 return. i부터 root사이의
		노드에 대해 collapsing rule을 적용 */
	int root, node, next;
	for (root = i; parent[root] >= 0; root = parent[root])
		;	   // 트리의 root 노드를 발견
	for (node = i;
		node != root && parent[node] != root; node = next) {
		next = parent[node];
		parent[node] = root;	// parent를 root로 변경
	}
	return root;
}

int main()
{
	int 	p1, p2, Nselected = 0;
	Edge 	e;
	int	edges[][3] = { 0, 5, 10,
					0, 1, 28,
					1, 2, 16,
					1, 6, 14,
					2, 3, 12,
					3, 4, 22,
					3, 6, 17,
					4, 5, 25,
					4, 6, 23 }; // ,
					// 5, 6, 24};
	int Nedges = sizeof(edges) / sizeof(int) / 3;

	for (int i = 0; i < Nedges; i++)
	{
		e.i = edges[i][0];
		e.j = edges[i][1];
		e.cost = edges[i][2];
		push_min_heap(e, &heapN);
	}

	for (int i = 0; i < N_NODES; i++)
		parent[i] = -1;

	while (heapN > 0)
	{
		e = pop_min_heap(&heapN);
		if ((p1 = find2(e.i)) != (p2 = find2(e.j)))
		{
			union2(p1, p2);
			Nselected++;
			printf("Edge (%d, %d)is selected!\n", e.i, e.j);
			if (Nselected == N_NODES - 1)
				break;
		}
		else
			printf("\x1b[31mEdge (%d, %d)is discarded!\n\x1b[0m", e.i, e.j);
	}
	if (Nselected == N_NODES - 1)
		printf("%d-nodes, %d-edges Min-cost Spanning Tree found!\n", N_NODES, N_NODES - 1);
	else
		printf("No Min-cost Spanning Tree!\n");
}
