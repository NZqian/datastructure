#include <iostream>
using namespace std;
int main(){
    int m, n;
    int a[20], b[20], c[40];
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    int posa = 0, posb = 0, posc = 0;
    while(posa < m && posb < n){
        if(a[posa] < b[posb]){
            c[posc] = a[posa];
            posc++;
            posa++;
        } else{
            c[posc] = b[posb];
            posc++;
            posb++;
        }
    }
    while(posa < m){
        c[posc] = a[posa];
        posa++;
        posc++;
    }
    while(posb < n){
        c[posc] = b[posb];
        posb++;
        posc++;
    }
    //cout<<"size "<<m+n<<endl;
    for(int i = 0; i < m+n; i++){
        cout<<c[i]<<endl;
    }
}