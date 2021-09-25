#include <iostream>
using namespace std;
int main(){
    int n, k, x;
    cin>>n>>k;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    for(int i = 0; i < k; i++){
        x = arr[n-1];
        for(int i = n-1; i > 0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = x;
    }
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}