#include <iostream>

using namespace std;

typedef struct PhanSo
{
	int iTuSo;
	int iMauSo;
}PS;

/* 1. Nhap phan so:
Input:
	+ x: PhanSo
	
*/
void scanf(PS &x)
{
	cin >> x.iTuSo;
	cin >> x.iMauSo;
}

/* 2. In phan so:
Input:
	+ x: PhanSo

Output:
	+ In ra man hinh phan so x
*/
void printf(PS &x)
{
	cout << x.iTuSo << "/" << x.iMauSo << endl;
}

/* 3. Rut gon phan so:
Input:
	+ x: PhanSo
Output:
	+ return PhanSo da rut gon
*/

// Ham tim UCLN cua tu so va mau so
int gcd(int a, int b){
	if(b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}

// Rut gon

PS rutGon(PS &x)
{
	int ucln = gcd(x.iTuSo, x.iMauSo);
	x.iTuSo = x.iTuSo / ucln;
	x.iMauSo = x.iMauSo / ucln;
}

/* 4. So sanh 2 phan so:
Input:
	+ x: PhanSo
	+ y: PhanSo
Output:
	+ -1 neu x < y
	+ 0 neu x = y
	+ 1 neu x > y
*/

int soSanh(PS ps1, PS ps2)
{
	double giaTri1 = (double)ps1.iTuSo / ps1.iMauSo;
	double giaTri2 = (double)ps2.iTuSo / ps2.iMauSo;
	
	if (giaTri1 < giaTri2)
	{
		return -1;
	}
	else if (giaTri1 == giaTri2)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/* 9. Tim phan so lon nhat trong nhieu phan so:
Input:
	+ n (so luong phan tu): int
	+ Nhap vao n phan so
Output:
	+ return PhanSo
*/

PhanSo maxPhanSo(PS a[], int n)
{
	PS max = a[0];
	for(int i = 1; i < n; i++)
	{
		// Tai su dung ham so sanh o cau 4
		if (soSanh(max, a[i]) == -1)
		{
			max = a[i];
		}
		cout << max.iTuSo << max.iMauSo;
	}
	return max;
}

int main()
{
	//khai bao va khoi tao so luong test case
	int test;
	cout << "Nhap so luong test case" << endl;
	cin >> test;
	while(test--)
	{	
		cout << "CAU 1" << endl;
		PS x;
		// Test cau 1
		scanf(x);
		
		// test cau 2
		cout << "CAU 2" << endl;
		printf(x);
		
		// Test cau 3
		cout << "\nCAU 3" << endl;
		rutGon(x);
		cout << x.iTuSo << "/" << x.iMauSo << endl;
		
		// Test cau 4
		cout << "\nCAU 4" << endl;
		PS b = {1, 2};
		PS c = {3, 4};
		cout << soSanh(b, c) << endl;
		
		// Test cau 9
		cout << "\nCAU 9" << endl;
		int n;
		cout << "Nhap n:" << endl;
		cin >> n;
		PS a[n];
		cout << "Nhap tung phan so: " << endl;
		
		for(int i = 0; i < n; i++)
		{
			cout << "+ Nhap tu so cua phan so thu " << i + 1 << endl;
			cin >> a[i].iTuSo;
			cout << "+ Nhap mau so cua phan so thu " << i + 1 << endl;
			cin >> a[i].iMauSo;
		}
		
		PS res = maxPhanSo(a, n);
		cout << "Phan so lon nhat la: " << res.iTuSo << "/" << res.iMauSo;
	}
	return 0;
}
