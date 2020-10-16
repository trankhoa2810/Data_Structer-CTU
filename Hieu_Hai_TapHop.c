//#include "AListLib.c"
#include <stdio.h>

#define MaxLength 300

typedef int ElementType;
typedef int Position;

typedef struct{
	ElementType Elements[MaxLength];
	Position Last; 
} List;


void makenullList(List *pL)
{
	pL->Last = 0;
}

void readList(int n, List *pL)
{
	Position i;
	pL->Last = n;
	for(i = 0; i < pL->Last; i++)
	{
		scanf("%d", &pL->Elements[i]);
	}
}

void printList(List L)
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

void normalize(List *pL)
{
	Position p = 0, q;
	while(p != pL->Last)
	{
		q = p + 1;
		while(q != pL->Last)
		{
			if(pL->Elements[p] == pL->Elements[q])
			{
				deleteList(q + 1, pL);
			}
			else q++;
		}
		p++;
	}
}


int member(ElementType x, List L)
{
	Position i;
	int flag = 0;
	for(i = 0; i < L.Last; i++)
	{
		if(x == L.Elements[i])
		{
			flag = 1;
			break;
		}
	}
	return flag;
}

void HieuHaiTapHop(List L1, List L2, List *pL)
{
	makenullList(pL);
	Position i; 
	for(i = 0; i < L1.Last; i++)
	{
		if(!member(L1.Elements[i], L2))
			insertSet(L1.Elements[i], pL);
	}
}

int main()
{
	List L1, L2, L3;
	int n;
	scanf("%d", &n);
	readList(n, &L1);
	normalize(&L1);
	int m;
	scanf("%d", &m);
	readList(m, &L2);
	normalize(&L2);
	HieuHaiTapHop(L1, L2, &L3);
	printList(L1);
	printList(L2);
	printList(L3);
	return 0;
}