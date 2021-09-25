#include <iostream>
#define MAX_SIZE 100
#define INF 10000
using namespace std;
struct Graph{
    int vertexNum;
    int matrix[MAX_SIZE][MAX_SIZE];
};
void dijkstra(Graph G, int from, int prev[], int dist[]){
    int minDist;
    int minPos;
    int flag[MAX_SIZE];
    //init
    for(int i = 0; i < G.vertexNum; i++){
        prev[i] = 0;
        dist[i] = G.matrix[from][i];
        flag[i] = 0;
    }
    flag[from] = 1;
    for(int i = 1; i < G.vertexNum; i++){
        //cout<<"loop "<<i<<"------------"<<endl;
        minDist = INF;
        for(int j = 0; j < G.vertexNum; j++){
            if(!flag[j] && dist[j] < minDist){
                minDist = dist[j];
                minPos = j;
            }
        }
        //cout<<"minpos "<<minPos<<endl;
        flag[minPos] = 1;
        for(int j = 0; j < G.vertexNum; j++){
            int tmpDist = G.matrix[minPos][j] == INF ? INF : G.matrix[minPos][j] + minDist;
            if(!flag[j] && tmpDist < dist[j]){
                dist[j] = tmpDist;
                prev[j] = minPos;
            }
        }
        /*
        for(int i = 0; i < G.vertexNum; i++){
            cout<<prev[i]<<' ';
        }
        cout<<endl;
        for(int i = 0; i < G.vertexNum; i++){
            cout<<dist[i]<<' ';
        }
        cout<<endl;
        */
    }  
}
void path(int vsize, int prev[], int to){
    int pos = to;
    int p[MAX_SIZE];
    int i = 0;
    while(pos > 0){
        p[i] = pos;
        pos = prev[pos];
        i++;
    }
    p[i] = 0;
    while(i>=0){
        cout<<p[i]<<endl;
        i--;
    }
}
int main(){
    Graph g;
    int n;
    int val;
    cin>>n;
    g.vertexNum = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>val;
            g.matrix[i][j] = val;
        }
    }
    int from, to;
    cin>>from>>to;
    int prev[MAX_SIZE], dist[MAX_SIZE];
    dijkstra(g, from, prev, dist);
    /*
        for(int i = 0; i < n; i++){
            cout<<prev[i]<<' ';
        }
        cout<<endl;
        */
        for(int i = 0; i < n; i++){
            cout<<dist[i]<<endl;
        }
    //path(n, prev, to);
}
/*
4
0 2 10 10000
2 0 7 3
10 7 0 6
10000 3 6 0
0 2
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
0 3
*/