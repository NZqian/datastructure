#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;

struct adjVertex{
    int vertexPos;
    adjVertex *next;
    adjVertex(int pos){
        this->vertexPos = pos;
        this->next = NULL;
    }
};
struct Vertex{
    int val;
    adjVertex *adj;
    adjVertex *curAdj;
    bool visited;
    Vertex(int val){
        this->val = val;
        this->visited = false;
        adj = NULL;
        curAdj = adj;
    }
    void insert(int pos){
        if(!adj){
            adj = new adjVertex(pos);
            curAdj = adj;
        } else{
            curAdj->next = new adjVertex(pos);;
            curAdj = curAdj->next;
        }
    }
};
struct Graph{
    vector<Vertex*> v;
    map<int, int> m;
    int vsize, esize;
    Graph(int vsize, int esize){
        this->vsize = vsize;
        this->esize = esize;
        for(int i = 0; i < vsize; i++){
            int vval;
            cin>>vval;
            Vertex* tmpv = new Vertex(vval);
            v.push_back(tmpv);
            m[vval] = i;
        }
        for(int i = 0; i < esize; i++){
            int v1, v2;
            cin>>v1>>v2;
            v[m[v1]]->insert(v2);
            v[m[v2]]->insert(v1);
        }
    }
    bool connected(int v1, int v2){
        queue<Vertex*> q;
        q.push(v[m[v1]]);
        return bfs(q, v2);;;
    }
    bool bfs(queue<Vertex*> q, int target){
        Vertex* cur = q.front();
        q.pop();
        while(cur->visited){
            cur = q.front();
            q.pop();
        }
        if(cur->visited){
            return false;
        }
        //cout<<cur->val<<' ';
        cur->visited = true;
        if(cur->val == target){
            return true;
        } else{
            adjVertex* adj = cur->adj;
            while(adj){
                //cout<<m[adj->vertexPos]<<endl;
                q.push(v[m[adj->vertexPos]]);
                adj = adj->next;
            }
        }
        return bfs(q, target);
    }
    
    void show(){
        for(int i = 0; i < vsize; i++){
            Vertex* cur = v[i];
            cout<<cur->val<<' ';
            adjVertex* adj = cur->adj;
            while(adj){
                cout<<m[adj->vertexPos]<<' ';
                adj = adj->next;
            }
            cout<<endl;
        }
    }
};
int main(){
    int v, e;
    cin>>v>>e;
    Graph g(v, e);
    int v1, v2;
    cin>>v1>>v2;
    //g.show();
    if(g.connected(v1, v2)){
        cout<<"yes"<<endl;
    } else{
        cout<<"no"<<endl;
    }
    //cout<<g.connected(1, 2)<<endl;
    //cout<<g.connected(1, 3)<<endl;
    //cout<<g.connected(1, 4)<<endl;
    //cout<<g.connected(2, 3)<<endl;
    //cout<<g.connected(2, 4)<<endl;
    //cout<<g.connected(3, 4)<<endl;
}
/*
4 4
1 2 3 4
1 2
1 3
1 4
2 3
2 3
*/