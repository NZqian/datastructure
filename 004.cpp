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
    int m, n;
    LinkedNode *l1 = new LinkedNode(-1); 
    LinkedNode *l2 = new LinkedNode(-1); 
    LinkedNode *l3 = new LinkedNode(-1);
    cin>>m>>n;
    LinkedNode *p1 = l1, *p2 = l2, *p3 = l3;
    int num;
    for(int i = 0; i < m; i++){
        cin >> num;
        p1->next = new LinkedNode(num);
        p1 = p1->next;
    }
    for(int i = 0; i < n; i++){
        cin >> num;
        p2->next = new LinkedNode(num);
        p2 = p2->next;
    }
    p1 = l1->next, p2 = l2->next;
    LinkedNode *cur;
    while(p1 && p2){
        if(p1->val < p2->val){
            cur = p1;
            p1 = p1->next;
            cur->next = p3->next;
            p3->next = cur;
        } else{
            cur = p2;
            p2 = p2->next;
            cur->next = p3->next;
            p3->next = cur;
        }
    }
    while(p1){
        cur = p1;
        p1 = p1->next;
        cur->next = p3->next;
        p3->next = cur;
    }
    while(p2){
        cur = p2;
        p2 = p2->next;
        cur->next = p3->next;
        p3->next = cur;
    }
    p3 = l3->next;
    while(p3){
        cout<<p3->val<<' ';
        p3 = p3->next;
    }
    cout<<endl;
}