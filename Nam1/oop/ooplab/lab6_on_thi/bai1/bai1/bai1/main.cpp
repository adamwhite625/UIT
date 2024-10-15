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
    int loai = -1;  // NVVP la 0, NVSX la 1, NVQL la 2
public:
    NhanVien() {}
    NhanVien(int, string, float);

    int getMa() {return maNV;}
    float getLuongHT() {return luongHT;}
    float getLuongCB() {return luongCB;}
    void setLuongCB(float);
    int getLoai() {return loai;}

    void printfNV();
    virtual void tinhLuongHT() = 0;
};

//Triển khai
NhanVien::NhanVien(int maNV, string hoTen, float luongCB) : maNV(maNV), hoTen(hoTen), luongCB(luongCB)
{

}

void NhanVien::printfNV()
{
    printf("[%d, %s, %.0f, %.0f]\n", maNV, hoTen.c_str(), luongCB, luongHT);
}

void NhanVien::setLuongCB(float luongCB)
{
    this->luongCB = luongCB;
}

class NhanVienVanPhong : public NhanVien
{
private:
    int soGio;
    float troCap = 0;
public:
    NhanVienVanPhong() {}
    NhanVienVanPhong(int, string, float, int);
    void tinhLuongHT();
};

//Triển khai
NhanVienVanPhong::NhanVienVanPhong(int maNV, string hoTen, float luongCB, int soGio) : NhanVien(maNV, hoTen, luongCB), soGio(soGio)
{
    loai = 0;
}

void NhanVienVanPhong::tinhLuongHT()
{
    luongHT = luongCB + soGio *220000;
    if(soGio > 100)
    {
        troCap = 5000000;
    }
    luongHT += troCap;
}



class NhanVienSanXuat : public NhanVien
{
    int soSp;
public:
    NhanVienSanXuat() {}
    NhanVienSanXuat(int, string, float, int);
    void tinhLuongHT();
};

//Triển khai
NhanVienSanXuat::NhanVienSanXuat(int maNV, string hoTen, float luongCB, int soSp) : NhanVien(maNV, hoTen, luongCB), soSp(soSp)
{
    loai = 1;
}

void NhanVienSanXuat::tinhLuongHT()
{
    luongHT = luongCB + soSp * 175000;
}

class NhanVienQuanLy : public NhanVien
{
    float heSo;
    float thuong;
public:
    NhanVienQuanLy() {}
    NhanVienQuanLy(int, string, float, float, float);
    void tinhLuongHT();
};

//Triển khai
NhanVienQuanLy::NhanVienQuanLy(int maNV, string hoTen, float luongCB, float heSo, float thuong) : NhanVien(maNV, hoTen, luongCB), heSo(heSo), thuong(thuong)
{
    loai = 2;
}

void NhanVienQuanLy::tinhLuongHT()
{
    luongHT = luongCB * heSo + thuong;
}

class DaiLy
{
    string ten;
    vector<NhanVien*> dsNV;
public:
    DaiLy() {}
    DaiLy(string);

    //1. Khởi tạo dữ liệu cho Đại Lý
    void init();

    //2. Xuất thông tin của các nhân viên
    void xuat();

    //3. Thực hiện việc tính lương cho từng nhân viên
    void tinhLuong();

    //4. Tìm nhân viên theo mã nhân viên
    void timKiem(int);

    //5. Tính trung bình tiền lương hằng tháng mà đại lý trả cho nhân viên
    void luongTrungBinh();

    //6. Cập nhật lương cơ bản theo mã nhân viên
    void capNhat(int, float);

    //7. Tìm nhân viên có lương cơ bản cao nhất
    void maxLuongCB();

    //8. Tìm nhân viên sản xuất có lương cao nhất
    void NVSXmax();

    //9. Tìm các nhân viên có lương cơ bản thấp nhất
    void minLuongCB();
};

// Triển khai
DaiLy::DaiLy(string ten)
{
    this->ten = ten;
}

//1. Khởi tạo dữ liệu cho Đại Lý
void DaiLy::init()
{
    dsNV.push_back(new NhanVienVanPhong(101, "Nguyen A", 4500000, 200));
    dsNV.push_back(new NhanVienVanPhong(102, "Nguyen B", 5600000, 100));
    dsNV.push_back(new NhanVienVanPhong(103, "Nguyen C", 8900000, 90));

    dsNV.push_back(new NhanVienSanXuat(201, "Nguyen D", 7800000, 250));
    dsNV.push_back(new NhanVienSanXuat(202, "Nguyen E", 4500000, 110));
    dsNV.push_back(new NhanVienSanXuat(203, "Nguyen F", 6600000, 360));

    dsNV.push_back(new NhanVienQuanLy(301, "Nguyen G", 8500000, 1.3, 19500000));
    dsNV.push_back(new NhanVienQuanLy(302, "Nguyen H", 7600000, 1.2, 18600000));
}

//2. Xuất thông tin của các nhân viên
void DaiLy::xuat()
{
    for(int i = 0; i < dsNV.size(); i++)
    {
        dsNV[i]->printfNV();
    }
}

//3. Thực hiện việc tính lương cho từng nhân viên
void DaiLy::tinhLuong()
{
    for(int i = 0; i < dsNV.size(); i++)
    {
        dsNV[i]->tinhLuongHT();
    }
    for(int i = 0; i < dsNV.size(); i++)
    {
        dsNV[i]->printfNV();
    }
}

//4. Tìm nhân viên theo mã nhân viên
void DaiLy::timKiem(int ma)
{
    for(int i = 0; i < dsNV.size(); i++)
    {
        if(ma == dsNV[i]->getMa())
        {
            dsNV[i]->printfNV();
        }
    }
}

//5. Tính trung bình tiền lương hằng tháng mà đại lý trả cho nhân viên
void DaiLy::luongTrungBinh()
{
    float sum = 0;
    for(int i = 0; i < dsNV.size(); i++)
    {
        sum = sum + dsNV[i]->getLuongHT();
    }
    float luongTB = sum / dsNV.size();
    printf("%.0f\n", luongTB);
}

//6. Cập nhật lương cơ bản theo mã nhân viên
void DaiLy::capNhat(int ma, float luongMoi)
{
    for(int i = 0; i < dsNV.size(); i++)
    {
        if(ma == dsNV[i]->getMa())
        {
            dsNV[i]->setLuongCB(luongMoi);
            dsNV[i]->printfNV();
        }
    }

}

//7. Tìm nhân viên có lương cơ bản cao nhất
void DaiLy::maxLuongCB()
{
    float MAX = dsNV[0]->getLuongCB();
    for(int i = 1; i < dsNV.size(); i++)
    {
        if(MAX < dsNV[i]->getLuongCB())
        {
            MAX = dsNV[i]->getLuongCB();
        }
    }
    for(int i = 0; i < dsNV.size(); i++)
    {
        if(dsNV[i]->getLuongCB() == MAX)
        {
            dsNV[i]->printfNV();
        }
    }
}

//8. Tìm nhân viên sản xuất có lương cao nhất
void DaiLy::NVSXmax()
{
    float MAX = -1;
    for(int i = 0; i < dsNV.size(); i++)
    {
        if(dsNV[i]->getLoai() == 1)
        {
            if(dsNV[i]->getLuongHT() > MAX)
            {
                MAX = dsNV[i]->getLuongHT();
            }
        }
    }

    for(int i = 0; i < dsNV.size(); i++)
    {
        if(dsNV[i]->getLoai() == 1)
        {
            if(dsNV[i]->getLuongHT() == MAX)
            {
                dsNV[i]->printfNV();
            }
        }
    }
}

//9. Tìm các nhân viên có lương cơ bản thấp nhất
void DaiLy::minLuongCB()
{
    float MIN = dsNV[0]->getLuongCB();
    for(int i = 1; i < dsNV.size(); i++)
    {
        if(MIN > dsNV[i]->getLuongCB())
        {
            MIN = dsNV[i]->getLuongCB();
        }
    }
    for(int i = 0; i < dsNV.size(); i++)
    {
        if(dsNV[i]->getLuongCB() == MIN)
        {
            dsNV[i]->printfNV();
        }
    }
}

int main()
{
    DaiLy dl("UIT");
    //1. Khởi tạo dữ liệu cho Đại Lý
    dl.init();

    //2. Xuất thông tin của các nhân viên
    cout << "Test 2. Xuat thong tin cua cac nhan vien:" << endl;
    dl.xuat();

    //3. Thực hiện việc tính lương cho từng nhân viên
    cout << "\nTest 3. Thuc hien viec tinh luong cho tung nhan vien:" << endl;
    dl.tinhLuong();

    //4. Tìm nhân viên theo mã nhân viên
    cout << "\nTest 4. Tim nhan vien theo ma nhan vien:" << endl;
    dl.timKiem(201);

    //5. Tính trung bình tiền lương hằng tháng mà đại lý trả cho nhân viên
    cout << "\nTest 5. Tinh trung binh tien luong hang thang:" << endl;
    dl.luongTrungBinh();

    //6. Cập nhật lương cơ bản theo mã nhân viên
    cout << "\nTest6. Cap nhat luong co ban theo ma nhan vien:" << endl;
    dl.capNhat(202, 9000000);

    //7. Tìm nhân viên có lương cơ bản cao nhất
    cout << "\nTest 7. Tim nhan vien co luong co ban cao nhat:" << endl;
    dl.maxLuongCB();

    //8. Tìm nhân viên sản xuất có lương cao nhất
    cout << "\nTest 8. Tim nhan vien san xuat co luong cao nhat:" << endl;
    dl.NVSXmax();

    //9. Tìm các nhân viên có lương cơ bản thấp nhất
    cout << "\nTest 9. Tim cac nhan vien co luong co ban thap nhat:" << endl;
    dl.minLuongCB();

    return 0;
}
