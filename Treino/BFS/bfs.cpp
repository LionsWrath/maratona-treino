#include <iostream>
#include <vector>
#include <queue>

#define INFINITY 999999

using namespace std;

typedef vector<int> vi;

vector<vi> adjList;

vi nodeDistance;
vi nodeParents;

void print(int V, int first) {
    for (int i = 0; i < V; i++) {
        cout << "V: " << i << " P: ";
        if (nodeParents[i] >= 0 && nodeParents[i] != i) cout << nodeParents[i];
        else cout << "NIL ";

        cout << " D("<< first << "): ";

        if (nodeParents[i] >= 0) cout << nodeDistance[i] << endl;
        else cout << "INF" << endl;
    }
}

void bfs(int u) {
    queue<int> q;

    q.push(u);
    nodeDistance[u] = 0;
    nodeParents[u] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i];
            if (nodeDistance[v] == INFINITY) {
                nodeDistance[v] = nodeDistance[u] + 1;
                nodeParents[v] = u;
                q.push(v);
            }
        }
    }
}

int main() {
    int V, E, X, Y;
    int IN;

    cin >> V >> E;

    adjList.assign(V, vector<int>());
    nodeDistance.assign(V, INFINITY);
    nodeParents.assign(V, -1);

    for (int i=0; i<E; i++) {
        cin >> X >> Y;
        adjList[X].push_back(Y);
    }

    cin >> IN;

    bfs(IN);

    print(V, IN);
}


