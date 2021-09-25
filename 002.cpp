#include <iostream>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(int num){
        val = num;
    }
};
int main(){
    int n;
    int arr[1001];
    Node *head = new Node(-1);
    Node *cur = head;
    cin>>n;
    for(int i = 0; i < n; i++){
        int num;
        cin>>num;
        arr[i] = num;
        cur->next = new Node(num);
        cur = cur->next;
    }
    for(int i = 0; i < n / 2; i++){
        swap(arr[i], arr[n-1-i]);
    }
    cur = head->next;
    Node *next = cur->next;
    for(int i = 0; i < n-1; i++){
        Node* nnext = next->next;
        next->next = cur;
        if(i == 0){
            cur->next = NULL;
        }
        Node* test = next;
        cur = next;
        next = nnext;
    }
    head->next = cur;
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    cur = head->next;
    for(int i = 0; i < n; i++){
        cout<<cur->val<<' ';
        cur = cur->next;
    }
    cout<<endl;
}