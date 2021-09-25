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
    static void insert(TreeNode *&root, int val){
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
    static void del(TreeNode *&root, int val){
        if(root->val < val){
            del(root->right, val);
        } else if(root->val > val){
            del(root->left, val);
        } else{
            if(!root->left && !root->right){
                root = NULL;
                return;
            } else if(!root->left && root->right){
                root = root->right;
            } else if(root->left && !root->right){
                root = root->left;
            } else{
                TreeNode *rightMin, *rightMinPre;
                if(root->right->left){
                    rightMinPre = root->right;
                    rightMin = root->right->left;
                    while(rightMin->left){
                        rightMinPre = rightMinPre->left;
                        rightMin = rightMin->left;
                    }
                } else{
                    rightMin = root->right;
                    rightMinPre = NULL;
                }
                if(rightMinPre){
                    rightMinPre->left = rightMin->right;
                    rightMin->left = root->left;
                    rightMin->right = root->right;
                    root = rightMin;
                } else{
                    rightMin->left = root->left;
                    root = rightMin;
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
    static void LDR(TreeNode* root, int left, int right){
        if(!root){
            return;
        }
        LDR(root->left, left, right);
        if(root->val > left && root->val < right){
            cout<<root->val<<' ';
        }
        LDR(root->right, left, right);
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
    TreeNode *root = TreeNode::construct();
    int left, right, ins, del;
    cin>>left>>right>>ins>>del;
    TreeNode::LDR(root, left, right);
    cout<<endl;
    TreeNode::insert(root, ins);
    TreeNode::LDR(root);
    cout<<endl;
    TreeNode::del(root, ins);
    TreeNode::del(root, del);
    TreeNode::LDR(root);
    cout<<endl;
}
/*
12 8 4 -1 -1 10 -1 -1 16 13 -1 -1 18 -1 -1
17 6 2 -1 -1 9 -1 -1 24 19 -1 -1 26 -1 -1
*/