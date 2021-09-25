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
TreeNode* constructTree(string &first, string &mid, int &pos, int start, int end){
    if(end <= start || pos > mid.size()){
        return NULL;
    }
    char c = first[pos];
    pos += 1;
    int headPos;
    for(int i = start; i < end; i++){
        if(mid[i] == c){
            headPos = i;
            break;
        }
    }
    TreeNode* root = new TreeNode(c);
    root->left = constructTree(first, mid, pos, start, headPos);
    root->right = constructTree(first, mid, pos, headPos+1, end);
    return root;
}
void backTraverse(TreeNode* root, string &back){
    if(!root)
        return;
    if(!root->left && !root->right){
        back.push_back(root->val);
    } else{
        backTraverse(root->left, back);
        backTraverse(root->right, back);
        back.push_back(root->val);
    }
}
int main(){
    string first, mid, back;
    cin >> first;
    cin >> mid;
    //first = "ABDFGCEH";
    //mid = "BFDGACEH";
    int pos = 0;
    TreeNode* root = constructTree(first, mid, pos, 0, mid.size());
    backTraverse(root, back);
    cout << back << endl;
}