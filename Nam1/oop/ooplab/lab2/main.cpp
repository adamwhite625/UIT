#include <iostream>

using namespace std;

class PhanSo
{

    // Thành phần dữ liệu => thuộc tính => khai báo biến
private:
    int iTuSo;
    int iMauSo;

    // Thành phần xử lý => Phương thức => Khai báo hàm
public:
    // 1. Khởi tạo phân số (xây dựng constructor)
    //PhanSo();
    PhanSo(int, int);
    void initPS(int, int);

    // 2. Xuất, in phân số
    void printf();

    // 3. Rút gọn phân số đã nhập
    PhanSo rutGon();

    // 4. So sánh 2 phân số
    int soSanh(PhanSo);

    // 5 cong
    PhanSo cong(PhanSo);

    // 7. Nhan hai phân số
    PhanSo nhan(PhanSo);

    // 10.
    PhanSo timMax(PhanSo*, int); // Đưa vào địa chỉ

};
typedef PhanSo PS;
// Triển khai
// 1. Khởi tạo phân số (xây dựng constructor)

/* PhanSo::PhanSo()
{
    // cout << "Constructor khong tham so";
    this->iTuSo = 1;
    this->iMauSo = 1;
} */
// 1
PhanSo::PhanSo(int iTuSo =1, int iMauSo= 1)
{
   this->iTuSo = iTuSo;
   this->iMauSo = iMauSo;
}

// 2. Xuất, in phân số
void PS::printf()
{
    if(this->iMauSo == 1)
    {
        cout << iTuSo << endl;
        return;
    }

    cout << iTuSo << "/" << iMauSo << endl;
}

void PS::initPS(int iTuSo, int iMauSo)
{
    this->iTuSo = iTuSo;
    this->iMauSo = iMauSo;
}

// 3. Rút gọn phân số đã nhập
PhanSo PS::rutGon()
{
    int a = iTuSo, b = iMauSo;

    while(a != b)
    {
        if(a > b)
            a = a - b;
        else if (b > a)
            b = b - a;
    }

    iTuSo = iTuSo/a;
    iMauSo = iMauSo/a;

    //return PhanSo(iTuSo, iMauSo);
    return *this;
}

// 4. So sánh 2 phân số
/*int PS::soSanh(PhanSo other)
{
    return 1;
}
*/
/* 4. So sanh 2 phan so:
Input:
	+ x: PhanSo
	+ y: PhanSo
Output:
	+ -1 neu x < y
	+ 0 neu x = y
	+ 1 neu x > y
*/

int PS::soSanh(PhanSo other)
{
	double gt1 = (double)iTuSo / iMauSo;
        double gt2 = (double)other.iTuSo / other.iMauSo;

        if (gt1 < gt2)
            return -1;
        else if (gt1 > gt2)
            return 1;
        else
            return 0;
}


// 5. cong
PhanSo PhanSo::cong(PhanSo other) {
    int tuSoMoi = iTuSo * other.iMauSo + other.iTuSo * iMauSo;
    int mauSoMoi = iMauSo * other.iMauSo;
    PhanSo tong(tuSoMoi, mauSoMoi);
    return tong.rutGon();
}

// 7.

PS PS::nhan(PhanSo other)
{

    int tu = this->iTuSo * other.iTuSo;
    int mau = this->iMauSo *other.iMauSo;

    return PhanSo(tu, mau).rutGon();
}

// 10.

PhanSo PhanSo::timMax(PhanSo a[], int n)
{

}

int main()
{
    // Test: 1. Khởi tạo phân số
    PhanSo a(1, 2), b(2, 6);
    PhanSo c = PhanSo(3, 6); // Gán

    a.initPS(5, 6);

    PhanSo d;

    cout << "\nTest: 2. In phan so:" << endl;
    a.printf();
    b.printf();
    c.printf();
    d.printf();

    cout << "\nTest: 3. Rut gon phan so:" << endl;
    d = b.rutGon();
    b.printf();
    d.printf();

    cout << "\nTest: 4. So sanh hai phan so:" << endl;
    PhanSo x(2,6), y(6, 8);
    int k = x.soSanh(y);
    cout << k << endl;
    cout << y.soSanh(x);

    cout << "Test 5";
    PS h = x.cong(y);

    cout << "\nTest: 7. Nhan 2 phan so:" << endl;
    PhanSo e = x.nhan(y);
    e.printf();

    cout << "\nTest: 10. Tim phan so lon nhat trong nhieu phan so" << endl;
    PhanSo arr[] = {PhanSo(1, 2), PhanSo(5, 6), PhanSo(1, 8)};
    int n = 3;

    PhanSo p;
    a = p.timMax(arr, n);

    cout << "\nTest: " << endl;


    return 0;
}
