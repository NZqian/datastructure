#include <iostream>

using namespace std;
int find_place(int arr[], int start, int end, int num);
void insert(int arr[], int size, int pos, int num);
int main()
{
    int arr[1001];
    int size, target;
    cin>>size;
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }
    cin>>target;
    int pos = find_place(arr, 0, size, target);
    //cout<< pos;
    insert(arr, size, pos, target);
    for(int i = 0; i <= size; i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

int find_place(int arr[], int start, int end, int num){
    /*
    if(start <= end)
        return end;
    int mid = (start + end) / 2;
    if(arr[mid] == num)
        return mid;
    else if(arr[mid] > num)
        return find_place(arr, start, mid, num);
    else
        return find_place(arr, mid + 1, end, num);
        */
    if(num >= arr[end-1])
        return end;
    for(int i = start+1; i < end; i++){
        if(num < arr[i])
            return i-1;
        else if(num == arr[i])
            return i;
    }
}

void insert(int arr[], int size, int pos, int num){
    for(int i = size; i > pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = num;
}