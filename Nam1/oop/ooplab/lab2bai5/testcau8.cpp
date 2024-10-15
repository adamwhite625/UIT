// Test 8
    cout << "\n\nCau 8:\n";
    //ct.selctionSort();
    cout << "dang chay";
    ct.top10();

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
    void selctionSort();
    void top10();
};

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
    //selctionSort();
    for(int i = 0; i < 10; i++)
    {
        vtNV[i].printf();
    }
}
