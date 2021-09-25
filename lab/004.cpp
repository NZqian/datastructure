#include<iostream>
#include<vector>
using namespace std;
struct triplet{
    int i, j;
    int val;
};
struct matrix{
    int m, n;
    int t;
    vector<triplet> data;
    matrix(int m, int n, int t){
        this->m = m;
        this->n = n;
        this->t = t;

        data = vector<triplet>(t);
    }
};
int main(){
    int row, col, t1, t2;
    cin>>row>>col>>t1>>t2;
    matrix m(101, 101, t1);
    matrix n(101, 101, t2);
    matrix ans(101, 101, 202);
    int a, b, c;
    for(int i = 0; i < t1; i++){
        cin>>a>>b>>c;
        m.data[i].i = a;
        m.data[i].j = b;
        m.data[i].val = c;
    }
    for(int i = 0; i < t2; i++){
        cin>>a>>b>>c;
        n.data[i].i = a;
        n.data[i].j = b;
        n.data[i].val = c;
    }
    int posm, posn, posa;
    posm = posn = posa = 0;
    while(posm < m.t && posn < n.t){
        triplet x = m.data[posm];
        triplet y = n.data[posn];
        if(x.i * 101 + x.j < y.i * 101 + y.j){
            ans.data[posa].i = x.i;
            ans.data[posa].j = x.j;
            ans.data[posa].val = x.val;
            posm++;
            posa++;
        } else if(x.i == y.i && x.j == y.j){
            ans.data[posa].i = x.i;
            ans.data[posa].j = x.j;
            ans.data[posa].val = x.val + y.val;
            if(ans.data[posa].val != 0){
                posa++;
            }
            posm++;
            posn++;
        } else{
            ans.data[posa].i = y.i;
            ans.data[posa].j = y.j;
            ans.data[posa].val = y.val;
            posn++;
            posa++;
        }
    }
    while(posm < m.t){
        triplet x = m.data[posm];
        ans.data[posa].i = x.i;
        ans.data[posa].j = x.j;
        ans.data[posa].val = x.val;
        posm++;
        posa++;
    }
    while(posn < n.t){
        triplet y = n.data[posn];
        ans.data[posa].i = y.i;
        ans.data[posa].j = y.j;
        ans.data[posa].val = y.val;
        posn++;
        posa++;
    }
    for(int i = 0; i < posa; i++){
        cout<<ans.data[i].i<<' '<<ans.data[i].j<<' '<<ans.data[i].val<<endl;
    }
}