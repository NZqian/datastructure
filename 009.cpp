#include <iostream>
using namespace std;
struct que{
    int MAX_QUE_SIZE;
    int *arr;
    int start, end, length;
    que(int size){
        MAX_QUE_SIZE = size;
        arr = new int[MAX_QUE_SIZE];
        start = 0;
        end = 0;
        length = 0;
    }
    bool push(int num){
        if (length == MAX_QUE_SIZE){//queue full
            return false;      
        } else{
            this->arr[end] = num;
            length += 1;
            end = (end + 1) % MAX_QUE_SIZE;
            return true;
        }
    }
    bool pop(){
        if(this->length){
            this->start = (this->start + 1) % MAX_QUE_SIZE;
            length -= 1;
            return true;
        }
        return false;
    }
    int front(){
        return this->arr[this->start];
    }
    void print(){
        //cout<<"here"<<endl;
        for(int i = start; i != end; i = (i + 1) % MAX_QUE_SIZE){
            cout << arr[i] << ' ';
        }
        cout<<endl;
    }
};

int main(){
    int n, num, target;
    string status;
    cin >> n;
    que q(n);
    cin >> num;
    if(!q.push(num)){
        //cout << "yes" << endl; 
    }
    while (cin.get() != '\n'){
        if(q.length == n){
            continue;
        }
        cin >> num;
        q.push(num);
        if(q.length == n){
            //cout << "yes" << endl; 
            cin>>status;
        }
        //cout<<"length "<<q.length<<endl;
    }
    if(q.length < n){
        cin>>status;
    }
    /* 
    for(int i = 0; i < n; i++){
        cout<<q.arr[i]<<' ';
    }
    cout<<endl;
    while(q.length){
        cout<<q.front()<<endl;
        q.pop();
    }
    */
    cin >> target;
    while(q.front() != target){
        q.pop();
        //q.print();
    }
    q.pop();
    q.print();    
    cout<<q.front()<<endl;
}