#pragma once
#include <stdio.h>
#include "heap_node.h"

void printGap(int a)
{
	int i;
	for (i = 0; i < a; i++) printf(" ");
}

int getLevel(int n)
{
	int i;
	for (i = 0; n; i++) n /= 2;
	return i;
}

int setArray(element* heap, int* n, char* buff, int pos)
{
	static int maxPos;
	if (pos == 1) maxPos = 0;
	if (pos <= (*n) + 1)
	{
		if (maxPos < pos) maxPos = pos;
		buff[pos - 1] = heap[pos].key;
		setArray(heap, n, buff, pos * 2);
		setArray(heap, n, buff, pos * 2 + 1);
	}
	return maxPos;
}

int pow(int x, int y)
{
	int i, sum = 1;
	for (i = 0; i < y; i++)	sum *= x;
	return sum;
}

void print(element* heap, int* n)
{
	char buff[1024] = { 0 };
	int i, j, end, gap, cnt = 0, maxPos = 0, level;
	maxPos = setArray(heap, n, buff, 1); //Ʈ���� �迭�� ���
	level = getLevel(maxPos);// �ִ� ���� �˾Ƴ���
	for (i = 0; i < level; i++)
	{
		gap = pow(2, level - i) - 1; // �ش� ���� ��(����)���� ���ϱ�
		printGap(gap / 2); //ù���� �⺻���� 1/2
		end = pow(2, i); //������ ������ ������ ���� ���ϱ�
		for (j = 0; j < end; j++)
		{
			printf("%d", buff[cnt++]);
			printGap(gap);
		}
		printf("\n");
	}
	printf("\n");
}