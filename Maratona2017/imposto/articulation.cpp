#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define WHITE 0
#define MAXV 15

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef map<int, int> mii;

vii adjList[MAXV];

vector<string> v_names;

mii dfs_num;
mii dfs_low;
mii dfs_parent;

int dfsNumberCounter;
int dfsRoot;
int rootChildren;

bool articulation_vertex[MAXV];

void articulation(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;

    for(vii::iterator it = adjList[u].begin(); it != adjList[u].end(); it++) {
        if (dfs_num[it->first] == WHITE) { //Nó de árvore
            dfs_parent[it->first] = u;
            
            if (u == dfsRoot) //Caso especial
                rootChildren++;
            
            articulation(it->first);

            if (dfs_low[it->first] >= dfs_num[u]) //Para Ponto de Articulação
                articulation_vertex[u] = true;

            if (dfs_low[it->first] > dfs_num[u]) //Para pontes
                cout << "Bridge: (" << u << "," << it->first << ") " << endl;

            dfs_low[u] = min(dfs_low[u], dfs_low[it->first]);
        
        } else if (it->first != dfs_parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[it->first]);
        }
            
    }
}

int main() {
    int V, C, X, Y, Z;
    vector<int> imposto; 

    cin >> V >> C;

    for (int i=0; i<V; i++) { cin >> X; imposto.push_back(X); }
    
    for (int i=0; i<V-1; i++) {
        cin >> X >> Y >> Z;

        adjList[X].push_back(make_pair(Y, Z));
        adjList[Y].push_back(make_pair(X, Z));
    }

    for (int i=0; i<V; i++) {
        if (dfs_num[i] == WHITE) {
            dfsRoot = i;
            rootChildren = 0;
            articulation(i);
            articulation_vertex[dfsRoot] = (rootChildren > 1); //Caso especial Vértice inicial é articulação
        }
    }

    cout << "Articulation Points: " << endl;
    for (int i=0; i<V-1; i++) {
        if (articulation_vertex[i]) 
            cout << "Vertex: " << i << endl;
    }

    return 0;
}
