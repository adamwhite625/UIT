#include <iostream>
#include <stack>
#include <string>

using namespace std;

string to_string(long long n){
    string s = "";
    while (n > 0){
        s = char (n % 10 + '0') + s;
        n /= 10;
    }
    return s;
}

int main(){
    string s;
    getline(cin, s);
    s = s + '0';
    stack<char> st;
    string str = "";
    for(int i = 0; i < s.length(); i++){
        if(st.empty() || st.top() == s[i]){
            st.push(s[i]);
        }
        else{
            int cnt = 0;
            str = str + st.top();
            while(!st.empty()){
                cnt++;
                st.pop();
            }
            str = str + to_string(cnt);
            st.push(s[i]);
        }
    }
    cout << str;
}
