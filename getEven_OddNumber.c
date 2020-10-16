#include <stdio.h>
#include "AListLib.c"

void makeNullList(List *pL)
{
	pL->Last = 0;
}

void nhap(int n, List *pL)
{
	pL->Last = n;
	Position i;
	for(i = 0; i < pL->Last; i++)
	{
		scanf("%d", &pL->Elements[i]);
	}
}

void hienThi(List L)
{
	Position i;
	for(i = 0; i < L.Last; i++)
	{
		printf("%d ", L.Elements[i]);
	}
	printf("\n");
}

void listOddNumber(List L)
{
	Position i;
	for(i = 0; i < L.Last; i++)
	{
		if(L.Elements[i] & 1)
			printf("%d ", L.Elements[i]);
	}
	printf("\n");
}

void insertSet(int x, List *pL)
{
	pL->Elements[pL->Last] = x;
	pL->Last++;
}

void copyEvenOdd(List L, List *pL)
{
	Position i;
	for(i = 0; i < L.Last; i++)
	{
		if(!(L.Elements[i] & 1))
			insertSet(L.Elements[i], pL);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	List A, B;
	makeNullList(&A);
	nhap(n, &A);
	hienThi(A);
	listOddNumber(A);
	makeNullList(&B);
	copyEvenOdd(A, &B);
	hienThi(B);
	return 0;
}