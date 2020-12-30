#include <stdio.h>
#define MaxSize 100

typedef struct {
	int Data[MaxSize];
	int Front, Rear;
}Queue;

void makenullQueue(Queue *pQ){
	pQ->Front = pQ->Rear = 0;
}

int emptyQueue(Queue Q){
	return Q.Front == Q.Rear;
}

int fullQueue(Queue Q){
	return (Q.Rear - Q.Front + 1) == MaxSize;
}

void enQueue(int x, Queue *pQ){
	if(!fullQueue(*pQ)){
		pQ->Data[pQ->Rear] = x;
		pQ->Rear = (pQ->Rear + 1);
	}
}

void deQueue(Queue *pQ, int *pTop){
	if(!emptyQueue(*pQ)){
		(*pTop) = pQ->Data[pQ->Front];
		pQ->Front = (pQ->Front + 1);
	}
}

int countElement(Queue Q){
	int i, count = 0;
	for(i = Q.Front; i < Q.Rear; i++)
	{
		count++;
	}
	return count;
}

int main(){
	int n;
	scanf("%d", &n);
	getchar();
	Queue Q;
	makenullQueue(&Q);
	
	for(int i = 0; i < n; i++){
		char c;
		scanf("%c", &c);
		getchar();
		if(c == 'E'){
			int x;
			scanf("%d", &x);
			getchar();
			enQueue(x, &Q);
			printf("%d\n", countElement(Q));
		}else if(c == 'D'){
			int top;
			if(!emptyQueue(Q))
			{
				deQueue(&Q, &top);
				printf("%d %d\n", top, countElement(Q));
			}else printf("-1 %d\n", countElement(Q));
		}
	}
	return 0;
}