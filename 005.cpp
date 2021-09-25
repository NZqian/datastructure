#include <iostream>

using namespace std;
struct LinkedNode{
    int val;
    LinkedNode* next;
    LinkedNode(int v){
        this->val = v;
        this->next = NULL;
    }
};

int main(){
    LinkedNode *A = new LinkedNode(-1);
    LinkedNode *B = new LinkedNode(-1);
    LinkedNode *C = new LinkedNode(-1);
    LinkedNode *a = A, *b = B, *c = C;
    int x, y, z;
    cin>>x>>y>>z;
    int num;
    for(int i = 0; i < x; i++){
        cin>>num;
        a->next = new LinkedNode(num);
        a = a->next;
    }
    for(int i = 0; i < y; i++){
        cin>>num;
        b->next = new LinkedNode(num);
        b = b->next;
    }
    b = B->next;
    for(int i = 0; i < z; i++){
        cin>>num;
        while(b && b->val < num){
            b = b->next;
        }
        if(!b){
            continue;
        }
        if(b->val == num){
            c->next = new LinkedNode(num);
            c = c->next;
        }
    }
    c = C->next;
    /*
    while(c){
        cout<<c->val<<' ';
        c = c->next;
    }
    */
    a = A;
    while(a->next && c){
        if(a->next->val == c->val){
            LinkedNode *del = a->next;
            a->next = a->next->next;
            delete del;
        }
        while(a->next && a->next->val < c->val){
            a = a->next;
        }
        if(!a->next)
            break;
        while(c && a->next->val > c->val){
            c = c->next;
        }
        if(!c)
            break;
    }
    a = A->next;
    while(a){
        cout<<a->val<<' ';
        a = a->next;
    }
    cout<<endl;
}
/*
8 5 6
1 2 3 4 5 6 6 7
2 3 5 9 12
2 4 5 6 12 13
*/