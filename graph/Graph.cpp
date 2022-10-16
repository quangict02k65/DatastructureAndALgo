#include<bits/stdc++.h>
using namespace std;

bool *visited;
class Graph{
    int V;
    list<int> *adj;

    public: 
        int numVertex();
        Graph(int V);
        void addEdge(int v, int w);
        void BFS(int s);
};

Graph::Graph(int v){
    this->V = V;
    adj = new list<int>[V];
}

int Graph::numVertex(){
    return V;
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::BFS(int s){
    queue<int> q;
    visited[s] = true;
    q.push(s);

    list<int>::iterator i;
    while(!q.empty()){
        s = q.front();
        cout << s << " ";
        q.pop();

        //traversal list adjacency of s 
        for(i = adj[s].begin(); i !=  adj[s].end(); i++){
            int v = *i;
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main(){
    Graph g(5);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,0);
    g.addEdge(4,0);
    g.addEdge(0,2);

    int numV = g.numVertex();
    visited = new bool[numV];
    for(int i = 0; i < numV; i ++){
        visited[i] = false;
    }

    cout<< "BFS(1): ";
    g.BFS(1);

    return 0;




}