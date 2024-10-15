#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    string id;
    int count;
};

// Hàm so sánh d? s?p x?p c?u trúc Item
bool compare(Item a, Item b) {
    if (a.count != b.count) {
        return a.count > b.count;
    }
    return a.id < b.id;
}


void swap(Item& a, Item& b) {
    Item temp = a;
    a = b;
    b = temp;
}


int partition(vector<Item>& items, int low, int high) {
    int pivot = items[high].count; 
    int i = low - 1; 

    for (int j = low; j <= high - 1; j++) {
        
        if (items[j].count > pivot || (items[j].count == pivot && items[j].id < items[high].id)) {
            i++;
            swap(items[i], items[j]);
        }
    }
    swap(items[i + 1], items[high]);
    return (i + 1);
}


void quick(vector<Item>& items, int low, int high) {
    if (low < high) {
      
        int pi = partition(items, low, high);

     
        quick(items, low, pi - 1);
        quick(items, pi + 1, high);
    }
}

int main() {
    int N;
    cin >> N;
    
    
    vector<Item> items(N);
    for (int i = 0; i < N; ++i) {
        cin >> items[i].id;
        items[i].count = 1;
       
        for (int j = 0; j < i; ++j) {
            if (items[j].id == items[i].id) {
                items[j].count++;
                items[i].count = 0; 
                break;
            }
        }
    }


    quick(items, 0, N - 1);
    

    for (int i = 0; i < N; ++i) {
        if (items[i].count != 0) {
            cout << items[i].id << " " << items[i].count << endl << endl;
        }
    }
    
    return 0;
}
