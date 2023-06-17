int parent[MAX_VERTICES];		// �θ� ���

void set_init(int n)
{
	for (int i = 0; i < n; i++)
		parent[i] = -1;
}

// curr�� ���ϴ� ������ ��ȯ�Ѵ�
int set_find(int curr)
{
	if (parent[curr] == -1)
		return curr;
	while (parent[curr] != -1) curr = parent[curr];
	return curr;
}

// �ΰ��� ���Ұ� ���� ������ ��ģ��
void set_union(int a, int b)
{
	int root1 = set_find(a); // ��� a�� ��Ʈ�� ã�´�
	int rott2 = set_find(b); // ��� b�� ��Ʈ�� ã�´�
	if (root1 != root2)
		parent[root1] = root2;
}