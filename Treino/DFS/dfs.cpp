#include <iostream>
#include <vector>

using namespace std;

#define UNVISITED 0     //WHITE
#define VISITED   1     //GRAY
#define FINISHED  2     //BLACK

typedef vector<int> vi;

vector<vi> adjList;

vi nodeState;
vi nodeParents;

vi discoveryTime;
vi endTime;

int actualTime = 0;

void print(int V) {
    for (int i=0; i < V; i++) {
        cout << "V: " << i << " D: " << discoveryTime[i] << " E: " << endTime[i];
        
        if (nodeParents[i] >= 0) cout << " P: " << nodeParents[i] << endl;
        else cout << " P: NIL " << endl;
    }
}

void dfs(int u) {
    nodeState[u] = VISITED;
    discoveryTime[u] = ++actualTime;

    for (int j = 0; j < adjList[u].size(); j++) {
        int v = adjList[u][j];
        if ( nodeState[v] == UNVISITED ) { 
            cout << "Aresta de árvore: " << u << " -> " << v << endl;
            nodeParents[v] = u;
            dfs(v);
        }

        if ( nodeState[v] == VISITED ) { 
            if (v != nodeParents[u]) 
                cout << "Aresta de Retorno: " << u << " -> " << v << endl;
            else 
                cout << "Aresta pai bidirecional " << u << " -> " << v << endl;
        }

        if ( nodeState[v] == FINISHED  ) cout << "Aresta de Cruzamento " << u << " -> " << v << endl;
    }

    nodeState[u] = FINISHED;
    endTime[u] = ++actualTime;
}

int main() {
    int V, E, X, Y;
    int IN;

    cin >> V >> E;

    adjList.assign(V, vector<int>());
    nodeState.assign(V, UNVISITED);
    nodeParents.assign(V, -1);
    discoveryTime.assign(V, 0);
    endTime.assign(V, 0);

    for (int i=0; i<E; i++) {
        cin >> X >> Y;
        adjList[X].push_back(Y);
    }

    cin >> IN;

    dfs(IN);

    print(V);
}


