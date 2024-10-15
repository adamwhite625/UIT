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
    friend class NVVP;
    friend class NVSX;
    friend class CongTy;
    void setluongCB(float);
};

NhanVien::NhanVien(int maNV, string hoTen, float luongCB)
{
    this->maNV = maNV;
    this->hoTen = hoTen;
    this->luongCB = luongCB;
    this->luongHT = 0;
}

void NhanVien::printfNV()
{
    printf("[%5d, %10s, %8.2f, %8.2f]\n",this->maNV, this->hoTen.c_str(), this->luongCB, this->luongHT);
}

void NhanVien::setluongCB(float luongCB)
{
    this->luongCB = luongCB;
}

class NVVP: public NhanVien
{
    int soNg;
public:
    NVVP(){};
    NVVP(int, string, float, int);
    void printfNVVP();
    float tinhLuongHT();
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

float NVVP::tinhLuongHT()
{
    float luong = 0;
    luong = luongCB + soNg * 250000;
    if(this->soNg < 15)
    {
        luong *= 1.2;
    }
    this->luongHT = luong;
    return luongHT;
}

class NVSX: public NhanVien
{
    int soSp;
public:
    NVSX(){};
    NVSX(int, string, float, int);
    void printfNVSX();
    float tinhLuongHT();
    friend class CongTy;

};

// Triển khai
NVSX::NVSX(int maNV, string hoTen, float luongCB, int soSp): NhanVien(maNV, hoTen, luongCB)
{
    this->soSp = soSp;
}

void NVSX::printfNVSX()
{
    printf("[%5d, %10s, %8.2f, %8.2f, %3d]\n",this->maNV, this->hoTen.c_str(), this->luongCB, this->luongHT, this->soSp);
}

float NVSX::tinhLuongHT()
{
    float luong = 0;
    luong = luongCB + soSp * 175000;
    if(luong >= 10000000)
    {
        luong *= 1.1;
    }
    if(this->soSp < 10)
    {
        luong *= 1.3;
    }
    this->luongHT = luong;
    return luongHT;
}

class CongTy
{
    int maCT;
    string tenCT;
    NVVP* mangVP;
    int soVP;
    vector<NVSX> vectorSX;
public:
    CongTy(int, string);

    // 1. Tạo dữ liệu nhân viên
    void initDsNv();

    //2. Xuất các nhân viên trong công ty
    void printfDsNv();

    //3. Tính lương nhân viên trong công ty
    void tinhLuongHT();

    //4. Tìm nhân viên theo mã nhân viên
    void tim(int);

    //5. Cập nhật lương cơ bản nhân viên theo mã nhân viên
    void capNhat(int, float);

    //6. Tìm nhân viên có lương cao nhất
    void maxLuong();

    //7. Tìm nhân viên có số sản phẩm được bán thấp nhất
    void minSP();
};

// Triển khai

CongTy::CongTy(int maCT, string tenCT)
{
    this->maCT = maCT;
    this->tenCT = tenCT;
    this->mangVP = new NVVP[100];
    this->soVP = 0;
}

//1. Tạo dữ liệu nhân viên
void CongTy::initDsNv()
{
    NVVP vp1(123, "Nguyen Van A", 7e6, 21);
    NVSX sx1(124, "Nguyen Van B", 8e6, 98);
    NVVP vp2 = NVVP(125, "Nguyen Van T", 7e6, 21);
    NVSX sx2 = NVSX(127, "Nguyen Van D", 7e5, 70);
    NVVP vp3 = NVVP(126, "Nguyen Van C", 7e6, 15);
    NVSX sx3 = NVSX(128, "Nguyen Van E", 7e5, 60);
    this->mangVP[0] = vp1;
    this->mangVP[1] = vp2;
    this->mangVP[2] = vp3;
    this->soVP = 3;

    this->vectorSX.push_back(sx1);
    this->vectorSX.push_back(sx2);
    this->vectorSX.push_back(sx3);
}
//2. In danh sách nhân viên trong công ty
void CongTy::printfDsNv()
{
    cout << "In ds nhan vien van phong tu mang:\n";
    for(int i = 0; i < this->soVP; i++)
    {
        this->mangVP[i].printfNVVP();
    }
    cout << "In ds nhan vien san xuat tu vector:\n";
    for(int i = 0; i < this->vectorSX.size(); i++)
    {
        this->vectorSX[i].printfNVSX();
    }
}

//3. Tính lương nhân viên trong công ty
void CongTy::tinhLuongHT()
{
    float luong = 0;
    for(int i = 0; i < this->soVP; i++)
    {
        this->mangVP[i].tinhLuongHT();
    }

    for(int i = 0; i < this->vectorSX.size(); i++)
    {
        this->vectorSX[i].tinhLuongHT();
    }
}

//4. Tìm nhân viên theo mã nhân viên
void CongTy::tim(int ma)
{
    for(int i = 0; i < this->soVP; i++)
    {
        if(ma == this->mangVP[i].maNV)
        {
            mangVP[i].printfNVVP();
        }
    }
    for(int i = 0; i < this->vectorSX.size(); i++)
    {
        if(ma == this->vectorSX[i].maNV)
        {
            vectorSX[i].printfNVSX();
        }
    }
}

//5. Cập nhật lương cơ bản nhân viên theo mã nhân viên
void CongTy::capNhat(int ma, float luongCB)
{
    for(int i = 0; i < this->soVP; i++)
    {
        if(ma == mangVP[i].maNV)
        {
            mangVP[i].setluongCB(luongCB);
        }
    }
    for(int i = 0; i < this->vectorSX.size(); i++)
    {
        if(ma == vectorSX[i].maNV)
        {
            vectorSX[i].setluongCB(luongCB);
        }
    }
}

// 6. Tìm nhân viên có lương cao nhất
void CongTy::maxLuong()
{
    float MAX = 0;
    for(int i = 0; i < this->soVP; i++)
    {
        if(mangVP[i].luongHT >= MAX)
        {
            MAX = mangVP[i].luongHT;
        }
    }

    for(int i = 0; i < vectorSX.size(); i++)
    {
        if(vectorSX[i].luongHT >= MAX)
        {
            MAX = vectorSX[i].luongHT;
        }
    }

    for(int i = 0; i < soVP; i++)
    {
        if(mangVP[i].luongHT == MAX)
        {
            mangVP[i].printfNVVP();
        }
    }

    for(int i = 0; i < vectorSX.size(); i++)
    {
        if(vectorSX[i].luongHT == MAX)
        {
            vectorSX[i].printfNVSX();
        }
    }
}

//7. Tìm nhân viên có số sản phẩm được bán thấp nhất
void CongTy::minSP()
{
    int MIN = vectorSX[0].soSp;
    for(int i = 1; i < vectorSX.size(); i++)
    {
        if(vectorSX[i].soSp < MIN)
        {
            MIN = vectorSX[i].soSp;
        }
    }
    for(int i = 0; i < vectorSX.size(); i++)
    {
        if(vectorSX[i].soSp == MIN)
        {
            vectorSX[i].printfNVSX();
        }
    }
}


int main()
{

    //Test 1. Khởi tạo danh sách nhân viên
    CongTy ct(210, "UIT");
    ct.initDsNv();

    cout << "Test 2. In danh sach nhan vien:\n";
    ct.printfDsNv();

    cout << "\nTest 3. Tinh luong:\n";
    ct.tinhLuongHT();
    ct.printfDsNv();

    cout << "\nTest 4. Tim nhan vien theo ma:\n";
    ct.tim(123);

    cout << "\nTest 5. Cap nhat luong co ban theo ma nhan vien:\n";
    ct.capNhat(123, 500);
    ct.printfDsNv();

    cout << "\nTest 6. Tim nhan vien co luong cao nhat:\n";
    ct.maxLuong();

    cout << "\nTest 7. Tim nhan vien co so san pham duoc ban thap nhat:\n";
    ct.minSP();

    return 0;
}
