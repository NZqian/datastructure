#include <iostream>
using namespace std;
int main(){
    int m, n;
    int a, b, c;
    cin>>m>>n;
    int M[21][21] = {0};
    for(int i = 0;i < m*n;i++){
        cin>>a>>b>>c;
        if(!a && !b && !c){
            break;
        }
        M[a][b] = c;
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(M[j][i]){
                cout<<i<<' '<<j<<' '<<M[j][i]<<endl;
            }
        }
    }
}