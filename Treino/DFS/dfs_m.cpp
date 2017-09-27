#include <iostream>
#include <vector>

using namespace std;

#define MAXSIZE 30

#define UNVISITED 1     //WHITE
#define VISITED   2     //GRAY
#define FINISHED  3     //BLACK

typedef vector<int> vi;

int adjMatrix[MAXSIZE][MAXSIZE];

vi nodeState;
vi nodeParents;

vi discoveryTime;
vi endTime;

int actualTime = 0, V;

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

    for (int j = 0; j < V; j++) {
        if (adjMatrix[u][j]) {
            if ( nodeState[j] == UNVISITED ) { 
                cout << "Aresta de árvore: " << u << " -> " << j << endl;
                nodeParents[j] = u;
                dfs(j);
            }

            if ( nodeState[j] == VISITED ) { 
                if (j != nodeParents[u]) 
                    cout << "Aresta de Retorno: " << u << " -> " << j << endl;
                else 
                    cout << "Aresta pai bidirecional " << u << " -> " << j << endl;
            }

            if ( nodeState[j] == FINISHED  ) cout << "Aresta de Cruzamento " << u << " -> " << j << endl;
        }
    }

    nodeState[u] = FINISHED;
    endTime[u] = ++actualTime;
}

int main() {
    int E, X, Y;
    int IN;

    cin >> V >> E;

    nodeState.assign(V, UNVISITED);
    nodeParents.assign(V, -1);
    discoveryTime.assign(V, 0);
    endTime.assign(V, 0);

    for (int i=0; i<E; i++) {
        cin >> X >> Y;
        adjMatrix[X][Y] = 1;
    }

    cin >> IN;

    dfs(IN);

    print(V);
}


