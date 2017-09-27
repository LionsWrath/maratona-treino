#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define UNVISITED 0

typedef vector<int> vi;

vector<vi> adjList;

vi dfs_num;
vi dfs_low;
vi S;
vi visited;

int dfsNumberCounter;
int numSCC;

void scc (int u) {
    dfs_low[u] = dfsNumberCounter;
    dfs_num[u] = dfsNumberCounter++;
    
    S.push_back(u);
    visited[u] = 1;

    for (int i=0; i< adjList[u].size(); i++) {
        int v = adjList[u][i];
        
        if (dfs_num[v] == UNVISITED)
            scc(v);

        if (visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_low[u] == dfs_num[u]) {
        numSCC++;
        while (1) {
            int v = S.back();
            S.pop_back();
            visited[v] = 0;
            if (u == v) break;
        }
    }
}

int main() {
    int N, M;
    int V, W, P;
    
    cin >> N >> M;
    while (N != 0 && M != 0) {
        adjList.assign(N, vector<int>());
        dfs_num.assign(N, UNVISITED);
        dfs_low.assign(N, 0);
        visited.assign(N, 0);

        dfsNumberCounter = 0;
        numSCC = 0;

        for (int i=0; i<M; i++) {
            cin >> V >> W >> P;

            if (P == 1) {
                adjList[V-1].push_back(W-1);
            } else {
                adjList[V-1].push_back(W-1);
                adjList[W-1].push_back(V-1);
            }
        }

        for (int i=0; i<N; i++)
            if (dfs_num[i] == UNVISITED)
                scc(i);
        //cout << numSCC << endl;

        if (numSCC == 1) 
            cout << 1 << endl;
        else
            cout << 0 << endl;

        cin >> N >> M;
    }

    return 0;
}
