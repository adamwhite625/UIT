#include <iostream>
#include <vector>

using namespace std;

class SinhVien
{
    int maSV;
    string hoTen;
    string diaChi;
    int tinChi;
    float diemTB;
    bool totNghiep = false;
public:
    SinhVien(){};
    SinhVien(int, string, string, int, float);
    void printfSV();
    friend class SVDH;
    friend class SVVB2;
    friend class DaiHoc;
};

//Triển khai
SinhVien::SinhVien(int maSV, string hoTen, string diaChi, int tinChi, float diemTB)
{
    this->maSV = maSV;
    this->hoTen = hoTen;
    this->diaChi = diaChi;
    this->tinChi = tinChi;
    this->diemTB = diemTB;
}

void SinhVien::printfSV()
{
    printf("[%5d, %10s, %10s, %5d, %8.2f]\n",this->maSV, this->hoTen.c_str(), this->diaChi, this->tinChi, this->diemTB);
}

class SVDH : public SinhVien
{
    string luanVan;
    float diemLV;
public:
    SVDH(){};
    SVDH(int, string, string, int, float, string, float);
    void printfSVDH();
    bool xetTotNghiep();
};

//Triển khai
SVDH::SVDH(int maSV, string hoTen, string diaChi, int tinChi, float diemTB, string luanVan, float diemLV):SinhVien(maSV, hoTen, diaChi, tinChi, diemTB)
{
    this->luanVan = luanVan;
    this->diemLV = diemLV;
}

void SVDH::printfSVDH()
{
    printf("[%5d, %10s, %10s, %5d, %8.2f, %10s, %8.2f]\n",this->maSV, this->hoTen.c_str(), this->diaChi.c_str(), this->tinChi, this->diemTB, this->luanVan.c_str(), this->diemLV);
}

bool SVDH::xetTotNghiep()
{
    if((tinChi >= 120) && (diemTB >= 5) &&(diemLV >= 5)){
        return true;
    }
    else{
        return false;
    }
}

class SVVB2: public SinhVien
{
    float diemTN;
public:
    SVVB2(){};
    SVVB2(int, string, string, int, float, float);
    void printfSVVB2();
    bool xetTotNghiep();
};


//Triển khai
SVVB2::SVVB2(int maSV, string hoTen, string diaChi, int tinChi, float diemTB, float diemTN):SinhVien(maSV, hoTen, diaChi, tinChi, diemTB)
{
    this->diemTN = diemTN;
}

void SVVB2::printfSVVB2()
{
    printf("[%5d, %10s, %10s, %5d, %8.2f, %8.2f]\n",this->maSV, this->hoTen.c_str(), this->diaChi.c_str(), this->tinChi, this->diemTB, this->diemTN);
}

bool SVVB2::xetTotNghiep()
{
    if((tinChi >= 84) && (diemTB >= 5) && (diemTN >= 5))
        return true;
    else{
        return false;
    }
}

class DaiHoc
{
    string ten;
    vector<SVDH> vectorDH;
    vector<SVVB2> vectorVB2;
public:
    DaiHoc(){};
    DaiHoc(string);
    //1. Tạo danh sách sinh viên
    void init();

    //2. Xuất danh sách sinh viên
    void printf();

    //3. Xét tốt nghiệp
    void totNghiep();

    //4. Tìm các sinh viên đủ điều kiện tốt nghiệp
    void dkTotNghiep();

    //5.Tìm các sinh viên không đủ điều kiện tốt nghiệp
    void notdkTotNghiep();

    //6. Tìm sinh viên hệ VB2 có điểm trung bình thấp nhất
    void minVB2();

    //7. Cho biết sinh viên đại học nào có điểm trung bình cao nhất
    void maxDH();
};

DaiHoc::DaiHoc(string ten)
{
    this->ten = ten;
}

//1. Tạo danh sách sinh viên
void DaiHoc::init()
{
    SVDH dh1(100, "Nguyen Van A", "HCM", 80, 4.5, "web", 7);
    SVDH dh2(101, "Nguyen Van B", "HCM", 125, 9, "app", 8);
    SVDH dh3(102, "Nguyen Van C", "HCM", 130, 8.5, "web", 8);
    this->vectorDH.push_back(dh1);
    this->vectorDH.push_back(dh2);
    this->vectorDH.push_back(dh3);

    SVVB2 vb1(103, "Nguyen Van D", "Ha Noi", 90, 7, 9);
    SVVB2 vb2(104, "Nguyen Van E", "Ha Noi", 95, 7.5, 9);
    SVVB2 vb3(105, "Nguyen Van F", "Ha Noi", 100, 6, 8);
    this->vectorVB2.push_back(vb1);
    this->vectorVB2.push_back(vb2);
    this->vectorVB2.push_back(vb3);
}

//2. Xuất danh sách sinh viên
void DaiHoc::printf()
{
    cout << "In ds sinh vien dai hoc:\n";
    for(int i = 0; i < this->vectorDH.size(); i++)
    {
        this->vectorDH[i].printfSVDH();
    }
    cout << "In ds nhan vien van bang 2:\n";
    for(int i = 0; i < this->vectorVB2.size(); i++)
    {
        this->vectorVB2[i].printfSVVB2();
    }
}

//3. Xét tốt nghiệp
void DaiHoc::totNghiep()
{
    for(int i = 0; i < this->vectorDH.size(); i++)
    {
        if(this->vectorDH[i].xetTotNghiep() == true)
            this->vectorDH[i].totNghiep = true;
        else{
            this->vectorDH[i].totNghiep = false;
        }
    }
    for(int i = 0; i < this->vectorVB2.size(); i++)
    {
        if(this->vectorVB2[i].xetTotNghiep() == true)
            this->vectorVB2[i].totNghiep = true;
        else{
            this->vectorVB2[i].totNghiep = false;
        }
    }
}

//4. Tìm các sinh viên đủ điều kiện tốt nghiệp
void DaiHoc::dkTotNghiep()
{
    for(int i = 0; i < this->vectorDH.size(); i++)
    {
        if(this->vectorDH[i].totNghiep == true){
            this->vectorDH[i].printfSVDH();
        }
    }
    for(int i = 0; i < this->vectorVB2.size(); i++)
    {
        if(this->vectorVB2[i].totNghiep == true){
            this->vectorVB2[i].printfSVVB2();
        }
    }
}

//5.Tìm các sinh viên không đủ điều kiện tốt nghiệp
void DaiHoc::notdkTotNghiep()
{
    for(int i = 0; i < this->vectorDH.size(); i++)
    {
        if(this->vectorDH[i].totNghiep == false)
            this->vectorDH[i].printfSVDH();
    }
    for(int i = 0; i < this->vectorVB2.size(); i++)
    {
        if(this->vectorVB2[i].totNghiep == false)
            this->vectorVB2[i].printfSVVB2();
    }
}

//6. Tìm sinh viên hệ VB2 có điểm trung bình thấp nhất
void DaiHoc::minVB2()
{
    float nho = 99;
    for(int i = 0; i < this->vectorVB2.size(); i++)
    {
        if(this->vectorVB2[i].diemTB < nho){
            nho = this->vectorVB2[i].diemTB;
        }
    }
    for(int i = 0; i < this->vectorVB2.size(); i++)
    {
        if(this->vectorVB2[i].diemTB == nho)
        {
            this->vectorVB2[i].printfSVVB2();
        }
    }
}

//7. Cho biết sinh viên đại học nào có điểm trung bình cao nhất
void DaiHoc::maxDH()
{
    float cao = -1;
    for(int i = 0; i < this->vectorDH.size(); i++)
    {
        if(this->vectorDH[i].diemTB > cao){
            cao = this->vectorDH[i].diemTB;
        }
    }
    for(int i = 0; i < this->vectorDH.size(); i++)
    {
        if(this->vectorDH[i].diemTB == cao)
        {
            this->vectorDH[i].printfSVDH();
        }
    }
}

int main()
{
    // Test 1. Tạo danh sách sinh viên
    DaiHoc DH("UIT");
    DH.init();

    cout << "\nTest 2: Xuat danh sach sinh vien:\n";
    DH.printf();

    cout << "\nTest 3: Xet tot nghiep:\n";
    DH.totNghiep();

    cout << "\nTest 4: Sinh vien du dieu kien tot nghiep:\n";
    DH.dkTotNghiep();

    cout << "\nTest 5: Sinh vien khong du dieu kien tot nghiep:\n";
    DH.notdkTotNghiep();

    cout << "\nTest 6: Sinh vien VB2 co diem trung binh thap nhat:\n";
    DH.minVB2();

    cout << "\nTest 7: Sinh vien dai hoc co diem trung binh cao nhat:\n";
    DH.maxDH();
    return 0;
}
