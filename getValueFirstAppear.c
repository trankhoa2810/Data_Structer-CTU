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

int locate(int x, List L){
	Position i, p;
	for(i = 0; i < L.Last; i++)
	{
		if(L.Elements[i] == x)
		{
			p = i;
			return p + 1;
		}
	}
	return L.Last + 1;
}

void deleteList(Position p, List *pL)
{
	Position i;
	if(p <= pL->Last)
	{
		for(i = p - 1; i <= pL->Last; i++)
		{
			pL->Elements[i] = pL->Elements[i + 1];
		}
		pL->Last--;
	}
	else printf("Vi tri khong hop le\n");
}


void erase(int x, List *pL)
{
	deleteList(locate(x, *pL), pL);
}

int main()
{
	int n;
	scanf("%d", &n);
	List L;
	makeNullList(&L);
	nhap(n, &L);
	int x;
	scanf("%d", &x);
	hienThi(L);
	erase(x, &L);
	hienThi(L);
	return 0;
}