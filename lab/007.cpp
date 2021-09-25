#include <iostream>
#include <vector>
#include <map>
using namespace std;
class TreeNode{
    public:
    TreeNode *left;
    TreeNode *right;
    int val;
    string str;
    bool type; //叶子结点1，否则0
    TreeNode(int val, string str){
        this->val = val;
        this->str = str;
        this->type = 1;
        this->left = NULL;
        this->right = NULL;
    }
    TreeNode(int val){
        this->val = val;
        this->type = 0;
        this->left = NULL;
        this->right = NULL;
    }
    static void sort(vector<TreeNode*> &vec){
        int size = vec.size();
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size-i-1; j++){
                if(vec[j]->val > vec[j+1]->val){
                    swap(vec[j], vec[j+1]);
                }
            }
        }
    }
    static TreeNode* constructTree(){
        int n, val;
        cin>>n;
        vector<string> strVec;
        vector<int> valVec;
        vector<TreeNode*> vec;
        string str;
        TreeNode* node;
        for(int i = 0; i < n; i++){
            cin>>str;
            strVec.push_back(str);
        }
        for(int i = 0; i < n; i++){
            cin>>val;
            valVec.push_back(val);
        }
        for(int i = 0; i < n; i++){
            node = new TreeNode(valVec[i], strVec[i]);
            vec.push_back(node);
        }
        TreeNode* root;
        while(vec.size() > 1){
            TreeNode::sort(vec);
            TreeNode* bindNode = new TreeNode(vec[0]->val + vec[1]->val);
            bindNode->left = vec[0];
            bindNode->right = vec[1];
            vec.erase(vec.begin(), vec.begin()+2);
            vec.push_back(bindNode);
            /*
            for(int i = 0; i < vec.size(); i++){
                cout<<vec[i]->val<<' ';
            }
            cout<<endl;
            */
        }
        return vec[0];
    }
    static void traverse(TreeNode* root, string str, map<string, string> &m){
        if(root->type){
            m[root->str] = str;
            //cout<<root->str<<' '<<str<<endl;
        } else{
            str.push_back('0');
            traverse(root->left, str, m);
            str.pop_back();
            str.push_back('1');
            traverse(root->right, str, m);
            str.pop_back();
        }
    }
    static string decode(TreeNode* root, string str){
        string ans;
        for(int i = 0; i < str.size();){
            TreeNode* p = root;
            int j = 0;
            while(p->type != 1){
                if(str[i+j] == '0'){
                    p = p->left;
                } else{
                    p = p->right;
                } 
                j++;
            }
            i += j;
            ans += p->str;
        }
        return ans;
    }
};

int main(){
    TreeNode* root = TreeNode::constructTree();
    map<string, string> mymap;
    TreeNode::traverse(root, "", mymap);
    string target;
    cin>>target;
    string encode;
    for(int i = 0; i < target.size(); i++){
        string tmp(target.begin() + i, target.begin()+i+1);
        encode += mymap[tmp];
    }
    cout<<encode<<endl;
    cout<<TreeNode::decode(root, encode)<<endl;
}
//5 a b c d e 12 40 15 8 25
//bbbaddeccbbb