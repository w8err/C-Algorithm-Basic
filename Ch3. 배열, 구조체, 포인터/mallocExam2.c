#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct studentTag {
	char name[10];
	int age;
	double gpa;
} student;

int main(void)
{
	student* s;

	s = (student*)malloc(sizeof(student));
	int size = sizeof(student);
	printf("student ����ü�� ������� %d", size);
	/* �� �޸𸮰� 24����Ʈ�� ���� ? ����ü�� ������� �޸𸮿� ����� �� �����Ϸ��� �ణ�� ���� ������ �� Ȯ���ϰ� �Ǵµ�
	   �̸� "�е�(padding)"�̶�� �θ��ϴ�.�е��� ����ü ������� ũ�Ⱑ 2�� ����� �ƴ� �� �߻��ϸ�, ����ü ������� �� �̻� ���� �� ���� �� Ȯ���˴ϴ�. */

	if (s == null) {
		fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ��� �� �����ϴ�.");
		exit(1);
	}

	strcpy(s->name, "Park");
	s->age = 20;

	free(s);
	return 0;
}

/* 

int main() {
double *p1;
p1 = (int *)malloc(double);
p1 = 23.92;
}

������ �����ϰ� �� �����ΰ�? 

1. malloc �Լ��� ���޵� ���ڰ� �߸���. malloc(sizeof(double))�� �Ǿ� ��
2. p1�� double�� �����ʹ�. �̸� int �����ͷ� 'ĳ����'�Ͽ� �Ҵ�� �޸� ��Ͽ� �����Ϸ��� �ϴ� ��. 
3. p1�� ����Ű�� �޸� ��Ͽ� 23.92�� �Ҵ��Ϸ� �ϴ� ��. �̰� �߸���. 23.92�� ���ͷ� ����μ�, �޸𸮿� ���� �Ҵ�� �� �����ϴ�.

�� : 
int main() {
  double *p1;
  p1 = (double *)malloc(sizeof(double));
  *p1 = 23.92;
  free(p1);  // �Ҵ�� �޸� ����� �������־�� �մϴ�.
  return 0;
}

*/