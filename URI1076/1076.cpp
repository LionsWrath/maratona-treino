#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define WHITE 0
#define GRAY  1
#define BLACK 2

#define MAXV  49

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef map<int, int> mii;

vii adjList[MAXV];
mii dfs_num;

int dfs(int u) {
    int cont = 0;
    dfs_num[u] = GRAY;
    for (int j = 0; j < adjList[u].size(); j++) {
        ii v = adjList[u][j];
        if (dfs_num[v.first] == WHITE)
            cont += dfs(v.first);
    }

    return cont + 2;
}

int initialNode(int u) {
    int cont = 0;
    dfs_num[u] = GRAY;
    for (int j = 0; j < adjList[u].size(); j++) {
        ii v = adjList[u][j];
        if (dfs_num[v.first] == WHITE)
            cont += dfs(v.first);
    }

    return cont;
}   

int main() {
    int T, N, V, A, root;
    int X, Y;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> root;
        cin >> V >> A;
       
        for (int j = 0; j < A; j++) {
            cin >> X >> Y;
            adjList[X].push_back(make_pair(Y,0));
            adjList[Y].push_back(make_pair(X,0));
        }
    
        cout << initialNode(root) << endl;
        
        dfs_num.clear();
        for (int i=0; i<MAXV; i++) adjList[i].clear();
    }
    
    return 0;
}
