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
    int m, n; int t;
    triplet **row;
    triplet **col;
    matrix(int m, int n, int t){
        this->m = m;
        this->n = n;
        this->t = t;
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
    void add(matrix *B){
        for(int i = 1; i <= m; i++){
            if(!this->row[i]->right && B->row[i]->right){
                this->row[i] = B->row[i];
            } else if(this->row[i]->right && B->row[i]->right){
                triplet *a = this->row[i];
                triplet *b = B->row[i];
                while(b->right){
                    while(a->right && a->right->j < b->right->j){
                        a = a->right;
                    }
                    if(a->right){
                        if(a->right->j == b->right->j){
                            int sum = a->right->val + b->right->val;
                            if(!sum){
                                a->right = a->right->right;
                            } else{
                                a->right->val = sum;
                            }
                        } else{
                            triplet *cur = new triplet(b->right->i, b->right->j, b->right->val);
                            cur->right = a->right;
                            a->right = cur;
                        }
                    } else{
                        triplet *cur = new triplet(b->right->i, b->right->j, b->right->val);
                        a->right = cur;
                    }
                    b = b->right;
                }
            }
        }
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
    int m, n, t1, t2;
    cin>>m>>n>>t1>>t2;
    //m = 3, n = 4, t1 = 4, t2 = 4;
    matrix A(m, n, t1);
    matrix B(m, n, t2);
    int a, b, c;
    for(int i = 0; i < t1; i++){
        cin>>a>>b>>c;
        A.insert(a, b, c);
    }
    //cout<<endl;
    //A.print();
    for(int i = 0; i < t2; i++){
        cin>>a>>b>>c;
        B.insert(a, b, c);
    }
    //cout<<endl;
    //B.print();

/*
    A.insert(1, 1, 3);
    A.insert(1, 4, 5);
    A.insert(2, 2, -1);
    A.insert(3, 1, 2);
    B.insert(1, 2, 2);
    B.insert(2, 1, 1);
    B.insert(3, 1, -2);
    B.insert(3, 2, 4);
    */
    A.add(&B);
    A.print();
}