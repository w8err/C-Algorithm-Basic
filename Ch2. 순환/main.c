#include <stdio.h>

int factorial_����Լ�(int n) {
	printf("factorial (%d) \n", n);
	if (n <= 1) return(1);
	else return (n * factorial_����Լ�(n - 1));
}		// ����Լ�. 

int factorial_�ݺ��Լ�(int n) {
	int i, result = 1;
	for (i = 1; i < n; i++)
		result = result * i;
	return(result);
}

double �ŵ�����(double x, int n)
{
	if (n == 0) return 1;
	else if ((n % 2) == 0)
		return �ŵ�����(x * x, n / 2);
	else return x * �ŵ�����(x * x, (n - 1) / 2);
}

int num = 1;	// ����ƽ?

void �ϳ���_ž(int n, char from, char tmp, char to)
{
	if (n == 1) {
		printf("%d��°. ���� 1�� %c���� %c�� �ű��.\n", num, from, to);
		num++;
	}
	else {
		�ϳ���_ž(n - 1, from, to, tmp);
		printf("%d��°. ���� %d�� %c���� %c�� �ű��\n",num, n, from, to);
		num++;
		�ϳ���_ž(n - 1, tmp, from, to);
	}
}

int main() {
	int n;
	printf("���� �Է� >> ");
	scanf_s("%d", &n);

	// factorial_����Լ�(n);
	factorial_�ݺ��Լ�(n);

	int x = 3, xx = 5;
	
	�ŵ�����(x, xx);

	�ϳ���_ž(4, 'A', 'B', 'C');

	return 0;
}

