#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val){
        this->val = val;
    }
};
int main(){
    int childNum = 0;
    string str;
    cin>>str;
    //str = "ABD##EH###CF#I##G##";
    /*
    stack<TreeNode*> stk;
    TreeNode* root = NULL, *cur;
    for(int i = 0; i < str.size(); i++){
        if(i == 0){
            root = new TreeNode(str[i]);
            stk.push(root);
            cur = root;
        } else{
            if(str[i] != '#'){
                cur->left = new TreeNode(str[i]);
                cur = cur->left;
                stk.push(cur);
            }
        }
    }
    */
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '#'){
            int cnt = 0;
            //cout<<i<<' ';
            while(i + cnt < str.size() && str[i+cnt] == '#'){
                cnt++;
            }
            if(cnt > 1){
                childNum++;
            }
            i += cnt;
        }
    }
    cout<<childNum<<endl;
}