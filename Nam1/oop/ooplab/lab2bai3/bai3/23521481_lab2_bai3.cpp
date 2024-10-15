#include <bits/stdc++.h>

using namespace std;

class Diem
{
    // Thuộc tính
public:
    float x;
    float y;

    // Phương thức
public:
    Diem(){};
    Diem(float, float);
    void xuat();
};


Diem::Diem(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Diem::xuat()
{
    cout << "(" << x << ", " << y << ")";
}

class TamGiac
{
    Diem A;
    Diem B;
    Diem C;
public:
    TamGiac(){};
    TamGiac(Diem, Diem, Diem);
    void xuatDinh();
    void xuatLoaiTamGiac();
    float tinhChuVi();
    float tinhDienTich();
    void xuatChuVi();
    void xuatDienTich();
};

 // 1. Khởi tạo tam giác
TamGiac::TamGiac(Diem a, Diem b, Diem c):A(a), B(b), C(c)
{

}

    //2. Xuất thông tin tam giác
void TamGiac::xuatDinh()
{
    cout << "Cac dinh cua tam giac la: ";
    A.xuat();
    cout << ", ";
    B.xuat();
    cout << ", ";
    C.xuat();
    cout << endl;
}

    // 3. Xét loại tam giác
void TamGiac::xuatLoaiTamGiac()
{
    float AB = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
    float AC = sqrt(pow(C.x - A.x, 2) + pow(C.y - A.y, 2));
    float BC = sqrt(pow(C.x - B.x, 2) + pow(C.y - B.y, 2));

    if (AB == AC && AC == BC)
        cout << "Tam giac ABC la tam giac deu" << endl;
    else if (AB == AC || AB == BC || AC == BC)
        cout << "Tam giac ABC la tam giac can" << endl;
    else if (pow(AB, 2) == pow(AC, 2) + pow(BC, 2) || pow(AC, 2) == pow(AB, 2) + pow(BC, 2) || pow(BC, 2) == pow(AB, 2) + pow(AC, 2))
        cout << "Tam giac ABC la tam giac vuong" << endl;
    else
        cout << "Tam giac ABC la tam giac binh thuong" << endl;
}

//4. Tính chu vi

float TamGiac::tinhChuVi()
{
    float AB = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
    float AC = sqrt(pow(C.x - A.x, 2) + pow(C.y - A.y, 2));
    float BC = sqrt(pow(C.x - B.x, 2) + pow(C.y - B.y, 2));

    return AB + AC + BC;
}

void TamGiac::xuatChuVi()
{
    cout << "Chu vi tam giac ABC: " << tinhChuVi() << endl;
}

   //5. Tính diện tích

float TamGiac::tinhDienTich()
{
    float p = tinhChuVi() / 2;
    float AB = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
    float AC = sqrt(pow(C.x - A.x, 2) + pow(C.y - A.y, 2));
    float BC = sqrt(pow(C.x - B.x, 2) + pow(C.y - B.y, 2));

    return sqrt(p * (p - AB) * (p - AC) * (p - BC));
}

void TamGiac::xuatDienTich()
{
    cout << "Dien tich tam giac ABC: " << tinhDienTich() << endl;
}

int main()
{
    // 1. Khởi tạo tam giác
    Diem A(1, 2);
    Diem B(3, 4);
    Diem C(5, 6);
    TamGiac ABC(A, B, C);

    //2. Xuất thông tin tam giác
    cout << "Test 2: xuat thong tin tam giac\n";
    ABC.xuatDinh();

    // 3. Xét loại tam giác
    cout << "\nTest3: Xet loai tam giac\n";
    ABC.xuatLoaiTamGiac();

    //4. Tính chu vi
    cout << "\nTest 4: Tinh chu vi\n";
    ABC.xuatChuVi();

    //5. Tính diện tích
    cout << "\nTest 5: Tinh dien tich\n";
    ABC.xuatDienTich();

    return 0;
}
