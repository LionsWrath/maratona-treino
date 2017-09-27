#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 999999
#define MAXV 15

typedef pair<int, int>  ii;
typedef vector<ii>      vii;
typedef vector<int>     vi;

vector<vii> adjList;

int res[MAXV][MAXV];
int mf, f, s, t; //max_flow, actual flow, initial, final

vi p;
vi dist;

int V;

void augment(int v, int minEdge) {
    if (v == s) {
        f = minEdge;
        return;
    } else if (p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

void bellman_ford() {
    p.assign(V, -1);
    dist.assign(V, INF);

    dist[s] = 0;
    for (int i=0; i<V-1; i++) {
        for (int u=0; u<V; u++) {
            for(int j=0; j<adjList[u].size(); j++) {
                ii v = adjList[u][j];

                if (dist[u] + v.second < dist[v.first] && res[u][v.first] > 0) { 
                    dist[v.first] = dist[u] + v.second;
                    p[v.first] = u;
                } 
            }
        }
    }
}

void edmond_karp() {
    mf = 0;
    while (1) {
        f = 0;
        
        bellman_ford();

        for (int value : p) cout << value << " ";
        cout << endl;

        augment(t, INF);

        if (f == 0) break;

        mf += f;
    }
}

int main () {
    int E;
    int X, Y, Z, F;

    cin >> V >> E;

    adjList.assign(V, vector<ii>());

    for (int i=0; i<E; i++) {
        cin >> X >> Y >> Z >> F;

        adjList[X].push_back(ii(Y,Z));
        adjList[Y].push_back(ii(X,Z));
        
        res[X][Y] = F;
        //res[Y][X] = F;
    }

    cin >> s >> t;

    edmond_karp();
    
    cout << mf << endl;
}
