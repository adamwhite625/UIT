




#include <iostream>
#include <vector>

using namespace std;

class SinhVien
{
protected:
    int loai; // Sinh viên đại học là 1, sinh viên văn bằng 2 là 2
    int maSV;
    string hoTen;
    string diaChi;
    int tinChi;
    float diemTB;
    bool totNghiep = false;
public:
    SinhVien(){};
    SinhVien(int, string, string, int, float);
    virtual void printfSV() = 0;
    virtual void xetTotNghiep() = 0;
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


class SVDH : public SinhVien
{
    string luanVan;
    float diemLV;
public:
    SVDH(){};
    SVDH(int, string, string, int, float, string, float);
    void printfSV();
    void xetTotNghiep();
};

//Triển khai
SVDH::SVDH(int maSV, string hoTen, string diaChi, int tinChi, float diemTB, string luanVan, float diemLV):SinhVien(maSV, hoTen, diaChi, tinChi, diemTB)
{
    this->luanVan = luanVan;
    this->diemLV = diemLV;
    this->loai = 1;
}

void SVDH::printfSV()
{
    printf("[%5d, %10s, %10s, %5d, %8.2f, %10s, %8.2f]\n",this->maSV, this->hoTen.c_str(), this->diaChi.c_str(), this->tinChi, this->diemTB, this->luanVan.c_str(), this->diemLV);
}

void SVDH::xetTotNghiep()
{
    if((tinChi >= 120) && (diemTB >= 5) &&(diemLV >= 5)){
        totNghiep = true;
    }
    else{
        totNghiep = false;
    }
}

class SVVB2: public SinhVien
{
    float diemTN;
public:
    SVVB2(){};
    SVVB2(int, string, string, int, float, float);
    void printfSV();
    void xetTotNghiep();
};


//Triển khai
SVVB2::SVVB2(int maSV, string hoTen, string diaChi, int tinChi, float diemTB, float diemTN):SinhVien(maSV, hoTen, diaChi, tinChi, diemTB)
{
    this->diemTN = diemTN;
    this->loai = 2;
}

void SVVB2::printfSV()
{
    printf("[%5d, %10s, %10s, %5d, %8.2f, %8.2f]\n",this->maSV, this->hoTen.c_str(), this->diaChi.c_str(), this->tinChi, this->diemTB, this->diemTN);
}

void SVVB2::xetTotNghiep()
{
    if((tinChi >= 84) && (diemTB >= 5) && (diemTN >= 5))
        totNghiep = true;
    else{
        totNghiep = false;
    }
}

class DaiHoc
{
    string ten;
    vector<SinhVien*> dsSV;
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
    SinhVien* sv1 = new SVDH(100, "Nguyen Van A", "HCM", 80, 4.5, "web", 7);
    SinhVien* sv2 = new SVDH(101, "Nguyen Van B", "HCM", 125, 9, "app", 8);
    SinhVien* sv3 = new SVDH(102, "Nguyen Van C", "HCM", 130, 8.5, "web", 8);



    SinhVien* sv4 = new SVVB2(103, "Nguyen Van D", "Ha Noi", 90, 7, 9);
    SinhVien* sv5 = new SVVB2(104, "Nguyen Van E", "Ha Noi", 95, 7.5, 9);
    SinhVien* sv6 = new SVVB2(105, "Nguyen Van F", "Ha Noi", 100, 6, 8);

    this->dsSV.push_back(sv1);
    this->dsSV.push_back(sv2);
    this->dsSV.push_back(sv3);

    this->dsSV.push_back(sv4);
    this->dsSV.push_back(sv5);
    this->dsSV.push_back(sv6);
}

//2. Xuất danh sách sinh viên
void DaiHoc::printf()
{
    for(int i = 0; i < this->dsSV.size(); i++)
    {
        this->dsSV[i]->printfSV();
    }
}

//3. Xét tốt nghiệp
void DaiHoc::totNghiep()
{
    for(int i = 0; i < this->dsSV.size(); i++)
    {
        dsSV[i]->xetTotNghiep();
    }
}

//4. Tìm các sinh viên đủ điều kiện tốt nghiệp
void DaiHoc::dkTotNghiep()
{
    for(int i = 0; i < this->dsSV.size(); i++)
    {
        if(dsSV[i]->totNghiep == true){
            dsSV[i]->printfSV();
        }
    }
}

//5.Tìm các sinh viên không đủ điều kiện tốt nghiệp
void DaiHoc::notdkTotNghiep()
{
    for(int i = 0; i < dsSV.size(); i++)
    {
        if(dsSV[i]->totNghiep == false)
            dsSV[i]->printfSV();
    }
}

//6. Tìm sinh viên hệ VB2 có điểm trung bình thấp nhất
void DaiHoc::minVB2()
{
    float nho = 99;
    for(int i = 0; i < dsSV.size(); i++)
    {
        if(dsSV[i]->loai == 2)
        {
            if(dsSV[i]->diemTB < nho)
            {
                nho = dsSV[i]->diemTB;
            }
        }

    }
    for(int i = 0; i < dsSV.size(); i++)
    {
        if(dsSV[i]->loai == 2)
        {
            if(dsSV[i]->diemTB == nho)
            {
                dsSV[i]->printfSV();
            }
        }

    }
}

//7. Cho biết sinh viên đại học nào có điểm trung bình cao nhất
void DaiHoc::maxDH()
{
    float cao = -1;
    for(int i = 0; i < dsSV.size(); i++)
    {
        if(dsSV[i]->loai == 1)
        {
            if(dsSV[i]->diemTB > cao)
            {
                cao = dsSV[i]->diemTB;
            }
        }
    }
    for(int i = 0; i < dsSV.size(); i++)
    {
        if(dsSV[i]->loai == 1)
        {
            if(dsSV[i]->diemTB == cao)
            {
                dsSV[i]->printfSV();
            }
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

    cout << "\nTest 3: Xet tot nghiep: (chi thuc hien xet tot nghiep nen khong in ra)\n";
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
