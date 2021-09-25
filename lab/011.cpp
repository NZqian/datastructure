#include <iostream>
#define MAX_SIZE 100
#define INF 10000
using namespace std;
struct Graph{
    int vertexNum;
    int oriMatrix[MAX_SIZE][MAX_SIZE];
    int matrix[MAX_SIZE][MAX_SIZE];
    int mid[MAX_SIZE][MAX_SIZE];
    Graph(int n){
        this->vertexNum = n;
    }
    void construct(){
        int dist;
        for(int i = 0; i < vertexNum; i++){
            for(int j = 0; j < vertexNum; j++){
                cin>>dist;
                oriMatrix[i][j] = matrix[i][j] = dist;
            }
        } 
    }
    void floyd(){
        for(int i = 0; i < vertexNum; i++){
            for(int j = 0; j < vertexNum; j++){
                for(int k = 0; k < vertexNum; k++){
                    if(matrix[i][k] + matrix[k][j] < matrix[i][j]){
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                        mid[i][j] = k;
                    }
                }
            }
        }
    }
    void path(int from, int to){
        if(mid[from][to] != 0){
            path(from, mid[from][to]);
            path(mid[from][to], to);
        } else{
            cout<<to<<endl;
        }
    }
    void show(int matrix[MAX_SIZE][MAX_SIZE]){
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
    /*
    G.show(G.matrix);
    cout<<endl;
    G.show(G.mid);
    */

    for(int i = 0; i < distNum; i++){
        cin>>from>>to;
        cout<<from<<endl;
        G.path(from, to);
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

/*
7
0   3   4   10000   10000   10000   10000
3   0   5   6   10  10000   10000
4   5   0   2   10000   8   10000
10000   6   2   0   7   9   16
10000   10  10000   7   0   10000   12
10000   10000   8   9   12  0   14
10000   10000   10000   16  10000   14  0
*/