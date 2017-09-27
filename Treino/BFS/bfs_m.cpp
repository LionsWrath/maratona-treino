#include <iostream>
#include <vector>
#include <queue>

#define INFINITY 999999
#define MAXSIZE 30

using namespace std;

typedef vector<int> vi;

int adjMatrix[MAXSIZE][MAXSIZE];

vi nodeDistance;
vi nodeParents;

int V;

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

        for (int i = 0; i < V; i++) {
            if (adjMatrix[u][i]) {
                if (nodeDistance[i] == INFINITY) {
                    nodeDistance[i] = nodeDistance[u] + 1;
                    nodeParents[i] = u;
                    q.push(i);
                }
            }
        }
    }
}

int main() {
    int E, X, Y;
    int IN;

    cin >> V >> E;

    nodeDistance.assign(V, INFINITY);
    nodeParents.assign(V, -1);

    for (int i=0; i<E; i++) {
        cin >> X >> Y;
        adjMatrix[X][Y] = 1;
    }

    cin >> IN;

    bfs(IN);

    print(V, IN);
}


