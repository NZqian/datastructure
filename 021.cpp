#include <iostream>
using namespace std;
struct TreeNode{
    char c;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char c){
        this->c = c;
        this->left = NULL;
        this->right = NULL;
    }
    static TreeNode* constructTree(string str){
        int i;
        for(i = 0; str[i] == '(' && str[str.size()-i-1] == ')'; i++);
        str = string(str.begin() + i, str.end() - i);
        //cout<<str<<endl;
        int brace = 0;
        int begin = -1;
        char c;
        bool opflag1 = false, opflag2 = false;
        int pos;
        TreeNode *root, *curNode, *lastNode;
        for(i = str.size() - 1; i >= 0; i--){
            c = str[i];
            if(c == '('){
                brace += 1;
            } else if(c == ')'){
                brace -= 1;
            } else{
                if(!brace){
                    if(c == '+' || c == '-'){
                        opflag1 = true;
                        break;
                    } else if(c == '*' || c == '/'){
                        pos = opflag2 ? pos : i;
                        opflag2 = true;
                    }
                }
            }
        }
        if(opflag1){
            root = new TreeNode(str[i]);
            root->left = constructTree(string(str.begin(), str.begin() + i));
            root->right = constructTree(string(str.begin() + i + 1, str.end()));
        } else if(opflag2){
            root = new TreeNode(str[pos]);
            root->left = constructTree(string(str.begin(), str.begin() + pos));
            root->right = constructTree(string(str.begin() + pos + 1, str.end()));
        } else{
            root = new TreeNode(str[0]);
        }
        return root;
    }
    static string LRU(TreeNode* root){
        string ret;
        if(root){
            ret += LRU(root->left);
            ret += LRU(root->right);
            ret += root->c;
        }
        return ret;
    }
};
int main(){
    string str;
    cin>>str;
    //str =  "((a+b)*c)";
    //str = "A+B*(C-D)-E*F";
    TreeNode* root = TreeNode::constructTree(str);
    string ans = TreeNode::LRU(root);
    cout<<ans<<endl;
}