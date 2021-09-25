#include <iostream>
#define MAX_SIZE 100
#define INF 10000
using namespace std;
struct Graph{
    int vertexNum;
    int matrix[MAX_SIZE][MAX_SIZE];
    Graph(int n){
        this->vertexNum = n;
    }
    void construct(){
        int dist;
        for(int i = 0; i < vertexNum; i++){
            for(int j = 0; j < vertexNum; j++){
                cin>>dist;
                matrix[i][j] = dist;
            }
        } 
    }
    void floyd(){
        for(int i = 0; i < vertexNum; i++){
            for(int j = 0; j < vertexNum; j++){
                for(int k = 0; k < vertexNum; k++){
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }
    void show(){
        for(int i = 0; i < vertexNum; i++){
            for(int j = 0; j < vertexNum; j++){
                cout<<matrix[i][j]<<' ';
            }
            cout<<endl;
        }
    }
};
int main(){
    int n;
    cin>>n;
    Graph G(n);
    G.construct();
    G.floyd();
    int distNum, from, to;
    cin>>distNum;
    for(int i = 0; i < distNum; i++){
        cin>>from>>to;
        cout<<G.matrix[from][to]<<endl;
    }
}
/*
4
0 2 10 10000
2 0 7 3
10 7 0 6
10000 3 6 0
2
0 2
3 0
*/