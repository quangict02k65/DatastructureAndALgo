#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];
int limits[100];
int finish, start, limit;
int trace[1001];

void inp(){
    cin >> n >> m >> limit >> start >> finish;
    for(int i = 0; i < m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

//predecessor : parent node of current node.
//queue: first in first out.
void bfs(int u, int target){
    int predecessor[100], distance[100];

    for(int i = 1; i <= n; i++){
        if(i != u){
            predecessor[i] = NULL;
            distance[i] = 1000000;
        }
    }
    distance[u] = 0;
    predecessor[u] = NULL;
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        cout<<v<<" ";
        for(int x : adj[v]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
                predecessor[x] = v;
                distance[x] = distance[v] + 1;
            }
        }
    }
    printf("THe shortest path from %d to %d is : %d", u, target, distance[target]);
}

void dfs(int u){
    cout<<u<<" ";
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}


void dfs_version2(int u){
    int color[100];
    //color:
    //white: 0
    //grey : 1
    //black: 2
    int time = 0;
    for(int i = 1; i <= n; i ++){
        color[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            dfs_visit(i);
        }
    }
}

void dfs_visit(int u){
    color[u] = 1;
    time = time + 1; 
    distance[u] = time ;
    for(int v : adj[u]){
        if(color[v] == 0){
            dfs_visit(v);
        }
        color[u] = 2;
        time = time + 1;
        f[u] = time;
    }
}

//d: time node u is first visited

//f: time when the exploration the node u is completed.

/*
Thuật toán tím kiếm theo giói hạn chiêu sâu là thuật toán tương tự như
thuật toán dfs, chúng ta giới hạn chiếu sâu tìm kiếm cho chúng
Đối với thuạt toán tìm kiếm sâu dần, ta thử từng trường hợp với l = 1, 2, ..
tới khi nào tìm được điểm đích thì thuật toán dừng lại.
do đó ids(sâu dần) đảm bảo sẽ luôn tìm được nghiêm
còn dls không đảm bảo sẽ tìm được nghiệm của bài toán.
*/
void dls(int u){
    visited[u] = true;
    if(u == finish){
        cout<<"The solution is found!!!!!"<<endl;
        return;
    }
        //neu thuat toan duyet den limit thi quay lui lai de tiep tuc duyet
    if(limits[u] == limit){
        return;
    }

    //duyet qua cac dinh ke cua u 
    for(int v : adj[u]){
        if(!visited[v] ){
            limits[v] = limits[u] + 1;
            visited[v] = true;
            // trace[v] = u;
            dls(v);
        }
    }
}

int main(){
    inp();
    // int limit = 5;
    // cout<<"After search by dfs: ";
    // dfs(1);
    // limits[start] = 0;
    // dls(start);
    printf("After searching by bfs is : ");
    bfs(1, 4);

    // if(trace[finish] == 0)
    //     cout<<"khong tim thay duong di "<<endl;
    // else{
    //      while(finish != start){
    //         cout<<finish<<" ";
    //         finish = trace[finish];
    //      }
    //      cout<<start;
    // }
}