#include <iostream>
#include <vector>

using namespace std;

class NhanVien
{
protected:
    int maNV;
    string hoTen;
    float luongCB;
    float luongHT = 0;
public:
    NhanVien() {}
    NhanVien(int, string, float);
    virtual void printfNV() = 0;
    virtual void tinhLuongHT() = 0;
};

//Triển khai
NhanVien::NhanVien(int maNV, string hoTen, float luongCB) : maNV(maNV), hoTen(hoTen), luongCB(luongCB)
{

}

class lapTrinhVien : public NhanVien
{
private:
    int tangCa;
public:
    lapTrinhVien() {}
    lapTrinhVien(int, string, float, int);
    void tinhLuongHT();
    friend class phanTichVien;
};

//Triển khai
lapTrinhVien::lapTrinhVien(int maNV, string hoTen, float luongCB, int tangCa) : NhanVien(maNV, hoTen, luongCB), tangCa(tangCa)
{

}

void lapTrinhVien::tinhLuongHT()
{
    luongHT = luongCB + tangCa *250000;
}

class phanTichVien : public NhanVien
{
    int tangCa;
    float phuCap;
public:
    phanTichVien() {}
    phanTichVien(int, string, float, int, float);
    void tinhLuongHT();
};

//Triển khai
phanTichVien::phanTichVien(int maNV, Sstring hoTen, float luongCB, int tangCa, float phuCap) : NhanVien(maNV, hoTen, luongCB), tangCa(tangCa), phuCap(phuCap)
{

}

void phanTichVien::tinhLuongHT()
{
    luongHT = luongHT * 1.8;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
