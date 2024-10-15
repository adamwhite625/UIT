#include <iostream>

using namespace std;

void print(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void insertionSort(int a[], int n){
    for(int i = 1; i < n; i++){
        int pos = i -1, value = a[i];
        while(pos >= 0 && a[pos] > value){
            a[pos + 1] = a[pos];
            --pos;
            print(a, n);
        }
        a[pos + 1] = value;
        print(a, n);
    }

}

int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    insertionSort(a, n);
    print(a, n);
}
