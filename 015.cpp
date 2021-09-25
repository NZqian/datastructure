#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val){
        this->val = val;
    }
};
TreeNode* constructTree(const string &str){
    //cout<<str<<endl;
    TreeNode* root = new TreeNode(str[0]);
    if(str.size() > 1){
        int pos = 0;
        int stk = 0;
        for(int i = 2; i < str.size(); i++){
            char c = str[i];
            if(c == '('){
                stk += 1;
            } else if(c == ')'){
                stk -= 1;
            } else if(c == ','){
                if(stk == 0){
                    pos = i;
                    break;
                }
            }
        }
        //cout<<"pos "<<pos<<endl;
        root->left = constructTree(string(str.begin() + 2, str.begin() + pos));
        root->right = constructTree(string(str.begin() + pos + 1, str.end() - 1));
    } else{
        root->left = NULL;
        root->right = NULL;
    }
    return root;
}
void backtract(vector<char>&vec, TreeNode* root){
    if(!root){
        vec.push_back('#');
    } else{
        vec.push_back(root->val);
        if(!root->left && !root->right){
            return;
        }
        backtract(vec, root->left);
        backtract(vec, root->right);
    }
}
int main(){
    string str;
    cin>>str;
    //str = "A(B(#,D),C(E(#,F),#))";
    TreeNode* root = constructTree(str);
    vector<char> vec;
    backtract(vec, root);
    for(int i = 0; i < vec.size(); i++){
        cout<<vec[i];
    }
    cout<<endl;
}