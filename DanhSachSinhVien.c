#include <stdio.h>
#include <string.h>

typedef struct {
   char MSSV[10];
   char HoTen[50];
   float DiemLT, DiemTH1, DiemTH2;
} SinhVien;

typedef struct{
	SinhVien A[40];
	int n;
}DanhSach;

DanhSach dsRong()
{
	DanhSach L;
	L.n = 0;
	return L;
}

void nhap(int n, DanhSach *pL)
{
	pL->n = n;
	for(int i = 0; i < pL->n; i++)
	{
		getchar();
		fgets(pL->A[i].MSSV, 10, stdin);
		if(pL->A[i].MSSV[strlen(pL->A[i].MSSV) - 1] == '\n') {
			pL->A[i].MSSV[strlen(pL->A[i].MSSV) - 1] = 0;
		}
		fgets(pL->A[i].HoTen, 50, stdin);
		if(pL->A[i].HoTen[strlen(pL->A[i].HoTen) - 1] == '\n') {
			pL->A[i].HoTen[strlen(pL->A[i].HoTen) - 1] = 0;
		}
		scanf("%f%f%f", &pL->A[i].DiemLT, &pL->A[i].DiemTH1, &pL->A[i].DiemTH2);
	}
}

void hienThi(DanhSach L)
{
	for(int i = 0; i < L.n; i++)
	{
		printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);		
	}
}

void hienthiDat(DanhSach L)
{
	int i;
	printf("Sinh vien DAT\n");
	for(i = 0; i < L.n; i++)
	{
		if(L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2 >= 4.0)
		{
			printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);		
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	DanhSach L;
	L = dsRong();
	nhap(n, &L);
	hienThi(L);
	hienthiDat(L);
	return 0;
}