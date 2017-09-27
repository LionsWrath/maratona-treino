#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define WHITE 0
#define BLACK 2

#define MAXV  21

typedef vector<int> vi;

vi adjList[MAXV];
vi dfs_num;

void dfs(int u, int deep) {
    bool printEnd = false;
    deep++;
    dfs_num[u] = BLACK;
    for (int j = 0; j < adjList[u].size(); j++) {
        printEnd = true;
        int v = adjList[u][j];
        if (dfs_num[v] == WHITE) {
            for (int i=0; i<deep; i++) cout << "  ";
            cout << u << "-" << v << " pathR(G," << v << ")" << endl;
            dfs(v, deep);
        } else {
            for (int i=0; i<deep; i++) cout << "  ";
            cout << u << "-" << v << endl;
        }
    }

    if (printEnd && 1 == deep) cout << endl;
}
int main() {
    int N, V, E;
    int X, Y;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> V >> E;
       
        dfs_num.assign(V, WHITE);
        for (int j = 0; j < E; j++) {
            cin >> X >> Y;
            
            if (find(adjList[X].begin(), adjList[X].end(), Y) == adjList[X].end())
                adjList[X].push_back(Y);
        }

        for (int j = 0; j<MAXV; j++) sort(adjList[j].begin(), adjList[j].end());
  
        cout << "Caso " << i+1 << ":" << endl;

        for (int j = 0; j < V; j++) 
            if (dfs_num[j] == WHITE) 
                dfs(j, 0);
        
        dfs_num.clear();
        for (int i=0; i<MAXV; i++) adjList[i].clear();
    }
    
    return 0;
}
