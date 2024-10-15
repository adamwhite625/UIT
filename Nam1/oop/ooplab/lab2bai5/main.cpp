#include <bits/stdc++.h>

using namespace std;

class NhanVien
{
    // Thành phần dữ liệu
private:
    int maNV;
    string hoTen;
    float luongCB;
    int soSP;
    //float luongHT = 0;

    // Thành phần xử lý
public:
    float luongHT = 0;

    NhanVien(int, string, float, int);
    void printf();
    float tinhLuong();
    int getMa();
    void setluongCB(float);
    int getsoSP(); // Viết phương thức getter để lấy giá trị số sp để làm câu 7
};
typedef NhanVien NV;

float NhanVien::tinhLuong()
{
    //cout << luongHT << "hien tai";
    //luongHT = ((float)soSP * (float)175000);
    //cout << luongHT << "sau khi tinh";
    return ((float)luongCB + (float)soSP * (float)5000);
}

NhanVien::NhanVien(int maNV, string hoTen, float luongCB, int soSP)
{
    this->maNV = maNV;
    this->hoTen = hoTen;
    this->luongCB = luongCB;
    this->soSP = soSP;
}

void NV::printf()
{
    cout << "Thong tin nhan vien:" << endl;
    cout << "\t+ Manv    : " << this->maNV << endl;
    cout << "\t+ Ho ten  : " << this->hoTen << endl;
    cout << "\t+ Ho ten  : " << this->luongCB << endl;
    cout << "\t+ luong ht  : " << this->luongHT << endl;
}

int NhanVien::getMa()
{
    return maNV;
}

void NhanVien::setluongCB(float luongCB)
{
    this->luongCB = luongCB;
}

int NhanVien::getsoSP()
{
    return soSP;
}

class CongTy
{
    // Thành phần dữ liệu
    int maCT;
    string tenCT;

    //NhanVien mangNV[200];
    int soNV;

    vector<NhanVien> vtNV;

    // Thành phần xử lý
public:
    CongTy(int, string);
    void initDS_NV();
    void printfDS_NV();
    float tinhLuong();
    void timMa(int);
    void capNhat(int, float);
    void maxLuong();
    void minSP();
    void selctionSort(); // Hàm để sắp xếp lương NV có kiểu dữ liệu là NhanVien, vì mảng nhỏ nên dùng Selection Sort
    void top10();
};

CongTy::CongTy(int maCT, string tenCT)
{
    this->maCT = maCT;
    this->tenCT = tenCT;

    this->soNV = 0;
}

void CongTy::initDS_NV()
{
    NhanVien nv1(122, "Nguyen van A", 9e2, 99);
    NhanVien nv2(123, "Nguyen van B", 6e2, 89);
    NhanVien nv3(124, "Nguyen van C", 8e3, 72);
    NhanVien nv4(125, "Nguyen van D", 3e2, 65);
    NhanVien nv5(126, "Nguyen van E", 9e4, 34);
    NhanVien nv6(127, "Nguyen van F", 5e2, 55);
    NhanVien nv7(128, "Nguyen van G", 1e5, 97);
    NhanVien nv8(129, "Nguyen van H", 2e2, 100);
    NhanVien nv9(130, "Nguyen van I", 8e2, 90);
    NhanVien nv10(131, "Nguyen van J", 3e3, 85);
    NhanVien nv11(132, "Nguyen van K", 4e2, 87);
    NhanVien nv12(133, "Nguyen van L", 2e5, 79);

    this->vtNV.push_back(nv1);
    this->vtNV.push_back(nv2);
    this->vtNV.push_back(nv3);
    this->vtNV.push_back(nv4);
    this->vtNV.push_back(nv5);
    this->vtNV.push_back(nv6);
    this->vtNV.push_back(nv7);
    this->vtNV.push_back(nv8);
    this->vtNV.push_back(nv9);
    this->vtNV.push_back(nv10);
    this->vtNV.push_back(nv11);
    this->vtNV.push_back(nv12);


    this->soNV = vtNV.size();

    //this->vtNV.push_back(nv1);
}
// 2 xuat cac nhan vien cong ty
void CongTy::printfDS_NV()
{
    /*for(int i = 0; i < this->soNV; i++)
    {
        this->mangNV[i].printf();
    } */

    cout << "In tu vector: \n";
    for(int i = 0; i < this->vtNV.size(); i++)
    {
        this->vtNV[i].printf();
    }
}

// 3. Tinh luong nhan vien
float CongTy::tinhLuong()
{
    for(int i = 0; i < vtNV.size(); i++)
    {
        vtNV[i].luongHT = vtNV[i].tinhLuong();
        if(vtNV[i].luongHT >= 10000000)
        {
            vtNV[i].luongHT *= 1.1;
        }
    }
}

// 4.
void CongTy::timMa(int ma)
{
    for(int i = 0; i < vtNV.size(); i++)
    {
        if(ma == vtNV[i].getMa())
        {
            vtNV[i].printf();
        }
    }
}

// 5
void CongTy::capNhat(int ma, float luongCB)
{
    for(int i = 0; i < vtNV.size(); i++)
    {
        if(ma == vtNV[i].getMa())
        {
            vtNV[i].setluongCB(luongCB);
        }
    }
}


// 6
void CongTy::maxLuong()
{
    float MAX = vtNV[0].luongHT;
    for(int i = 1; i < vtNV.size(); i++)
    {
        if(vtNV[i].luongHT >= MAX)
        {
            MAX = vtNV[i].luongHT;
        }
    }
    for(int i = 0; i < vtNV.size(); i++)
    {
        if(vtNV[i].luongHT == MAX)
        {
            vtNV[i].printf();
        }
    }
}

// 7
void CongTy::minSP()
{
    int MIN = vtNV[0].getsoSP();
    for(int i = 1; i < vtNV.size(); i++)
    {
        if(vtNV[i].getsoSP() < MIN)
        {
            MIN = vtNV[i].getsoSP();
        }
    }
    for(int i = 0; i < vtNV.size(); i++)
    {
        if(vtNV[i].getsoSP() == MIN)
        {
            vtNV[i].printf();
        }
    }
}

// 8
void CongTy::selctionSort()
{
    for(int i = 0; i < vtNV.size() - 1; i++)
    {
        int min_pos = i;
        for(int j = i + 1; j < vtNV.size(); i++)
        {
            if(vtNV[j].luongHT < vtNV[min_pos].luongHT)
            {
                min_pos = j;
            }
        }
        swap(vtNV[i], vtNV[min_pos]);
    }
}
void CongTy::top10()
{
    selctionSort();
    for(int i = 0; i < 10; i++)
    {
        vtNV[i].printf();
    }
}

int main()
{
    CongTy ct(210, "UIT");

    // Test 1
    ct.initDS_NV();

    // Test 2
    ct.printfDS_NV();

    // Test 3
    ct.tinhLuong();
    ct.printfDS_NV();

    // Test 4
    ct.timMa(123);

    // Test 5
    ct.capNhat(123, 500);
    ct.printfDS_NV();

    // Test 6
    ct.maxLuong();

    // Test 7
    ct.minSP();

    // Test 8
    //ct.top10();
    return 0;
}
