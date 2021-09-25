#include <iostream>
using namespace std;
struct que{
    int MAX_QUE_SIZE;
    int *arr;
    int start, end, length, target;
    que(int size, int target){
        MAX_QUE_SIZE = size;
        arr = new int[MAX_QUE_SIZE];
        start = 0;
        end = 0;
        length = 0;
        this->target = target;
    }
    void print(){
        //cout<<"start "<<start<<" end "<<end;
        for(int i = start; i != end; i = (i + 1) % MAX_QUE_SIZE){
            cout << arr[i] << ' ';
        }
        cout<<arr[end]<<endl;
    }
    int sum(){
        int s = 0;
        for(int i = 0; i < MAX_QUE_SIZE; i++){
            s += arr[i];
        }
        return s;
    }
    void calculate(){
        for(int i = 0; i < MAX_QUE_SIZE - 1; i++){
            arr[i] = 0;
        }
        arr[MAX_QUE_SIZE-1] = 1;
        end = MAX_QUE_SIZE-1;
        int s = sum();
        while(s < target){
            end = (end + 1) % MAX_QUE_SIZE;
            arr[end] = s;
            start = (start + 1) % MAX_QUE_SIZE;
            /*
            cout<<"---------"<<endl;
            this->print();
            cout<<sum<<endl;
            */
            s = sum();
        }
    }
};
int main(){
    int target, size;
    cin >> target >> size;
    //target = 14, size = 2;
    que q(size, target);
    q.calculate();
    q.print();
}