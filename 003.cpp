#include <iostream>

using namespace std;
void remove(int arr[], int pos, int size);
void find_same(int B[], int sizeb, int C[], int sizec, int D[], int &sized);
int main(){
    int A[100], B[100], C[100], D[100];
    int posa = 0, posb = 0, posc = 0;
    int sizea = 0, sizeb = 0, sizec = 0, sized;
    cin>>sizea>>sizeb>>sizec;
    for(int i = 0; i < sizea; i++)
        cin>>A[i];
    for(int i = 0; i < sizeb; i++)
        cin>>B[i];
    for(int i = 0; i < sizec; i++)
        cin>>C[i];
    find_same(B, sizeb, C, sizec, D, sized);
    for(int i = 0; i < sized; i++){
        int cur = D[i];
        while(posa < sizea && A[posa] < cur){
            posa++;
        }
        if(posa == sizea){
            break;
        }
        if(A[posa] == cur){
            remove(A, posa, sizea);
            sizea--;
        }
    }
    for(int i = 0; i < sizea; i++){
        cout<<A[i]<<' ';
    }
    cout<<endl;
}

void remove(int arr[], int pos, int size){
    for(int i = pos; i < size-1; i++){
        arr[i] = arr[i+1];
    }
}

void find_same(int B[], int sizeb, int C[], int sizec, int D[], int &sized){
    int posb = 0, posc = 0, posd = 0;
    while(posb < sizeb && posc < sizec){
        while(posb < sizeb && B[posb] < C[posc])
            posb++;
        while(posc < sizec && B[posb] > C[posc])
            posc++;
        if(B[posb] == C[posc]){
            D[posd] = B[posb];
            sized++;
            posd++;
            posb++;
            posc++;
        }
    }
}