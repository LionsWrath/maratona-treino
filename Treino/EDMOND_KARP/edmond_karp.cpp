#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 999999
#define MAXV 15

typedef pair<int, int>  ii;
typedef vector<ii>      vii;
typedef vector<int>     vi;

int res[MAXV][MAXV];
int mf, f, s, t; //max_flow, actual flow, initial, final

vi p;

void augment(int v, int minEdge) {
    if (v == s) {
        f = minEdge;
    } else if (p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

void edmond_karp() {
    mf = 0;
    while (1) {
        f = 0;

        vi dist(MAXV, INF);
        
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        p.assign(MAXV, -1);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == t) break;

            for (int i=0; i<MAXV; i++) {
                if (res[u][i] > 0 && dist[i] == INF) {
                    dist[i] = dist[u] + 1;
                    q.push(i);
                    p[i] = u;
                }
            }
        }

        augment(t, INF);

        if (f == 0) break;

        mf += f;
    }
}

int main () {
    int V, E;
    int X, Y, Z;

    cin >> V >> E;

    for (int i=0; i<E; i++) {
        cin >> X >> Y >> Z;

        res[X][Y] = Z;
    }

    cin >> s >> t;

    edmond_karp();

    cout << mf << endl;
}
