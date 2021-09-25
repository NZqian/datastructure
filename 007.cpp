#include <iostream>
#include <stack>
using namespace std;
int main(){
    string str;
    cin>>str;
    int size = str.size();
    stack<char> stk;
    for (int i = 0; i < size; i++){
        char c = str[i];
        if (c == '[' || c == ']' || c == '{' || c == '}' || c == '(' || c == ')'){
            if (!stk.size()){
                stk.push(c);
            } else if (stk.top() == '[' && c == ']'){
                stk.pop();
            } else if (stk.top() == '(' && c == ')'){
                stk.pop();
            } else if (stk.top() == '{' && c == '}'){
                stk.pop();
            }
        }
    }
    if(stk.size()){
        cout<<"no"<<endl;
    } else{
        cout<<"yes"<<endl;
    }
}