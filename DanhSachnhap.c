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
