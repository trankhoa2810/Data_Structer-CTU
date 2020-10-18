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

int tim(char MSSV[], DanhSach L)
{
	int n = L.n;
	for(int i = 0; i < n; i++)
	{
		if(strcmp(MSSV,L.A[i].MSSV) == 0)
			return i;
	}
	return n + 1;
}

int tim1(char MSSV[], DanhSach S) {
	int n = S.n;
	for(int i = 0; i < n; i++) {
		if(strcmp(MSSV, S.A[i].MSSV) == 0) {
			return 1;
		}
	}
	return 0;
}

void xoaSinhVien(char MSSV[], DanhSach *pL)
{
	for(int i = tim(MSSV, *pL) - 1; i < pL->n; i++)
	{
		pL->A[i] = pL->A[i+1];
	}
	pL->n--;
}

int main()
{
	int n;
	scanf("%d", &n);
	DanhSach L;
	L = dsRong();
	nhap(n, &L);
	char MSSV[10];
	//scanf("%s", MSSV);
	fgets(MSSV, 10, stdin);
	if(MSSV[strlen(MSSV) - 1] == '\n')
		MSSV[strlen(MSSV) - 1] = 0;
	hienThi(L);
	int i = tim(MSSV, L);
	if(tim1(MSSV, L))
	{
		printf("Tim thay sinh vien %s. Thong tin sinh vien:\n", MSSV);
		printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
	}else printf("Khong tim thay sinh vien %s", MSSV);
	xoaSinhVien(MSSV, &L);
	return 0;
}