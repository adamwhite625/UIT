#include<bits/stdc++.h>
 
using namespace std;

struct point
{
	int x;
	int y;
};

int partition(point a[], int l, int r){
	int i = l - 1;
	point pivot = a[r];
	for(int j = l; j < r; j++){
		if(a[j].x < pivot.x){
			++i;
			swap(a[i], a[j]);
		}
		else if(a[j].x == pivot.x){
			if(a[j].y > pivot.y){
				++i;
				swap(a[i], a[j]);
		}
		}
	}
	++i;
	swap(a[i], a[r]);
	return i;
}

void quick(point a[], int l, int r){
	if(l < r){
		int pos = partition(a, l, r);
		quick(a, l, pos - 1);
		quick(a, pos + 1, r);
	}
}
 
void printArray(point a[], int n){
    for (int i = 0; i < n; i++){
    	cout << a[i].x << " ";
    	cout << a[i].y << endl;
	}
}

int main(){
	int n;
	cin >> n;
	point a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i].x;
		cin >> a[i].y;
	}
    quick(a, 0, n - 1);
    printArray(a, n);
    
    return 0;
}
