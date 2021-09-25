#include <iostream>
#include <stack>
using namespace std;

enum ElemTag{ATOM, LIST};
struct GLNode{
    ElemTag tag;
    union
    {
        char c;
        struct{
            GLNode *hp, *tp;
        }ptr;
    };
    GLNode(char c){
        this->tag = ATOM;
        this->c = c;
    }
    GLNode(){
        this->tag = LIST;
        this->ptr.hp = NULL;
        this->ptr.tp = NULL;
    }
    static GLNode* constructList(string str){
        //cout<<str<<endl;
        GLNode *list, *cur, *curhead;
        list = new GLNode();
        cur = list;
        int brace = 0, start = 1;
        if(str.size() == 1){
            cur = new GLNode(str[0]);
            return cur;
        }
        for(int i = 1; i < str.size() - 1; i++){
            char c = str[i];
            if(i == str.size() - 2){
                GLNode *tmp = constructList(string(str.begin() + start, str.begin() + i + 1));
                cur->ptr.hp = tmp;
                cur = cur->ptr.tp;
            }
            if (c == '('){
                brace += 1;
            } else if (c == ')'){
                brace -= 1;
            } else if (c == ','){
                if (brace == 0){
                    GLNode *tmp = constructList(string(str.begin() + start, str.begin() + i));
                    cur->ptr.tp = new GLNode();
                    cur->ptr.hp = tmp;
                    cur = cur->ptr.tp;
                    start = i + 1;
                }
            }
        }
        return list;
    }
    static int depth(GLNode* head){
        int num = 0;
        GLNode *node = head->ptr.hp;
        if(!node){
            return 0;
        }
        if(node && node->tag == ATOM){
            //cout<<node->c;
            return 0;
        }else{
            //cout<<"(";
            while(node){
                num = max(num, depth(node));
                //cout<<",";
                node = node->ptr.tp;
            }
            //cout<<")";
            return num + 1;
        }
    }
};


int main(){
    string str;
    //cin>>str;
    //str = "((a,b,(c,(d,e),f)),g)";
    //str = "((),a)";
    //str = "(a,(b,c))";
    cin>>str;
    int size = str.size();
    GLNode* head = new GLNode();
    head->ptr.hp = GLNode::constructList(str);
    int depth = GLNode::depth(head);
    cout<<depth<<endl;
    cout<<depth<<endl;
}
