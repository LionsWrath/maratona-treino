#include <iostream>
#include <vector>
#include <queue>

#define INF 999999999

using namespace std;

typedef vector<int> vi;

vector<vi> adjList;
vector<vi> nodeDistance;

vi translateY;

void bfs(int u) {
    queue<int> q;

    q.push(u);
    nodeDistance[u][u] = 0;

    while (!q.empty()) {
        int z = q.front();
        q.pop();

        for (int i = 0; i < adjList[z].size(); i++) {
            int v = adjList[z][i];
            if (nodeDistance[u][v] == INF) {
                nodeDistance[u][v] = nodeDistance[u][z] + 1;
                q.push(v);
            }
        }
    }
}

void printAdjList(int V) {
    for (int i=0; i<V; i++) {
        cout << i << "  :  ";
        for (int j=0; j<adjList[i].size(); j++)  {
            cout << adjList[i][j] << " " << " -> ";
        }
        cout << " FIM" << endl;
    }
    cout << "-------" << endl;
}

int main() {
    int N, V;
    int NORTH, SOUTH, EAST, WEST; //NORTE, SUL, LESTE, OESTE
    int P;
    int x0, y0, x1, y1;

    cin >> N;
    while (N) {
        V = N*N;

        adjList.assign(V, vector<int>());

        nodeDistance.assign(V, vector<int>());
        for (int i=0; i<V; i++)
            nodeDistance[i].assign(V, INF);

        for (int i=N-1; i>=0; i--) {
            translateY.push_back(i);
        }

        for (int i=0; i<N; i++) {
            for (int j=N-1; j>=0; j--) {
                cin >> NORTH >> SOUTH >> WEST >> EAST;

                int index = N*i + translateY[j];

                //cout << index << endl;

                if (NORTH)  adjList[index].push_back(index - N);
                if (SOUTH)  adjList[index].push_back(index + N);
                if (WEST)   adjList[index].push_back(index - 1);
                if (EAST)   adjList[index].push_back(index + 1);

            }
        }

        //printAdjList(V);

        for (int i=0; i<V; i++) {
                bfs(i); 
        }

        cin >> P;
        
        for (int i=0; i<P; i++) {
            cin >> x0 >> y0 >> x1 >> y1;

            int x = x0 + N*translateY[y0];
            int y = x1 + N*translateY[y1];
           
            //cout << x << " " << y << endl;

            int distance = nodeDistance[x][y];
            if (distance != INF)
                cout << distance << endl;
            else cout << "Impossible" << endl;
        }

        cout << endl;

        translateY.clear();
        cin >> N;
    }
   
    return 0;
}
