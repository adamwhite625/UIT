#include <bits/stdc++.h>

using namespace std;

double luongLonNhat = INT_MIN; // Khai bao bien toan cuc de thuan tien cho cau 4
int tuoiNhoNhat = 0; // Khai bao bien toan cuc de thuan tien cho cau 5

typedef struct NhanVienVanPhong
{
	string hoTen;
	int namSinh;
	int soNgay;
	double luongThucTe(){
		return (double)soNgay * (double)100000;
	}
}NVVP;

typedef struct NhanVienSanXuat
{
	string hoTen;
	int namSinh;
	float luongCB;
	int soSp;
	double luongThucTe(){
		return ((double)luongCB + (double)soSp * (double)5000);
	}
}NVSX;

typedef struct CongTy
{
	vector<NVVP> dsVP;
	vector<NVSX> dsSX; 
}CT;

/* 1. Nhap vao cac nhan vien (tu dong 36 -> 74)
Input:
	+ Nhap cac nhan vien
*/
void nhapNVVP(CongTy &ct, int n)
{
	cout << "Nhap nhan vien van phong\n\n";
	for(int i = 0; i < n; i++){
		NVVP vp;
		cout << "Ho ten: ";
		getline(cin, vp.hoTen);
		cout << "Nam sinh: ";
		cin >> vp.namSinh;
		cout << "So ngay lam viec: ";
		cin >> vp.soNgay;
		fflush(stdin);
		ct.dsVP.push_back(vp);
	}	
}

void nhapNVSX(CongTy &ct, int m)
{
	cout << "Nhap nhan vien san xuat\n\n";
	for(int i = 0; i < m; i++){
		NVSX sx;
		cout << "Ho ten: ";
		getline(cin, sx.hoTen);
		cout << "Nam sinh: ";
		cin >> sx.namSinh;
		cout << "Luong can ban: ";
		cin >> sx.luongCB;
		cout << "So san pham: ";
		cin >> sx.soSp;
		fflush(stdin);
		ct.dsSX.push_back(sx);
	}	
}

void khoiTaoNhanVien(CongTy &ct, int n, int m)
{
	nhapNVVP(ct, n);
	nhapNVSX(ct, m);
}

/* 2. Xuat ra thong tin cac nhan vien vua nhap ( tu dong 83 -> 107)
Ouput:
	+ In ra man hinh thong tin cac nhan vien vua nhap
*/
void xuatNVVP(CongTy &ct, int n)
{
	cout << "\nDanh sach cac nhan vien van phong:\n";
	for(int i = 0; i < n; i++){
		cout << ct.dsVP[i].hoTen << "\n";
		cout << ct.dsVP[i].namSinh << "\n";
		cout << ct.dsVP[i].soNgay << "\n";
	}
}

void xuatNVSX(CongTy &ct, int m)
{
	for(int i = 0; i < m; i++){
		cout << ct.dsSX[i].hoTen << "\n";
		cout << ct.dsSX[i].namSinh << "\n";
		cout << ct.dsSX[i].luongCB << "\n";
		cout << ct.dsSX[i].soSp << "\n";
	}
}

void xuatNhanVien(CongTy &ct, int n, int m)
{
	xuatNVVP(ct, n);
	xuatNVSX(ct, m);
}


/* 3. Tinh tong luong phai tra cho tat ca nhan vien (tu dong 111 -> 120) */
double sum(CongTy &ct){
	double tong = 0;
	for(int i = 0; i < ct.dsVP.size(); i++){
		tong += ct.dsVP[i].luongThucTe();
	}
	for(int i = 0; i < ct.dsSX.size(); i++){
		tong += ct.dsSX[i].luongThucTe();
	}
	return tong;
}


// 4. Cac nhan vien co tien luong lon nhat (tu dong 124 -> 153)

void maxLuong(CongTy &ct) // Ham tim luong lon nhat
{
	for(int i = 0; i < ct.dsVP.size(); i ++)
	{
		luongLonNhat = fmax(luongLonNhat, ct.dsVP[i].luongThucTe());
	}
	for(int i = 0; i < ct.dsSX.size(); i++)
	{
		luongLonNhat = fmax(luongLonNhat, ct.dsSX[i].luongThucTe());
	}
}

// Khai bao 2 vector de luu tru cac nhan vien co tien luong lon nhat, nham tai su dung

vector<NVVP> nvvp_cau4; 
vector<NVSX> nvsx_cau4;

void cau4(CongTy &ct)
{
	for(int i = 0; i < ct.dsVP.size(); i ++)
	{
		if(ct.dsVP[i].luongThucTe() == luongLonNhat){
			nvvp_cau4.push_back(ct.dsVP[i]);
		}
	}
	for(int i = 0; i < ct.dsSX.size(); i++)
	{
		if(ct.dsSX[i].luongThucTe() == luongLonNhat){
			nvsx_cau4.push_back(ct.dsSX[i]);
		}
	}
}

// 5. Tim cac nhan vien tre nhat va co tien luong lon nhat (tu dong 160 -> 194)

void minTuoi(CongTy &ct) // Ham tim tuoi nho nhat, tuoi nho -> nam sinh lon nhat
{
	int minTuoi = 0;
	for(int i = 0; i < ct.dsVP.size(); i ++)
	{
		tuoiNhoNhat = fmax(tuoiNhoNhat, ct.dsVP[i].namSinh);
	}
	for(int i = 0; i < ct.dsSX.size(); i++)
	{
		tuoiNhoNhat = fmax(tuoiNhoNhat, ct.dsSX[i].namSinh);
	}
}

// Tao 2 vector de luu tru
vector<NVVP> nvvp_cau5;
vector<NVSX> nvsx_cau5;

void cau5(CongTy &ct)
{
	for(int i = 0; i < ct.dsVP.size(); i ++)
	{
		if(ct.dsVP[i].namSinh == tuoiNhoNhat){
			if(ct.dsVP[i].luongThucTe() == luongLonNhat){
				nvvp_cau5.push_back(ct.dsVP[i]);
			}
		}
	}
	for(int i = 0; i < ct.dsSX.size(); i ++)
	{
		if(ct.dsSX[i].namSinh == tuoiNhoNhat){
			if(ct.dsSX[i].luongThucTe() == luongLonNhat){
				nvsx_cau5.push_back(ct.dsSX[i]);
			}
		}
	}
}

int main(){
	// Test cau 1
	cout << "CAU 1\n";
	CT ct;
	int n, m;
	cout << "Nhap so luong nhan vien van phong va so luong nhan vien san xuat\n";
	cin >> n >> m;
	fflush(stdin); // Xoa dau cach de thuan tien nhap string
	khoiTaoNhanVien(ct, n, m);
	
	// Test cau 2
	cout << "CAU 2\n";
	xuatNhanVien(ct, n, m);
	
	// Test cau 3
	cout << "CAU 3\n";
	cout << "Tong tien luong: " << sum(ct) << endl;
	
	// Test cau 4
	maxLuong(ct);
	cau4(ct);
	for(int i = 0; i < nvvp_cau4.size(); i++){
		cout << nvvp_cau4[i].hoTen;
	}
	for(int i = 0; i < nvsx_cau4.size(); i++){
		cout << nvsx_cau4[i].hoTen;
	}
	
	// Test cau 5
	for(int i = 0; i < nvvp_cau5.size(); i++){
		cout << nvvp_cau5[i].hoTen;
	}
	for(int i = 0; i < nvsx_cau5.size(); i++){
		cout << nvsx_cau5[i].hoTen;
	}
}


