#include "AListLib.c"
#include <stdio.h>

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

float getAvg(List L)
{
	float avg = 0;
	Position i;
	for(i = 0; i < L.Last; i++)
	{
		avg += L.Elements[i];
	}
	if(L.Last != 0)
		return avg / i;
	else return -10000;
}

int main()
{
	int n;
	scanf("%d", &n);
	List L, A;
	makeNullList(&L);
	makeNullList(&A);
	nhap(n, &L);
	hienThi(L);
	copyEvenOdd(L, &A);
	hienThi(A);
	printf("%.3f", getAvg(A));
	return 0;
}