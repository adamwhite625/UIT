#include <iostream>
#include <vector>
using namespace std;

class NhanVienVanPhong
{
    //Thuộc tính
private:
    int maNV;
    string hoTen;
    float luongCB;
    float luongHT;
    int soNgay;
    //Phương thức
public:
    NhanVienVanPhong(){};
    NhanVienVanPhong(int, string, float, int);
    void printfVanPhong();
    float tinhLuongHT();
    int getMa();
    void setluongCB(float); // Phương thức setter
    float getLuongHT();
};
typedef NhanVienVanPhong NVVP;
//Triển khai

NhanVienVanPhong::NhanVienVanPhong(int maNV, string hoTen, float luongCB, int soNgay)
{
    this->maNV = maNV;
    this->hoTen = hoTen;
    this->luongCB = luongCB;
    this->soNgay = soNgay;
    this->luongHT = 0;
}

void NhanVienVanPhong::printfVanPhong()
{
    printf("[%5d, %15s, %8.2f, %12.2f]\n", this->maNV, this->hoTen.c_str(), this->luongCB, this->luongHT);
}

float NhanVienVanPhong::tinhLuongHT()
{
    //lương cơ bản + số ngày làm việc * 250.000đ
    //Nếu số ngày làm việc < 15 thì phụ cấp thêm 20%
    int luong = 0;

    luong = this->luongCB + this->soNgay * 250000;
    if(this->soNgay < 15)
    {
        luong *= 1.2;
    }
    this->luongHT = luong;
    return luong;
}
int NhanVienVanPhong::getMa()
{
    return maNV;
}

void NhanVienVanPhong::setluongCB(float luongCB)
{
    this->luongCB = luongCB;
}

float NhanVienVanPhong::getLuongHT()
{
    return luongHT;
}


class NhanVienSanXuat
{
    // Thuộc tính
private:
    int maNV;
    string hoTen;
    float luongCB;
    float luongHT;
    int soSP;
    // Phương thức
public:
    NhanVienSanXuat(){};
    NhanVienSanXuat(int, string, float, int);
    void printfSanXuat();
    float tinhLuongHT();
    int getMa();
    void setluongCB(float); // Phương thức setter
    float getLuongHT();
    int getsoSP(); // Viết phương thức getter để lấy giá trị số sp
};
typedef NhanVienSanXuat NVSX;

//Triển khai

NhanVienSanXuat::NhanVienSanXuat(int maNV, string hoTen, float luongCB, int soSP)
{
    this->maNV = maNV;
    this->hoTen = hoTen;
    this->luongCB = luongCB;
    this->soSP = soSP;
    this->luongHT = 0;
}

void NhanVienSanXuat::printfSanXuat()
{
    printf("[%5d, %15s, %8.2f, %12.2f]\n", this->maNV, this->hoTen.c_str(), this->luongCB, this->luongHT);
}

float NhanVienSanXuat::tinhLuongHT()
{
    //lương cơ bản + số sản phẩm * 150.000đ
    //Nếu lương từ 10 triệu trở lên thì thưởng thêm 10%, nếu số sản phẩm < 10 thì phụ cấp thêm 30%
    float luong = 0;

    luong = this->luongCB + this->soSP * 150000;
    if(luong > 1e7)
    {
        luong *= 1.1;
    }
    if(this->soSP < 10)
    {
        luong *= 1.3;
    }
    this->luongHT = luong;
    return luong;
}

int NhanVienSanXuat::getMa()
{
    return maNV;
}

void NhanVienSanXuat::setluongCB(float luongCB)
{
    this->luongCB = luongCB;
}

float NhanVienSanXuat::getLuongHT()
{
    return luongHT;
}

int NhanVienSanXuat::getsoSP()
{
    return soSP;
}

class CongTy
{
    // Thuộc tính
private:
    int maCT;
    string tenCT;
    NhanVienVanPhong* mangVP;
    int soNVVP;
    vector<NVSX> vectorSX;

    // Phương thức
public:
    CongTy(int, string);

    //1. Tạo dữ liệu
    void initDsNV();

    //2. Xuất, in
    void printfDsNV();

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
typedef CongTy CT;
//Triển khai
CongTy::CongTy(int maCT, string tenCT)
{
    this->maCT = maCT;
    this->tenCT = tenCT;

    this->mangVP = new NhanVienVanPhong[100];
    this->soNVVP = 0;
}

//1. Tạo dữ liệu nhân viên
void CongTy::initDsNV()
{
    NhanVienVanPhong vp1(123, "nguyen van a", 7e6, 23);
    NhanVienVanPhong vp2(125, "nguyen van b", 6e6, 20);
    NhanVienVanPhong vp3(126, "nguyen van c", 5e6, 21);
    this->mangVP[0] = vp1;
    this->mangVP[1] = vp2;
    this->mangVP[2] = vp3;

    this->soNVVP = 3;

    NhanVienSanXuat sx1(124, "tran van trui", 9e6, 99);
    NhanVienSanXuat sx2(127, "tran van d", 8e6, 90);
    this->vectorSX.push_back(sx1);
    this->vectorSX.push_back(sx2);
}

//2. In danh sách nhân viên trong công ty
void CongTy::printfDsNV()
{
    cout << "In ds nhan vien van phong tu mang:\n";
    for(int i = 0; i < this->soNVVP; i++)
    {
        this->mangVP[i].printfVanPhong();
    }
    cout << "In ds nhan vien san xuat tu vector:\n";
    for(int i = 0; i < this->vectorSX.size(); i++)
    {
        this->vectorSX[i].printfSanXuat();
    }
}

//3. Tính lương nhân viên trong công ty
void CongTy::tinhLuongHT()
{
    float luong = 0;
    for(int i = 0; i < this->soNVVP; i++)
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
    for(int i = 0; i < this->soNVVP; i++)
    {
        if(ma == this->mangVP[i].getMa())
        {
            mangVP[i].printfVanPhong();
        }
    }
    for(int i = 0; i < this->vectorSX.size(); i++)
    {
        if(ma == this->vectorSX[i].getMa())
        {
            vectorSX[i].printfSanXuat();
        }
    }
}

//5. Cập nhật lương cơ bản nhân viên theo mã nhân viên
void CongTy::capNhat(int ma, float luongCB)
{
    for(int i = 0; i < this->soNVVP; i++)
    {
        if(ma == mangVP[i].getMa())
        {
            mangVP[i].setluongCB(luongCB);
        }
    }
    for(int i = 0; i < this->vectorSX.size(); i++)
    {
        if(ma == vectorSX[i].getMa())
        {
            vectorSX[i].setluongCB(luongCB);
        }
    }
}

// 6. Tìm nhân viên có lương cao nhất
void CongTy::maxLuong()
{
    float MAX = 0;
    for(int i = 0; i < this->soNVVP; i++)
    {
        if(mangVP[i].getLuongHT() >= MAX)
        {
            MAX = mangVP[i].getLuongHT();
        }
    }

    for(int i = 0; i < vectorSX.size(); i++)
    {
        if(vectorSX[i].getLuongHT() >= MAX)
        {
            MAX = vectorSX[i].getLuongHT();
        }
    }

    for(int i = 0; i < soNVVP; i++)
    {
        if(mangVP[i].getLuongHT() == MAX)
        {
            mangVP[i].printfVanPhong();
        }
    }

    for(int i = 0; i < vectorSX.size(); i++)
    {
        if(vectorSX[i].getLuongHT() == MAX)
        {
            vectorSX[i].printfSanXuat();
        }
    }
}

//7. Tìm nhân viên có số sản phẩm được bán thấp nhất
void CongTy::minSP()
{
    int MIN = vectorSX[0].getsoSP();
    for(int i = 1; i < vectorSX.size(); i++)
    {
        if(vectorSX[i].getsoSP() < MIN)
        {
            MIN = vectorSX[i].getsoSP();
        }
    }
    for(int i = 0; i < vectorSX.size(); i++)
    {
        if(vectorSX[i].getsoSP() == MIN)
        {
            vectorSX[i].printfSanXuat();
        }
    }
}

int main()
{
    //Test 1. Khởi tạo danh sách nhân viên
    CongTy ct(210, "UIT");
    ct.initDsNV();

    cout << "Test 2. In danh sach nhan vien:\n";
    ct.printfDsNV();

    cout << "\nTest 3. Tinh luong:\n";
    ct.tinhLuongHT();
    ct.printfDsNV();

    cout << "\nTest 4. Tim nhan vien theo ma:\n";
    ct.tim(123);

    cout << "\nTest 5. Cap nhat luong co ban theo ma nhan vien:\n";
    ct.capNhat(123, 500);
    ct.printfDsNV();

    cout << "\nTest 6. Tim nhan vien co luong cao nhat:\n";
    ct.maxLuong();

    cout << "\nTest 7. Tim nhan vien co so san pham duoc ban thap nhat:\n";
    ct.minSP();


    return 0;
}
