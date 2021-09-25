#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 100
#define INF 10000
using namespace std;
struct Edge{
    int to;
    int dis;
    Edge* next;
    Edge(int to, int dis){
        this->to = to;
        this->dis = dis;
    }
};
struct Vertex{
    Edge *edges;
    Edge *curEdge;
    Vertex(){
        this->edges = NULL;
        this->curEdge = NULL;
    }
    void insert(int to, int dis){
        if(!this->edges){
            edges = new Edge(to, dis);
            curEdge = edges;
        } else{
            curEdge->next = new Edge(to, dis);
            curEdge = curEdge->next;
        }
    }
};
struct Graph{
    int vertexNum;
    int edgeNum;
    Vertex vertexs[MAX_SIZE];
    Graph(int v, int e){
        this->vertexNum = v;
        this->edgeNum = e;
        for(int i = 0; i < v; i++){
            vertexs[i] = Vertex();
        }
    }
    void constructGraph(){
        int from, to, dis;
        for(int i = 0; i < this->edgeNum; i++){
            cin>>from>>to>>dis;
            vertexs[from].insert(to, dis);
        }
    }
};
void dijkstra(Graph G, int from, int prev[], int dist[]){
    int minDist;
    int minPos;
    int flag[MAX_SIZE];
    //init
    for(int i = 1; i <= G.vertexNum; i++){
        prev[i] = 0;
        flag[i] = 0;
        dist[i] = INF;
    }
    flag[from] = 1;
    dist[from] = 0;
    Edge* fromEdges = G.vertexs[from].edges;
    while(fromEdges){
        dist[fromEdges->to] = fromEdges->dis;
        fromEdges = fromEdges->next;
    }

    for(int i = 2; i <= G.vertexNum; i++){
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
        Edge* fromMinPos = G.vertexs[minPos].edges;
        while(fromMinPos){
            int tmpDist = fromMinPos->dis + minDist;
            if(!flag[fromMinPos->to] && tmpDist < dist[fromMinPos->to]){
                dist[fromMinPos->to] = tmpDist;
                prev[fromMinPos->to] = minPos;
            }
            fromMinPos = fromMinPos->next;
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
void distance(int dis[], int size){
    vector<pair<int, int> > vec;    
    for(int i = 1; i <= size; i++){
        vec.push_back(make_pair(dis[i], i));
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < size; i++){
        int dist = vec[i].first;
        if(dist == 0){
            continue;
        } else if(dist == INF){
            dist = -1;
        }
        cout<<1<<' '<<vec[i].second<<' '<<dist<<endl;
    }
}
int main(){
    int vertexNum, edgeNum;
    cin>>vertexNum>>edgeNum;
    Graph g(vertexNum, edgeNum);
    g.constructGraph();
    int prev[MAX_SIZE], dist[MAX_SIZE];
    dijkstra(g, 1, prev, dist);
    /*
        for(int i = 0; i < n; i++){
            cout<<prev[i]<<' ';
        }
        cout<<endl;
        */
       /*
        for(int i = 1; i <= vertexNum; i++){
            cout<<dist[i]<<endl;
        }
        */
    distance(dist, vertexNum);
    //path(n, prev, to);
}
/*
6 11
1 2 50
1 3 10
1 5 45
2 3 15
2 5 10
3 1 20
3 4 15
4 2 20
4 5 35
5 4 30
6 4 3
*/