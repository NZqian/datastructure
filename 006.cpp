#include <iostream>

using namespace std;

struct LinkedNode{
    char data;
    LinkedNode* next;
    LinkedNode* prev;
    int freq;

    LinkedNode(char c){
        this->data = c;
        this->next = NULL;
        this->prev = NULL;
        this->freq = 0;
    }
};

void locate_update(LinkedNode* head, char c){
    LinkedNode *p = head->next;
    while(p && p->data != c){
        p = p->next;
    }
    p->freq += 1;
    if(p->freq > head->next->freq){
        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;

        head->next->prev = p;
        p->next = head->next;
        head->next = p;
        p->prev = head; 
    }
}

int main(){
    int m, n;
    cin>>m>>n;
    LinkedNode *l = new LinkedNode(' ');
    LinkedNode *p = l;
    char c;
    for(int i = 0; i < m; i++){
        cin >> c;
        p->next = new LinkedNode(c);
        p->next->prev = p;
        p = p->next;
    }
    p = l;
    /*
    while(p->next){
        cout<<char(p->next->data)<<' ';
        p = p->next;
    }
    cout<<endl;
    */
    for(int i = 0; i < n; i++){
        cin >> c;
        locate_update(l, c);
    }
    p = l->next;
    while(p){
        cout<<p->data<<' ';
        p = p->next;
    }
    cout<<endl;
}