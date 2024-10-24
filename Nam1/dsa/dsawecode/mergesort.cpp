#include<iostream>
 
using namespace std;
int arr[1000];
int n;

void printArray(int a[], int n){
    for (int i = 0; i < n; i++){
    	cout << a[i] << " ";
	}
}

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++){
    	L[i] = arr[l + i];
	}  
    for (j = 0; j < n2; j++){
    	R[j] = arr[m + 1+ j];
	}
    i = 0;
    j = 0; 
    k = l; 
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
    for(int i = 0; i < l; i++){
    	cout << arr[i] << " ";
	}
	cout << "[ ";
	for(int i = l; i <= r; i++){
		cout << arr[i] << " ";
	}
	cout << "] ";
	for(int i = r + 1; i < n; i++){
		cout << arr[i] << " ";
	}
    cout << endl;
}
void mergeSort(int a[], int l, int r){
    if (l < r){
        int m = l+(r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}
 

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	mergeSort(arr, 0, n - 1);
}
