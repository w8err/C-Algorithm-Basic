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
    int n; //������ ����
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

// �׷��� �ʱ�ȭ
void graph_init(GraphType* g)
{
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}

// ���� ���� ����
void insert_vertex(GraphType* g, int v)
{
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "�׷���: ������ ���� �ʰ�");
        return;
    }
    g->n++;
}

// ���� ���� ����, v�� u�� ���� ����Ʈ�� ����
void insert_edge(GraphType* g, int u, int v, int weight)
{
    GraphNode* node;
    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "�׷���: ���� ��ȣ ����");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->weight = weight;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

// ���� �ڵ�
#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s)
{
    s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
    return (s->top == -1);
}

// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

// �����Լ�
void push(StackType* s, element item)
{
    if (is_full(s))
    {
        fprintf(stderr, "���� ��ȭ ����\n");
        return;
    }
    else s->stack[++(s->top)] = item;
}

// �����Լ�
element pop(StackType* s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return s->stack[(s->top)--];
}

// Earliest Time ��� �Լ�
void earliest_time(GraphType* g, int* et)
{
    int i;
    StackType s;
    GraphNode* node;

    init_stack(&s);

    // ��� ������ ���� ������ ���
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

    // ���� ������ 0�� ������ ���ÿ� ����
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

// Latest Time ��� �Լ�
void latest_time(GraphType* g, int* et, int* lt)
{
    int i;
    StackType s;
    GraphNode* node;

    init_stack(&s);

    // ��� ������ ���� ������ ���
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

    // ���� ������ 0�� ������ ���ÿ� ����
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

// �����Լ�
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

    // ���� 0�� ���� ����Ʈ ����
    insert_edge(&g, 0, 2, 2);
    insert_edge(&g, 0, 3, 3);

    // ���� 1�� ���� ����Ʈ ����. �� �ڷ� 2, 3, ...
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