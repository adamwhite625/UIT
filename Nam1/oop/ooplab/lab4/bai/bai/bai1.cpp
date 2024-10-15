#include <bits/stdc++.h>

using namespace std;

class NhanVien
{
    int maNV;
    string hoTen;
    float luongCB;
    float luongHT;

public:
    NhanVien(){};
    NhanVien(int, string, float);
    void printfNV();
    friend class NVVP();
};

NhanVien::NhanVien(int maNV, string hoTen, float luongCB)
{
    this->maNV = maNV;

    this->luongHT = 0;
}

void NhanVien::printfNV()
{
    printf("[%5d, %10s, %8.2f, %8.2f]",this->maNV, this->hoTen.c_str(), this->luongCB, this->luongHT);
}

class NVVP: public NhanVien
{
    int soNg;
public:
    NVVP(){};
    NVVP(int, string, float, int);
    void printfNVVP();
};

// Triển khai
NVVP::NVVP(int maNV, string hoTen, float luongCB, int soNg):NhanVien(maNV, hoTen,luongCB)
{
    this->soNg = soNg;
}

void NVVP::printfNVVP()
{
    printf("[%5d, %10s, %8.2f, %8.2f, %3d]\n",this->maNV, this->hoTen.c_str(), this->luongCB, this->luongHT, this->soNg);
}

class NVSX: public NhanVien
{
    int soSp;
public:
    NVSX(){};
    NVSX(int, string, float, int);
    void printfNVSX();
};

// Triển khai
NVSX::NVSX(int maNV, string hoTen, float luongCB, int soSp): NhanVien(maNV, hoTen, luongCB)
{
    this->soSp = soSp;
}

int main()
{
    NVVP vp1(123, "Nguyen Van A", 7e6, 21);
    vp1.printfNV();
    return 0;
}
