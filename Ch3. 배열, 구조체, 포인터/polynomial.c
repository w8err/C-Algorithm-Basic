/*

수학에서 나오는 다항식을 배열을 이용하여 표현해보자. 

1. 모든 차수의 계수값을 배열에 저장하는 것. 예를 들어 10x5 + 6x + 3이 있다고 치면, 10x5 + 0x4 + 0x3 + 0x2 + 6x + 3 으로 표현할 수 있다. 
   그래서 10 * 0 * 0 * 0 * 6 * 3 을 배열 coef에 저장하는 방법. 

   */



// 배열의 응용 : 다항식

#include <stdio.h>
#define MAX(a,b) (((a) > (b))? (a) : (b));
#define MAX_DEGREE 101
typedef struct {
	int degree;
	float coef[MAX_DEGREE]; 
}polynomial;

// C = A + B 여기서 A 와 B 는 다항식이다. 구조체가 반환된다. 
polynomial poly_add1(polynomial A, polynomial B)
{
	polynomial C;			// 결과 다항식
	int Apos = 0, Bpos = 0, Cpos = 0; // 배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree);	// 결과 다항식 차수

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {		// A항 > B항
				C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}

		else if(degree_a == degree_b)  {      // A항 == B항
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}	
		else {	 // A항 < B항
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;

		}
	}
	return C;
}

void print_poly(polynomial p)
{
	for (int i = p.degree; i > 0; i--)
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	printf("%3.1f \n", p.coef[p.degree]);
}

int main() 
{
	polynomial a = { 5, {3, 6, 0 ,0 , 0 , 10} };
	polynomial b = { 4, {7, 0, 5, 0, 1} };
	polynomial c;

	print_poly(a);
	print_poly(b);
	c = poly_add1(a, b);
	printf("------------------------------------------------------------------------------------------------------\n");
	print_poly(c);
	return 0;
}
