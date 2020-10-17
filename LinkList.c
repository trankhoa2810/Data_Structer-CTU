#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct Node {
	int Element;
	struct Node* Next;
};

typedef struct Node* List;

void makenullList(List* pL) {	
	(*pL) = (List) malloc(sizeof(struct Node));	
	(*pL)->Next = NULL;
}

List first(List L) {
	return L;
}

List last(List L) {
	List P = first(L);
	while(P->Next->Element != NULL) P=P->Next;
	return P->Next;
}

List locate1(int x, List L) {
	List P = first(L);	
	while(P->Next != NULL) {
		if(P->Next->Element == x) {
			return P;
		}
		P = P->Next;
	}
	return NULL;
}

int member1(int x, List L) {
	List P;
	P = first(L);
	while(P->Next != NULL) {
		if(P->Next->Element == x) {
			return 1;
		}
		P = P->Next;
	}
	return 0;
}

void append1(int x, List* pL) {
	List P  = (List) malloc(sizeof(struct Node));
	P->Element = x;
	P->Next = (*pL)->Next;
	(*pL)->Next = P;
}

List intersection(List L1, List L2) {
	const int nax = 100;
	int vis[nax];
	memset(vis, 0, sizeof vis);
	List P = first(L1);
	while(P->Next != NULL) {	
		vis[P->Next->Element] = 1;
		P = P->Next;	
	}
	P = first(L2);
	List L;
	makenullList(&L);
	while(P->Next != NULL) {		
		if(vis[P->Next->Element] == 1) {
			append1(P->Next->Element, &L);
		}
		P = P->Next;
	}
	return L;
}	

int sizeList(List L) {
	int ret = 0;
	List P = first(L);
	while(P->Next != NULL) {
		ret++;
		P = P->Next;
	}
	return ret;
}

void deleteList1(List p) {
	List q;
	if(p->Next != NULL) {
		q = p->Next;
		p->Next = q->Next;	
		free(q);
	}
}

void erase(int x, List *pL) {
	List P = locate1(x, *pL);
	if(P != NULL) {
		deleteList1(P);		
	}
}

List reverseList(List L1) {
	List L;
	makenullList(&L);
	List P = first(L1);
	while(P->Next != NULL) {
		append1(P->Next->Element, &L);
		P = P->Next;
	}
	return L;
}

List difference(List L1, List L2) {
	List L;
	makenullList(&L);
	List P = first(L1);
	while(P->Next != NULL) {			
		if(member1(P->Next->Element, L2) == 0) {
			append1(P->Next->Element, &L);
		}
		P = P->Next;
	}	
	
	return reverseList(L);
}

void printList(List L) {
	List P = first(L);
	while(P->Next!=NULL) {
		printf("%d ", P->Next->Element);	
		P = P->Next;
	}
	printf("\n");
}

int main() {
	List L;
	typedef List Position;
	Position p,q;	
	L=(struct Node*)malloc(sizeof(struct Node));	
	L->Next=NULL;
	
	p=L;
	q=(struct Node*)malloc(sizeof(struct Node));	
	q->Element=5;
	q->Next=NULL;
	p->Next = q;
		
	p=L;
	
	q=(struct Node*)malloc(sizeof(struct Node));	
	q->Element=500;
	q->Next=p->Next;
	p->Next = q;
			
	erase(5,&L);
	p=L;
	while(p->Next!=NULL)
	{
		printf("%d ",p->Next->Element);
		p=p->Next;
	}
	return 0;
}
