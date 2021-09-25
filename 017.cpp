#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
    bool visited;
    TreeNode(char val){
        this->val = val;
        left = NULL;
        right = NULL;
        visited = false;
    }
};
int main(){
    stack<TreeNode*> stk;
    string str, ans;
    cin >> str;
    //str = "*+a(###b#)##c##";
    int size = str.size();;
    TreeNode* root, *cur;
    for(int i = 0; i < size; i++){
        char c = str[i];
        if(i == 0){
            root = new TreeNode(c);
            cur = root;
            stk.push(cur);
        } else{
            if(c == '#'){
                if(cur->visited){
                    ans.push_back(cur->val);
                    stk.pop();
                    if(stk.size())
                        cur = stk.top();
                    else
                        break;
                } else{
                    cur->visited = true;
                }
            } else{
                if(cur->visited){
                    ans.push_back(cur->val);
                    cur->right = new TreeNode(c);
                    stk.pop();
                    cur = cur->right;
                    stk.push(cur);
                } else{
                    cur->left = new TreeNode(c);
                    cur->visited = true;
                    cur = cur->left;
                    stk.push(cur);
                }
            }
        }
    }
    if(stk.size()){
        ans.push_back(stk.top()->val);
    }
    cout<<ans<<endl;
}