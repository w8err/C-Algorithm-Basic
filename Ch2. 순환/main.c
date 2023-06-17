#include <stdio.h>

int factorial_재귀함수(int n) {
	printf("factorial (%d) \n", n);
	if (n <= 1) return(1);
	else return (n * factorial_재귀함수(n - 1));
}		// 재귀함수. 

int factorial_반복함수(int n) {
	int i, result = 1;
	for (i = 1; i < n; i++)
		result = result * i;
	return(result);
}

double 거듭제곱(double x, int n)
{
	if (n == 0) return 1;
	else if ((n % 2) == 0)
		return 거듭제곱(x * x, n / 2);
	else return x * 거듭제곱(x * x, (n - 1) / 2);
}

int num = 1;	// 스태틱?

void 하노이_탑(int n, char from, char tmp, char to)
{
	if (n == 1) {
		printf("%d번째. 원판 1을 %c에서 %c로 옮긴다.\n", num, from, to);
		num++;
	}
	else {
		하노이_탑(n - 1, from, to, tmp);
		printf("%d번째. 원판 %d을 %c에서 %c로 옮긴다\n",num, n, from, to);
		num++;
		하노이_탑(n - 1, tmp, from, to);
	}
}

int main() {
	int n;
	printf("숫자 입력 >> ");
	scanf_s("%d", &n);

	// factorial_재귀함수(n);
	factorial_반복함수(n);

	int x = 3, xx = 5;
	
	거듭제곱(x, xx);

	하노이_탑(4, 'A', 'B', 'C');

	return 0;
}

