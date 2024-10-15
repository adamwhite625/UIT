#include <bits/stdc++.h>
using namespace std;

void decToBi(int n){
	stack<int> st;
	while(n != 0){
		int tmp = n % 2;
		n = n /2;
		st.push(tmp);
	}
	while(!st.empty()){
		int o = st.top();
		st.pop();
		cout << o;
	}
}

int main(){
	int n;
	cin >> n;
	decToBi(n);
}
