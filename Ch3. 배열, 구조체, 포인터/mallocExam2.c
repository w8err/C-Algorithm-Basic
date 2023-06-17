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
	printf("student 구조체의 사이즈는 %d", size);
	/* 이 메모리가 24바이트인 이유 ? 구조체의 멤버들이 메모리에 저장될 때 컴파일러가 약간의 여유 공간을 더 확보하게 되는데
	   이를 "패딩(padding)"이라고 부릅니다.패딩은 구조체 멤버들의 크기가 2의 배수가 아닐 때 발생하며, 구조체 멤버들을 더 이상 붙일 수 없을 때 확보됩니다. */

	if (s == null) {
		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.");
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

오류를 지적하고 왜 오류인가? 

1. malloc 함수에 전달된 인자가 잘못됨. malloc(sizeof(double))가 되야 함
2. p1은 double형 포인터다. 이를 int 포인터로 '캐스팅'하여 할당된 메모리 블록에 접근하려고 하는 중. 
3. p1이 가리키는 메모리 블록에 23.92를 할당하려 하는 중. 이건 잘못됨. 23.92는 리터럴 상수로서, 메모리에 직접 할당될 수 없습니다.

답 : 
int main() {
  double *p1;
  p1 = (double *)malloc(sizeof(double));
  *p1 = 23.92;
  free(p1);  // 할당된 메모리 블록을 해제해주어야 합니다.
  return 0;
}

*/