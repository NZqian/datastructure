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
    static void insert(TreeNode* root, int val){
        if(!root){
            root = new TreeNode(val);
        } else{
            if(val > root->val){
                if(root->right){
                    insert(root->right, val);
                } else{
                    root->right = new TreeNode(val);
                    return;
                }
            } else if(val < root->val){
                if(root->left){
                    insert(root->left, val);
                } else{
                    root->left = new TreeNode(val);
                    return;
                }
            }
        }
    }
    static void DLR(TreeNode* root, TreeNode* target){
        if(!root){
            return;
        } else{
            insert(target, root->val);
            DLR(root->left, target);
            DLR(root->right, target);
        }
    }
    static void LDR(TreeNode* root){
        if(!root){
            return;
        }
        LDR(root->left);
        cout<<root->val<<' ';
        LDR(root->right);
    }
};


int main(){
    TreeNode *root1 = TreeNode::construct();
    TreeNode *root2 = TreeNode::construct();
    TreeNode::DLR(root2, root1);
    TreeNode::LDR(root1);
    cout<<endl;
}
/*
12 8 4 -1 -1 10 -1 -1 16 13 -1 -1 18 -1 -1
17 6 2 -1 -1 9 -1 -1 24 19 -1 -1 26 -1 -1
*/