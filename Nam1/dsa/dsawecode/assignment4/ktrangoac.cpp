#include <bits/stdc++.h>
using namespace std;

int ktra(string s){
	stack<char> st;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '{' || s[i] == '(' || s[i] == '['){
			st.push(s[i]);
		}
		else if(s[i] == '}' || s[i] == ')' || s[i] == ']'){
		   	if(st.empty()) return 0;
		    if((s[i] == '}' && st.top() == '{') || (s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[')) st.pop();
			

			else return 0;
		}
	}
	if(st.empty()){
		return 1;
	}
	else return 0;
}

int main(){
	string s;
	getline(cin, s);
	cout << ktra(s);
}
