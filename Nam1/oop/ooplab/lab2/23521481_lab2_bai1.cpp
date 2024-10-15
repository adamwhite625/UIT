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
    PhanSo(int, int);

    // 2. Xuất, in phân số
    void printf();

    // 3. Rút gọn phân số đã nhập
    PhanSo rutGon();

    // 4. So sánh 2 phân số
    int soSanh(PhanSo);

    // 5. Cộng 2 phân số
    PhanSo Cong(PhanSo);

    // 6. Trừ 2 phân số
    PhanSo Tru(PhanSo);

    // 7. Nhân 2 phân số
    PhanSo nhan(PhanSo);

    // 8. Chia 2 phân số
    PhanSo Chia(PhanSo);

    // 9. Sao chép 2 phân số
    PhanSo saoChep();

    // 10. Tìm phân số lớn nhất trong nhiều phân số
    PhanSo timMax(PhanSo*, int); // Đưa vào địa chỉ

};
typedef PhanSo PS;
// Triển khai


// 1. Khởi tạo phân số (xây dựng constructor)

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

    iTuSo = iTuSo / a;
    iMauSo = iMauSo / a;
    return *this;
}

// 4. So sánh 2 phân số

/*
Input:
	+ other: PhanSo
Output:
	+ -1 neu x < other
	+ 0 neu x = other
	+ 1 neu x > other
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


// 5. Cộng 2 phân số
/*
Input:
	+ other: PhanSo
Output:
	+ PhanSo sau khi đã cộng và được rút gọn
*/

PhanSo PhanSo::Cong(PhanSo other)
{
    int tuSoMoi = iTuSo * other.iMauSo + other.iTuSo * iMauSo;
    int mauSoMoi = iMauSo * other.iMauSo;
    PhanSo tong(tuSoMoi, mauSoMoi);
    return tong.rutGon();
}

// 6. Trừ 2 phân số
/*
Input:
	+ other: PhanSo
Output:
	+ PhanSo sau khi trừ và được rút gọn
*/

PhanSo PhanSo::Tru(PhanSo other)
{
    int tuSoMoi = iTuSo * other.iMauSo - other.iTuSo * iMauSo;
    int mauSoMoi = iMauSo * other.iMauSo;
    PhanSo hieu(tuSoMoi, mauSoMoi);
    return hieu.rutGon();
}

// 7. Nhân 2 phân số
/*
Input:
	+ other: PhanSo
Output:
	+ PhanSo sau khi nhân và được rút gọn
*/

PS PS::nhan(PhanSo other)
{

    int tu = this->iTuSo * other.iTuSo;
    int mau = this->iMauSo *other.iMauSo;

    return PhanSo(tu, mau).rutGon();
}

// 8. Chia 2 phân số
/*
Input:
	+ other: PhanSo
Output:
	+ PhanSo sau khi chia và được rút gọn
*/

PhanSo PhanSo::Chia(PhanSo other)
{
    // Kiểm tra mẫu số của phân số other khác 0 để tránh chia cho 0
    if (other.iTuSo == 0) {
        cout << "Khong the chia cho 0.\n";
        return 0;
    }
    int tuSoMoi = iTuSo * other.iMauSo;
    int mauSoMoi = iMauSo * other.iTuSo;
    PhanSo thuong(tuSoMoi, mauSoMoi);
    return thuong.rutGon();
}

// 9. Sao chép 2 phân số
PhanSo PhanSo::saoChep()
{
    return PhanSo(iTuSo, iMauSo);
}

// 10. Tìm phân số lớn nhất trong nhiều phân số

PhanSo PhanSo::timMax(PhanSo a[], int n)
{
    PhanSo maxPS = a[0];

    for (int i = 1; i < n; ++i) {
        if (a[i].iTuSo * maxPS.iMauSo > maxPS.iTuSo * a[i].iMauSo) {
            maxPS = a[i];
        }
    }

    return maxPS;
}

int main()
{
    // Các testcase
    int t;
    cin >> t;
    while(t--)
    {
        // Test: 1. Khởi tạo phân số
        PhanSo a(1, 2), b(2, 6);
        PhanSo c = PhanSo(3, 6); // Gán
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
        PhanSo x(5,6), y(6, 8);
        int k = x.soSanh(y);
        cout << k << endl;
        cout << y.soSanh(x);

        cout << "\nTest 5: Cong 2 phan so" << endl;
        PS sum = x.Cong(y);
        sum.printf();

        cout << "\nTest 6: Tru 2 phan so" << endl;;
        PhanSo tru = x.Tru(y);
        tru.printf();

        cout << "\nTest: 7. Nhan 2 phan so:" << endl;
        PhanSo e = x.nhan(y);
        e.printf();

        cout << "\nTest 8: Chia 2 phan so" << endl;
        PS Thuong = x.Chia(y);
        Thuong.printf();

        cout << "\nTest 9: Sao chep 2 phan so" << endl;
        PS m = x.saoChep();
        m.printf();

        cout << "\nTest: 10. Tim phan so lon nhat trong nhieu phan so" << endl;
        PhanSo arr[] = {PhanSo(1, 2), PhanSo(5, 6), PhanSo(1, 8)};
        int n = 3;
        PhanSo p;
        PhanSo psMax;
        psMax = p.timMax(arr, n);
        psMax.printf();
    }

    return 0;
}
