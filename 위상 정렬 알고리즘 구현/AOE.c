#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 50

typedef struct GraphNode
{
    int vertex;
    int weight;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n; //정점의 개수
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

// 그래프 초기화
void graph_init(GraphType* g)
{
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}

// 정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

// 간선 삽입 연산, v를 u의 인접 리스트에 삽입
void insert_edge(GraphType* g, int u, int v, int weight)
{
    GraphNode* node;
    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->weight = weight;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

// 스택 코드
#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
    s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
    return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType* s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

// 삽입함수
void push(StackType* s, element item)
{
    if (is_full(s))
    {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else s->stack[++(s->top)] = item;
}

// 삭제함수
element pop(StackType* s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->stack[(s->top)--];
}

// Earliest Time 계산 함수
void earliest_time(GraphType* g, int* et)
{
    int i;
    StackType s;
    GraphNode* node;

    init_stack(&s);

    // 모든 정점의 진입 차수를 계산
    int* in_degree = (int*)malloc(g->n * sizeof(int));
    for (i = 0; i < g->n; i++)
        in_degree[i] = 0;

    for (i = 0; i < g->n; i++) {
        GraphNode* node = g->adj_list[i];
        while (node != NULL) {
            in_degree[node->vertex]++;
            node = node->link;
        }
    }

    // 진입 차수가 0인 정점을 스택에 삽입
    for (i = 0; i < g->n; i++) {
        if (in_degree[i] == 0)
            push(&s, i);
    }

    while (!is_empty(&s)) {
        int w;
        w = pop(&s);

        node = g->adj_list[w];
        while (node != NULL) {
            int u = node->vertex;
            int weight = node->weight;
            if (et[u] < et[w] + weight)
                et[u] = et[w] + weight;

            in_degree[u]--;
            if (in_degree[u] == 0)
                push(&s, u);

            node = node->link;
        }
    }

    free(in_degree);
}

// Latest Time 계산 함수
void latest_time(GraphType* g, int* et, int* lt)
{
    int i;
    StackType s;
    GraphNode* node;

    init_stack(&s);

    // 모든 정점의 진출 차수를 계산
    int* out_degree = (int*)malloc(g->n * sizeof(int));
    for (i = 0; i < g->n; i++)
        out_degree[i] = 0;

    for (i = 0; i < g->n; i++) {
        GraphNode* node = g->adj_list[i];
        while (node != NULL) {
            out_degree[i]++;
            node = node->link;
        }
    }

    // 진출 차수가 0인 정점을 스택에 삽입
    for (i = 0; i < g->n; i++) {
        if (out_degree[i] == 0)
            push(&s, i);
    }

    while (!is_empty(&s)) {
        int w;
        w = pop(&s);

        node = g->adj_list[w];
        while (node != NULL) {
            int u = node->vertex;
            int weight = node->weight;

            if (lt[u] == INT_MAX)
                lt[u] = lt[w] - weight;
            else if (lt[u] > lt[w] - weight)
                lt[u] = lt[w] - weight;

            out_degree[u]--;
            if (out_degree[u] == 0)
                push(&s, u);

            node = node->link;
        }
    }

    free(out_degree);
}

// 메인함수
int main(void)
{
    GraphType g;

    graph_init(&g);
    insert_vertex(&g, 0);
    insert_vertex(&g, 1);
    insert_vertex(&g, 2);
    insert_vertex(&g, 3);
    insert_vertex(&g, 4);
    insert_vertex(&g, 5);

    // 정점 0의 인접 리스트 생성
    insert_edge(&g, 0, 2, 2);
    insert_edge(&g, 0, 3, 3);

    // 정점 1의 인접 리스트 생성. 그 뒤로 2, 3, ...
    insert_edge(&g, 1, 3, 2);
    insert_edge(&g, 1, 4, 3);

    insert_edge(&g, 2, 3, 2);
    insert_edge(&g, 2, 5, 4);

    insert_edge(&g, 3, 5, 1);

    insert_edge(&g, 4, 5, 2);

    int* et = (int*)malloc(g.n * sizeof(int));
    int* lt = (int*)malloc(g.n * sizeof(int));

    for (int i = 0; i < g.n; i++) {
        et[i] = 0;
        lt[i] = INT_MAX;
    }

    earliest_time(&g, et);
    latest_time(&g, et, lt);

    printf("Vertex\tEarliest Time\tLatest Time\n");
    for (int i = 0; i < g.n; i++) {
        printf("%d\t%d\t\t%d\n", i, et[i], lt[i]);
    }

    free(et);
    free(lt);

    return 0;
}