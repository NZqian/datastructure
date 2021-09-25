#include <iostream>
#include <math.h>
using namespace std;
int nums[] = {22, 41, 53, 46, 30, 13, 01, 67};
int address[11] = {0};
int my_hash(int x){
    return (x * 3) % 11;
}
int search(int x){
    int pos;
    pos = my_hash(x); 
    for(int i = 1; ; i++){
        if(!address[pos]){
            address[pos] = x;
            return i;
        } else{
            pos = my_hash(my_hash(x) + i);
        }
    }
}
int main(){
    int sum = 0;
    for(int i = 0; i < 8; i++){
        sum += search(nums[i]);        
    }
    cout<<ceil(double(sum) / 8)<<endl;
}