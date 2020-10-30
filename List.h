#include <stdio.h>
#define MaxLength 300

typedef int ElementType;
typedef int Position;

typedef struct {
	ElementType Elements[MaxLength];
	Position Last;
} List;

//Khởi tạo danh sách rỗng(phần tử cuối cùng của danh sách bằng 0)
void makeNullList(List *pL)
{
	pL->Last = 0;
}

//Kiểm tra danh sách rỗng
int emptyList(List L)
{
	return L.Last==0;
}

//Kiểm tra danh sách đầy
int fullList(List L)
{
	return L.Last==MaxLength;
}

//Trả về vị trí đâu tiên trong danh sách
Position first(List L)
{
	return 1;
}


//Trả về vị trí cuối cùng trong danh sách
Position endList(List L)
{
	return L.Last+1;
}

//Hàm in danh sách
void printList(List L)
{
	Position i;
	for(i = 0; i < L.Last; i++)
	{
		printf("%d ", L.Elements[i]);
	}
	printf("\n");
}

//Hàm nhập danh sách
void readList(List *pL)
{
    makenullList(pL);
    int n, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insertList(x, pL->Last + 1, pL);
    }
}

//Kiểm tra phần tử x có nằm trong danh sách L hay không?
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

//Hàm trả về vị trí xuất hiện đầu tiên của phần tử x trong danh sách
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

//Hàm sắp xếp danh sách
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

//Chèn n phần tử x nhập từ bàn phím vào danh sách
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

//Thêm tất cả các phần tử thuộc cả hai danh sách L1 và L2 vào danh sách pL
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

//Kiểm tra nếu phần tử nào thuộc cả hai danh sách L1 và L2 thì thêm vào danh sách pL
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

//Xoá phần tử x xuất hiện đầu tiên trong danh sách L
void erase(int x, List *pL)
{
	deleteList(locate(x, *pL), pL);
}

//Lấy giá trị trung bình của các phần tử trong danh sách
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

//Chèn phần tử x vào vị bất kì trong danh sách
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

//Hàm sao chép số chẵn trong danh sách
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

//Chèn phần tử x vào cuối danh sách
void insertSet(int x, List *pL)
{
	pL->Elements[pL->Last] = x;
	pL->Last++;
}

//Kiểm tra phần tử trong danh sách L1 có nằm trong danh sách L2 hay không? Nếu không thì thêm vào danh sách pL 
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

//Xoá phần tử tại vị trí p trong danh sách
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

//Xoa tất cả phần tử x trong danh sách
void removeAll(int x, List *pL)
{
	while(locate(x, *pL) <= pL->Last)
	{
		deleteList(locate(x, *pL), pL);
	}
}

//Xoá các phần tử trùng nhau chỉ giữ lại 1 phần tử duy nhất trong danh sách
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
