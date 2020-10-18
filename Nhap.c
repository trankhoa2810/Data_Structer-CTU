#include <stdio.h>
#include <string.h>

struct SinhVien{
   char MSSV[10];
   char HoTen[50];
   float DiemLT, DiemTH1, DiemTH2;
};

typedef struct{
	SinhVien A[40];
	int n;
}DanhSach;

int ktRong(DanhSach L)
{
	if(L.n==0)
		return 1;
	else return 0;
}

void xoaTai(int p, DanhSach *pL)
{
	int i;
	for(i = p - 1; i < pL->n; i++)
	{
		pL->A[i] = pL->A[i + 1];
	}
	(pL->n)--;
}

int tim1(char MSSV[], DanhSach S) {
	int n = S.n;
	for(int i = 0; i < n; i++) {
		if(strcmp(MSSV, S.A[i].MSSV) == 0) {
			return 1;
		}
	}
	return -1;
}

DanhSach nhap() {
	DanhSach S = dsRong();
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		getchar();
		char MSSV[10], HoTen[50];
		fgets(MSSV, 10, stdin);
		if(MSSV[strlen(MSSV) - 1] == '\n') {
			MSSV[strlen(MSSV) - 1] = 0;
		}
		fgets(HoTen, 50, stdin);
		if(HoTen[strlen(HoTen) - 1] == '\n') {
			HoTen[strlen(HoTen) - 1] = 0;
		}
		float DiemLT, DiemTH1, DiemTH2;
		scanf("%f%f%f", &DiemLT, &DiemTH1, &DiemTH2);
		if(tim1(MSSV, S) == -1) {
			struct SinhVien sv;
			strcpy(sv.MSSV, MSSV);
			strcpy(sv.HoTen, HoTen);
			sv.DiemLT = DiemLT;
			sv.DiemTH1 = DiemTH1;
			sv.DiemTH2 = DiemTH2;
			chenCuoi(sv, &S);
		}
	}
	return S;
}

void hienthiDat(DanhSach L)
{
	int i;
	for(i = 0; i < L.n; i++)
	{
		if(L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2 >= 4.0)
		{
			printf("%s - %s - %.2f - %.2f - %.2f -%.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2, (L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2));		
		}
	}
}

int tim(char MSSV[], DanhSach L)
{
	int n = L.n;
	for(int i = 0; i < n; i++)
	{
		if(strcmp(MSSV,L.A[i].MSSV) == 0)
			return i + 1;
	}
	return n + 1;
}



int main()
{
	DanhSach L = {{{"B1806972","Hoang Minh", 5.5f, 4.5f, 5.0f}}, 1};
	printf("Size L = %lu x %lu\n",
	    sizeof(L.A)/sizeof(SinhVien), sizeof(SinhVien));
	printf("n = %d",L.n);
	return 0;
}