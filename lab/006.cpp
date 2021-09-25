#include<iostream>
#include<vector>
#define MAX_SIZE 5
using namespace std;
struct triplet{
    int i, j;
    int val;
    triplet *right, *down;
    triplet(int i, int j, int val){
        this->i = i;
        this->j = j;
        this->val = val;
        right = NULL;
        down = NULL; 
    }
};
struct matrix{
    int m, n;
    triplet **row;
    triplet **col;
    matrix(int m, int n){
        this->m = m;
        this->n = n;
        row = new triplet*[m+1];
        col = new triplet*[n+1];
        for(int i = 0; i <= m; i++){
            row[i] = new triplet(-1, -1, -1);
        }
        for(int i = 0; i <= n; i++){
            col[i] = new triplet(-1, -1, -1);
        }
    }
    void insert(int i, int j, int val){
        triplet* cur = new triplet(i, j, val);
        triplet* r = row[i];
        triplet* c = col[j];
        while(r->right && r->right->j < j){
            r = r->right;
        }
        cur->right = r->right;
        r->right = cur; 
        while(c->down && c->down->i < i){
            c = c->down;
        }
        cur->down = c->down;
        c->down = cur;
    }
    matrix* mul(matrix *B){
        matrix *C = new matrix(this->m, B->n);
        triplet *r, *c;
        for(int i = 1; i <= this->m; i++){
            for(int j = 1; j <= B->n; j++){
                int sum = 0;
                r = this->row[i];
                c = B->col[j];
                while(r->right && c->down){
                    if(r->right->j < c->down->i){
                        r = r->right;
                    } else if(r->right->j > c->down->i){
                        c = c->down;
                    } else{
                        sum += r->right->val * c->down->val;
                        r = r->right;
                        c = c->down;
                    }
                }
                if(sum){
                    C->insert(i, j, sum);
                }
            }
        }
        return C;
    }
    void print(){
        for(int i = 1; i <= m; i++){
            if(this->row[i]->right){
                triplet* r = row[i]->right;
                while(r){
                    cout<<r->i<<' '<<r->j<<' '<<r->val<<endl;
                    r = r->right;
                }
            }
        }
    }
};
int main(){
    int am, an, bm, bn;
    cin>>am>>an;
    //m = 3, n = 4, t1 = 4, t2 = 4;
    matrix A(am, an);
    int a, b, c;
    while(true){
        cin>>a>>b>>c;
        if(!a && !b && !c){
            break;
        }
        A.insert(a, b, c);
    }
    //cout<<endl;
    //A.print();
    cin>>bm>>bn;
    matrix B(bm, bn);
    while(true){
        cin>>a>>b>>c;
        if(!a && !b && !c){
            break;
        }
        B.insert(a, b, c);
    }
    //cout<<endl;
    //B.print();
/*
    matrix A(3, 3);
    matrix B(3, 3);
    A.insert(1, 1, 1);
    A.insert(2, 2, 2);
    A.insert(2, 3, 4);
    A.insert(3, 1, -4);
    B.insert(1, 3, -2);
    B.insert(2, 3, -5);
    B.insert(3, 1, 8);
    B.insert(3, 2, -6);
    */
    matrix *C = A.mul(&B);
    C->print();
}