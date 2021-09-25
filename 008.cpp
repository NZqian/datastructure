#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int priority(char c){
    if (c == '+' || c == '-'){
        return 1;
    } else if(c == '('){
        return 0;
    } else{
        return 2;
    }
}

bool compare(char c1, char c2){
    return priority(c1) > priority(c2);
}

int main(){
    string str, ans;
    cin>>str;
    //str = "(a+b)";
    queue<char> que;
    stack<char> stk;
    int size = str.size();
    for (int i = 0; i < size; i++){
        char c = str[i];
        if (c >= 'a' && c <= 'z'){
            que.push(c);
        } else{
            if (c == ')'){
                while (stk.top() != '('){
                    while(que.size()){
                        ans.push_back(que.front());
                        que.pop();
                    }
                    ans.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
            }
            else if (!stk.size() || compare(c, stk.top()) || c == '('){
                stk.push(c);
            } else{
                while(que.size()){
                    ans.push_back(que.front());
                    que.pop();
                }
                ans.push_back(stk.top());
                stk.pop();
                stk.push(c);
            }
        }
    }
    while(que.size()){
        ans.push_back(que.front());
        que.pop();
    }
    while(stk.size()){
        ans.push_back(stk.top());
        stk.pop();
    }
    cout << ans << endl;
}