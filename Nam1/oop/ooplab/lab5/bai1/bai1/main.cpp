#include <bits/stdc++.h>

using namespace std;

class NhanVien
{
protected:
    int maNV;
    string hoTen;
    float luongCB;
    float luongHT;
    int loai = -1; // NVVP la 0;  NVSX la 1
public:
    NhanVien(){};
    NhanVien(int maNV, string hoTen, float luongCB): maNV(maNV), hoTen(hoTen), luongCB(luongCB), luongHT(0)
    {

    }
    virtual void printfNV();
    virtual void tinhLuongHT() = 0;
    virtual int getSoSp() = 0;
    friend class CongTy;
};
//Triển khai

void NhanVien::printfNV()
{
    printf("[%5d, %10s, %8.2f, %8.2f]\n", this->maNV, this->hoTen.c_str(), this->luongCB, this->luongHT);
}

class NVVP: public NhanVien
{
    int soNg;
public:
    NVVP() {}
    NVVP(int maNV, string hoTen, float luongCB, int soNg):NhanVien(maNV, hoTen, luongCB), soNg(soNg)
    {
        loai = 0;
    }
    void printfNV() override;
    void tinhLuongHT();
    int getSoSp() {return 0;}
};

void NVVP::printfNV()
{
    printf("[%5d, %10s, %8.2f, %8.2f, %3d]\n", this->maNV, this->hoTen.c_str(), this->luongCB, this->luongHT, this->soNg);
}

void NVVP::tinhLuongHT()
{
    float luong = luongCB + soNg * 250000;
    if(soNg < 15){
        luong *= 1.2;
    }
    luongHT = luong;
}

class NVSX: public NhanVien
{
    int soSp;
public:
    NVSX() {}
    NVSX(int maNV, string hoTen, float luongCB, int soSp):NhanVien(maNV, hoTen, luongCB), soSp(soSp)
    {
        loai = 1;
    }
    int getSoSp() {return soSp;}
    void printfNV();
    void tinhLuongHT();
};

void NVSX::printfNV()
{
    printf("[%5d, %10s, %8.2f, %8.2f, %3d]\n", this->maNV, this->hoTen.c_str(), this->luongCB, this->luongHT, this->soSp);
}

void NVSX::tinhLuongHT()
{
    float luong = luongCB + soSp * 175000;
    if(luong >= 1e7)
    {
        luong *= 1.1;
    }
    if(soSp < 10)
    {
        luong *= 1.3;
    }
    luongHT = luong;
}

class CongTy
{
private:
    int maCT;
    string tenCT;
    vector<NhanVien*> ds;

public:
    CongTy(int maCT, string tenCT):maCT(maCT), tenCT(tenCT)
    {

    }
    // 1. Tạo dữ liệu nhân viên
    void initDsNV();

    // 2. Xuất các nhân viên trong công ty
    void printfDsNV();

    //3. Tính lương nhân viên trong công ty
    void tinhLuongHT();

    //4. TÌm nhân viên thao mã nhân viên
    void timNV(int);

    //5. Cập nhật lương cơ bản nhân viên theo mã nhân viên
    void capNhat(int, float);

    //6. Tìm nhân viên có lương cao nhất
    void maxLuong();

    //7. Tìm nhân viên có số sản phẩm được bán thấp nhất
    void minSP();

    // 8. Tìm 10 nhân viên có lương cao nhất
    void selctionSort(); // Tạo hàm để sắp xếp vector có kiểu dữ liệu NhanVien, sắp xếp giảm dần
    void top10();
};

// 1. Tạo dữ liệu nhân viên
void CongTy::initDsNV()
{
    NhanVien* pVP1 = new NVVP(123, "nguyen van a", 7e6, 22);
    NhanVien* pSX1 = new NVSX(124, "nguyen van b", 9e6, 98);

    NhanVien* pVP2 = new NVVP(125, "nguyen van c", 8e6, 23);
    NhanVien* pSX2 = new NVSX(126, "nguyen van d", 6e6, 59);

    NhanVien* pVP3 = new NVVP(127, "nguyen van e", 5e6, 12);
    NhanVien* pSX3 = new NVSX(128, "nguyen van f", 9e6, 67);

    this->ds.push_back(pVP1);
    this->ds.push_back(pSX1);
    this->ds.push_back(pVP2);
    this->ds.push_back(pSX2);
    this->ds.push_back(pVP3);
    this->ds.push_back(pSX3);

    this->ds.push_back(new NVVP(129, "nguyen van h", 2e6, 10));
}

// 2. In danh sách nhân viên
void CongTy::printfDsNV()
{
    for(int i = 0; i < ds.size(); i++)
    {
        ds[i]->printfNV();
    }
}

// 3. Tính lương các nhân viên trong công ty
void CongTy::tinhLuongHT()
{
    for(int i = 0; i < ds.size(); i++)
    {
        ds[i]->tinhLuongHT();
    }
}

//4. TÌm nhân viên thao mã nhân viên
void CongTy::timNV(int ma)
{
    for(int i = 0; i < ds.size(); i++)
    {
        if(ds[i]->maNV == ma)
        {
            ds[i]->printfNV();
        }
    }
}

//5. Cập nhật lương cơ bản nhân viên theo mã nhân viên
void CongTy::capNhat(int ma, float luong)
{
    for(int i = 0; i < ds.size(); i++)
    {
        if(ds[i]->maNV == ma)
        {
            ds[i]->luongCB = luong;
            ds[i]->printfNV();
        }
    }
}

//6. Tìm nhân viên có lương cao nhất
void CongTy::maxLuong()
{
    float MAX = 0;
    for(int i = 0; i < ds.size(); i++)
    {
        if(ds[i]->luongHT >= MAX)
        {
            MAX = ds[i]->luongHT;
        }
    }

    for(int i = 0; i < ds.size(); i++)
    {
        if(ds[i]->luongHT == MAX)
        {
            ds[i]->printfNV();
        }
    }
}

//7. Tìm nhân viên có số sản phẩm được bán thấp nhất
void CongTy::minSP()
{
    int MIN = 1e9;
    for(int i = 0; i < ds.size(); i++)
    {
        if(ds[i]->loai == 1)
        {
            if(ds[i]->getSoSp() < MIN)
            {
                MIN = ds[i]->getSoSp();
            }
        }
    }
    for(int i = 0; i < ds.size(); i++)
    {
        if(ds[i]->getSoSp() == MIN)
        {
            ds[i]->printfNV();
        }
    }
}

// 8. Tìm 10 nhân viên có lương cao nhất
void CongTy::selctionSort() // Sắp xếp giảm dần
{
    for(int i = 0; i < ds.size() - 1; i++)
    {
        int max_pos = i;
        for(int j = i + 1; j < ds.size(); j++)
        {
            if(ds[j]->luongHT > ds[max_pos]->luongHT)
            {
                max_pos = j;
            }
        }
        swap(ds[i], ds[max_pos]);
    }
}
void CongTy::top10()
{
    //selctionSort();
    for(int i = 0; i < 10; i++)
    {
        ds[i]->printfNV();
    }
}

int main()
{

    // Test 1. Khởi tạo danh sách nhân viên
    CongTy ct(210, "MTV UIT: Dong Goi - Ke Thua - Da Hinh");
    ct.initDsNV();

    cout << "Test 2: In danh sach nhan vien:" << endl;
    ct.printfDsNV();

    cout << "\nTest 3 : Tinh luong cac nhan vien trong cong ty" << endl;
    ct.tinhLuongHT();
    ct.printfDsNV();

    cout << "\nTest 4 : Tim nhan vien theo ma nhan vien:" << endl;
    ct.timNV(123);

    cout << "\nTest 5: Cap nhat luong co ban theo ma nhan vien :" << endl;
    ct.capNhat(123, 500000);


    cout << "\nTest 6. Tim nhan vien co luong cao nhat:\n";
    ct.maxLuong();

    cout << "\nTest 7. Tim nhan vien co so san pham duoc ban thap nhat:\n";
    ct.minSP();

    cout << "\nTest 8: Tim 10 nhan vien co luong cao nhat:" << endl;
    ct.selctionSort();
    ct.top10();
    return 0;
}
