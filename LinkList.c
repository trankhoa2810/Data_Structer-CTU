#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
struct Node{
	ElementType Element; //Chứa nội dung của phần tử
	struct Node *Next; //Con trỏ chỉ đến phần tử kế tiếp
};
typedef struct Node *Position; //Kiểu vị trí
typedef Position List;


// • Cấp phát vùng nhớ cho Header
// • Cho trường Next của Header trỏ đến NULL
void makenullList(List *pL)
{
	(*pL)=(struct Node*)malloc(sizeof(struct Node));
	(*pL)->Next = NULL;
}

//• Vị trí sau phần tử đầu tiên
Position first(List L)
{
	return L;
} 

//• Vị trí sau phần tử cuối cùng
Position endList(List L) {
	Position P;
	P=first(L); // P=L;
	while (P->Next!=NULL) P=P->Next;
	return P; 
} 

// • Xem trường Next của ô Header có trỏ đến
// NULL hay không?
int emptyList(List L)
{
	return (L->Next==NULL);
} 

void insertList(ElementType x, Position P, List *pL)
{
	Position T;
	T = (struct Node*)malloc(sizeof(struct Node));
	T->Element = x;
	T->Next = P->Next;
	P->Next = T;
}

int member(ElementType x, List L)
{
	Position P;
	P = L;
	while(P->Next != NULL)
	{
		if(P->Next->Element == x)
			return 1;
		P = P->Next;
	}
	return 0;
}

Position locate(ElementType x, List L)
{
	Position P;
	P = L;
	int flag = 0;
	while(P->Next != NULL && flag == 0)
	{
		if(P->Next->Element == x)
			flag = 1;
		else P = P->Next;
	}
	return P;
}

void deleteList(Position P, List *pL)
{
	if(P->Next != NULL)
	{
		Position Temp;
		Temp = (struct Node*)malloc(sizeof(struct Node));
		Temp = P->Next;
		P->Next = Temp->Next;
		free(Temp);
	}
}

void removeAll(ElementType x, List *pL)
{
	Position P;
	P = *pL;
	while(P->Next != NULL)
	{
		P = P->Next;
		deleteList(locate(x, *pL), pL);
	}
}

void normalize(List *pL)
{
	Position P, Q;
	P = *pL;
	while(P->Next != NULL)
	{
		Q = P->Next;
		while(Q->Next != NULL)
		{
			if(P->Next->Element == Q->Next->Element)
				deleteList(Q, pL);
			else Q = Q->Next;
		}
		P = P->Next;
	}
}

void erase(ElementType x, List *pL)
{
    Position P, Q;
    Q = locate(x, *pL);
    P = endList(*pL);
	if(Q == P)
	    printf("Not found %d\n", x);
	else deleteList(locate(x, *pL), pL);
}

void append(ElementType x, List *pL)
{
	Position P, Q;
	makenullList(&P);
	P->Element = x;
	Q = *pL;
	while(Q->Next != NULL)
	{
		Q = Q->Next;
	}
	Q->Next = P;
}

List unionSet(List L1, List L2)
{
	List L3;
	makenullList(&L3);
	L3 = L1;
	Position P = L2;
	while(P->Next != NULL)
	{
		if(!member(P->Next->Element, L1))
			append(P->Next->Element, &L3);
		P = P->Next;
	}
	return L3;
}

void addFirst(int x, List *pL)
{
	Position P;
	P = (struct Node*)malloc(sizeof(struct Node));
	P->Element = x;
	P->Next = (*pL)->Next;
	(*pL)->Next = P;
}

List readSet()
{
	List L;
	makenullList(&L);
	int n, x, i = 0;
	scanf("%d", &n);
	while(i < n)
	{
		scanf("%d", &x);
		if(!(member(x, L)))
			addFirst(x, &L);
		i++;
	}
	return L;
}

void copyEvenNumbers(List L1, List *pL2)
{
	Position P;
	P = L1;
	makenullList(pL2);
	while(P->Next != NULL)
	{
		P = P->Next;
		if(!(P->Element & 1))
			append(P->Element, pL2);
	}
}

void printOddNumbers(List L)
{
    Position P;
    P = L;
    while(P->Next != NULL)
    {
        P = P->Next;
        if((P->Element) & 1)
            printf("%d ", P->Element);
    }
}

float getAvg(List L)
{
    Position P;
    P = L;
	float AVG = 0;
	float count = 0;
	while(P->Next != NULL)
	{
		AVG += P->Next->Element;
		count++;
		P = P->Next;
	}
	if(count != 0)
		return AVG / count;
	return -10000;
}

void swap(int *P, int *Q)
{
	int temp = *P;
	*P = *Q;
	*Q = temp;
}

void sort(List *pL)
{
	Position P, Q;
	P = (*pL)->Next;
	while(P->Next != NULL)
	{
		Q = P->Next;
		while(Q->Next != NULL)
		{
			if(P->Element > Q->Next->Element)
				swap(&P->Element, &Q->Next->Element);
			Q = Q->Next;
		}
		P = P->Next;
	}
}

List intersection(List L1, List L2)
{
	List L;
	makenullList(&L);
	Position P;
	P = L1->Next;
	while(P->Next != NULL)
	{
		if(member(P->Element, L2))
			append(P->Element, &L);
		P = P->Next;
	}
	return L;
}

List difference(List L1, List L2)
{
	List L;
	makenullList(&L);
	Position P;
	P = L1;
	while(P->Next != NULL)
	{
		if(!member(P->Next->Element, L2))
			append(P->Next->Element, &L);
		P = P->Next;
	}
	return L;
}


int main()
{
	
	List L;
	Position p,q;
		
	L=(struct Node*)malloc(sizeof(struct Node));	
	L->Next=NULL;

	p=L;
	q=(struct Node*)malloc(sizeof(struct Node));	
	q->Element=5;
	q->Next=NULL;
	p->Next = q;
		
	q=(struct Node*)malloc(sizeof(struct Node));	
	q->Element=50;
	q->Next=p->Next;
	p->Next = q;
		
	deleteList(q,&L);
			
		
	p=L;
	while(p->Next!=NULL)
	{
		printf("%d ",p->Next->Element);
		p=p->Next;
	}
	printf("\n");
	return 0;
}
