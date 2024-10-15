#include <iostream>
#include <string>

#define LOAD 0.7;
using namespace std;

struct HocSinh{
	int MaSo;
	string Hoten;
	int Namsinh;
	bool Gioitinh;
	double TBK;
};

struct Node{
	HocSinh data;
	Node *next;
};

struct List{
	Node* head, *tail;
};

Node *CreateNode(HocSinh);
void CreateList(List &);
void AddTail(List&, HocSinh);
int RemoveHead(List &);
int RemoveAfter(List &, Node *);
void DeleteList(List &);

struct Hashtable{
	int m; //kich thuoc bang bam
	int n; //so phan tu trong ban bam
	List *table;
};

void CreateHashtable(Hashtable &, int);
int Hash(Hashtable, int); //ham bam ma so hoc sinh thanh chi so
Node *Search(Hashtable, int);
void PrintHashtable(Hashtable);
void DeleteHashtable(Hashtable &);

void Input(Hocsinh &x){
	cin >> x.MaSo;
	getline(cin>>ws, x.Hoten);
	cin >> x.Gioitinh;
	cin >> x.Namsinh;
	cin >> x.TBK;
}

int main()
{
	Hashtable hashtable;
	int m, n, k;
	Hocsinh hs;
	cin >> m;
	CreateHashtable(hashtable, m);
	for(int i = 0; i < m; i++)
	{
		cin >> k;
		hashtable.n = k;
		for(int j = 0; j < k; j++)
		{
			Input(hs);
			AddTail(hashtable.table[i], hs);
		}
	}
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> k;
		Node *p = Search(hashtable, k);
		if(p == NULL)
			cout << "ko tim thay\n";
		else{
			hs = p->data;
			cout << '[' << hs.Maso << ", " << hs.Hoten << ", " << hs.Gioitinh << ", " <<hs.TBk << endl;
			
		}
	}
	DeleteHashtable(hashtable);
	return 0;
}

void CreateList(List &l)
{
	l.head = l.tail = NULL;
}


