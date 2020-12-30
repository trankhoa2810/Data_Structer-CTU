#include <stdio.h>
#define MaxSize 100

typedef struct {
	int Data[MaxSize];
	int Front, Rear;
}Queue;

//Khởi tạo một hàng đợi rỗng 
void makenullQueue(Queue *pQ){
	pQ->Front = 0;
	pQ->Rear = 0;
}

//Kiểm tra hàng đợi rỗng hay không ? 
int emptyQueue(Queue Q){
	return Q.Front == Q.Rear;
} 

//Kiểm tra hàng đợi có đầy không ?
int fullQueue(Queue Q){
	return (Q.Rear + 1) % MaxSize == Q.Front;
}

//Thêm 1 phần tử vào hàng đợi 
void enQueue(int x, Queue *pQ){
	if(!fullQueue(*pQ)){
		pQ->Data[pQ->Rear] = x;
		pQ->Rear = (pQ->Rear + 1) % MaxSize;
	}
}

//Trả về nội dung phần tử đầu hàng đợi và xóa phần tử đầu hàng
void deQueue(Queue *pQ, int *pTop){
	if(!emptyQueue(*pQ)){
		(*pTop) = pQ->Data[pQ->Front];
		pQ->Front = (pQ->Front + 1) % MaxSize;
	}
}

//Hiển thị một hàng đợi 
void printQueue(Queue *pQ){
	while(!emptyQueue(*pQ)){
		int Top;
		deQueue(pQ, &Top);
		printf("%d\n", Top);
	}
	printf("\n");
}

int main(){
	Queue P, Q;
	makenullQueue(&P);
	makenullQueue(&Q);
	int n, time = 0;
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		enQueue(x, &P);
	}

	for (int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		enQueue(x, &Q);
	}

	while(!emptyQueue(P)){
		int topP, topQ;
		if(P.Data[P.Front] == Q.Data[Q.Front]){
			deQueue(&P, &topP);
			deQueue(&Q, &topQ);
		}
		else{
			deQueue(&P, &topP);
			enQueue(topP, &P);
		}
		time++;
	}
	printf("%d", time);
	return 0;
}