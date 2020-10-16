#include <stdio.h>
#define MaxLength 300

typedef int ElementType;
typedef int Position;

typedef struct{
	ElementType Elements[MaxLength];
	Position Last; 
} List;

void makeNullList(List *pL)
{
	pL->Last = 0;
}

int emptyList(List L)
{
	return L.Last==0;
}

int fullList(List L)
{
	return L.Last==MaxLength;
}

Position first(List L)
{
	return 1;
}

Position endList(List L)
{
	return L.Last+1;
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

void readList(int n, List *pL)
{
	Position i;
	pL->Last = n;
	for(i = 0; i < pL->Last; i++)
	{
		scanf("%d", &pL->Elements[i]);
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

void sort(List *pL)
{
	Position i, j;
	for(i = 0; i < pL->Last - 1; i++)
	{
		for(j = i + 1; j < pL->Last; j++)
		{
			if(pL->Elements[i] > pL->Elements[j])
			{
				int temp = pL->Elements[i];
				pL->Elements[i] = pL->Elements[j];
				pL->Elements[j] = temp;
			}
		}
	}
}

void readSet(List *pL)
{
	makenullList(pL);
	int n, x;
	Position i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
	    scanf("%d", &x);
	    if(!member(x,*pL))
		    insertSet(x, pL);
	}
}

void unionSet(List L1, List L2, List *pL)
{
	makenullList(pL);
	Position i;
	
	for(i = 0; i < L1.Last; i++)
	{
		insertSet(L1.Elements[i], pL);
	}
	
	for(i = 0; i < L2.Last; i++)
	{
		if(!member(L2.Elements[i], *pL))
		    insertSet(L2.Elements[i], pL);
	}
}

void intersection(List L1, List L2, List *pL)
{
	makenullList(pL);
	Position i;
	for(i = 0; i < L1.Last; i++)
	{
		if(member(L1.Elements[i], L2))
			insertSet(L1.Elements[i], pL);
	}
}

void erase(int x, List *pL)
{
	deleteList(locate(x, *pL), pL);
}

float getAvg(List L)
{
	int avg = 0;
	Position i;
	for(i = 0; i < L.Last; i++)
	{
		avg += L.Elements[i];
	}
	if(L.Last != 0)
		return avg / i;
	else return -10000;
}

void insertList(int x, Position p, List *pL)
{
	Position i;
	pL->Last++;
	if(p >= 1 && p <= pL->Last)
	{
		for(i = pL->Last - 1; i > p; i--)
		{
			pL->Elements[i + 1] = pL->Elements[i];
		}
		pL->Elements[p - 1] = x;
	}
	else printf("Vi tri khong hop le");
}

void copyEvenNumbers(List L, List *pL2)
{
	makenullList(pL2);
	Position i;
	for(i = 0; i < L.Last; i++)
	{
		if(!(L.Elements[i] & 1))
		{
			 insertList(L.Elements[i], pL2->Last + 1, pL2);
		}
	}
}

void insertSet(int x, List *pL)
{
	pL->Elements[pL->Last] = x;
	pL->Last++;
}

void difference(List L1, List L2, List *pL)
{
	makenullList(pL);
	Position i;
	
	for(i = 0; i < L1.Last; i++)
	{
		if(!member(L1.Elements[i], L2))
		{
		    insertSet(L1.Elements[i], pL);
		}
	}
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

void removeAll(int x, List *pL)
{
	while(locate(x, *pL) <= pL->Last)
	{
		deleteList(locate(x, *pL), pL);
	}
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
