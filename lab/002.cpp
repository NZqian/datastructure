#include <iostream>
using namespace std;
class LinkedNode{
    public:
    int val;
    LinkedNode *prev;
    LinkedNode *next;
    LinkedNode *head;
    LinkedNode *tail;
    LinkedNode(int val){
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
        this->head = this;
        this->tail = this;
    }
    static LinkedNode *initLinkedNode(int size){
        LinkedNode* head = new LinkedNode(-1);
        LinkedNode* cur = head;
        LinkedNode* tail;
        for(int i = 0; i < size; i++){
            cur->next = new LinkedNode(0);
            cur->next->prev = cur;
            cur->head = head;
            cur = cur->next;
        }
        tail = cur;
        while(cur){
            cur->tail = tail;
            cur = cur->prev;
        }
        return head;
    }
    LinkedNode* operator +(LinkedNode* b){
        LinkedNode* head = this;
        LinkedNode* tail_a = this->tail;
        LinkedNode* tail_b = b->tail;
        int carry = 0;
        int sum;
        while(tail_a != head){
            sum = carry + tail_a->val + tail_b->val;
            tail_a->val = sum % 10;
            carry = sum / 10;
            tail_a = tail_a->prev;
            tail_b = tail_b->prev;
        }
        return head;
    }
    LinkedNode* operator *(int n){
        LinkedNode* head = this;
        LinkedNode* cur = this->tail;
        int carry = 0;
        int mult, ans;
        while(cur != head){
            mult = cur->val * n;
            ans = mult + carry;
            cur->val = ans % 10;
            carry = ans / 10;
            cur = cur->prev;
        }
        return head;
    }
    LinkedNode* operator /(int n){
        LinkedNode* head = this;
        LinkedNode* cur = this->next;
        int carry = 0;
        int dividend;
        while(cur != NULL){
            carry = carry * 10;
            dividend = cur->val + carry;
            if(dividend >= n){
                cur->val = dividend / n;
                carry = dividend % n;
            } else{
                carry = carry + cur->val;
                cur->val = 0;
            }
            cur = cur->next;
        }
        return head;
    }
    void print(int n){
        LinkedNode* cur = this->next;
        cout<<cur->val<<'.';
        cur = cur->next;
        for(int i = 0; i < n; i++){
            if(!cur)
                break;
            cout<<cur->val;
            cur = cur->next;
        }
        cout<<endl;
    }
};

class pi{
    public:
    LinkedNode *sum;
    LinkedNode *cur;
    pi(int size){
        sum = LinkedNode::initLinkedNode(size);
        cur = LinkedNode::initLinkedNode(size);
    }
    void calculate(){
        cur->next->val = 1;
        sum = (*sum) + cur;
        for(int i = 2; i < 2000; i++){
            cur = (*cur) * (i-1);
            cur = (*cur) / (2*i-1);
            sum = (*sum) + cur;
        }
        sum = (*sum) * 2;
    }
};
int main(){
    int n;
    cin>>n;
    pi p(1000);
    p.calculate();
    p.sum->print(n);
}