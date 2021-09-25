#include <iostream>
#include <stack>
using namespace std;
class TreeNode{
    public:
    int val;
    int visit;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
        this->visit = 0;
    }
    static TreeNode* construct(){
        stack<TreeNode*> stk;
        TreeNode* root;
        int v;
        cin>>v;
        if(v < 0){
            return NULL;
        } else{
            root = new TreeNode(v);
            stk.push(root);
        }
        while(true){
            cin>>v;
            if(v < 0){
                stk.top()->visit += 1;
                if(stk.top()->visit == 2){
                    while(stk.size() && stk.top()->visit == 2){
                        stk.pop();
                    }
                }
            } else{
                TreeNode* cur = new TreeNode(v);
                if(stk.top()->visit == 0){
                    stk.top()->left = cur;
                } else{
                    stk.top()->right = cur;
                }
                stk.top()->visit += 1;
                stk.push(cur);
            }
            //cout<<stk.size()<<endl;
            if(!stk.size()){
                break;
            }
        }
        return root;
    }
    static int depth(TreeNode* root){
        if(!root){
            return 0;
        } else{
            return max(depth(root->left), depth(root->right)) + 1;
        }
    }
    static bool isSearchTree(TreeNode* root){
        if(!root){
            return true;
        } else{
            if((!root->left || root->left->val < root->val) && isSearchTree(root->left)){
            } else{
                return false;
            }
            if((!root->right || root->right->val > root->val) && isSearchTree(root->right)){
            } else{
                return false;
            }
        }
        return true;
    }
};


int main(){
    TreeNode *root = TreeNode::construct();
    if(TreeNode::isSearchTree(root)){
        cout<<"yes"<<endl;
    } else{
        cout<<"no"<<endl;
    }
}