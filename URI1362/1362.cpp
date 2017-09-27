#include <bits/stdc++.h>

#define MAXV 60
#define INF 9999999

using namespace std;

typedef vector<int> vi;

int adjMat[MAXV][MAXV];

vi p;

int maxFlow = 0;
int f, s = 6, t = 7;

void augmentPath(int v, int minEdge) {
    if (v == s) {
        f = minEdge;
        return;
    } else if (p[v] != -1) { 
        augmentPath(p[v], min(minEdge, adjMat[p[v]][v]));
        adjMat[p[v]][v] -= f; 
        adjMat[v][p[v]] += f;
    }
}

void edmond_karp() {
    maxFlow = 0;
    while (1) {
        f = 0;

        queue<int> q; q.push(s);
        vi dist(MAXV, INF); dist[s] = 0;
        p.assign(MAXV, -1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == t) break;

            for(int v = 0; v < MAXV; v++) {
                if (adjMat[u][v] > 0 && dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    p[v] = u;
                }
            }
        }

        augmentPath(t, INF);
        if (f == 0) break;
        maxFlow += f;
    }
}

int main() {
    int N, M, Q;
    string X, Y;

    cin >> Q;

    for (int k=0; k<Q; k++) {
        
        memset(adjMat, 0, sizeof(adjMat));
        
        cin >> N >> M;

        for (int i=0; i<M; i++) {
            cin >> X >> Y;

            if (X.compare("XXL") == 0) {
                adjMat[i+8][0] = 1;        
            }

            if (X.compare("XL") == 0) {
                adjMat[i+8][1] = 1; 
            }

            if (X.compare("L") == 0) {
                adjMat[i+8][2] = 1; 
            }

            if (X.compare("M") == 0) {
                adjMat[i+8][3] = 1;
            }

            if (X.compare("S") == 0) {
                adjMat[i+8][4] = 1;
            }

            if (X.compare("XS") == 0) {
                adjMat[i+8][5] = 1; 
            }

            //
            if (Y.compare("XXL") == 0) {
                adjMat[i+8][0] = 1;        
            }

            if (Y.compare("XL") == 0) {
                adjMat[i+8][1] = 1; 
            }

            if (Y.compare("L") == 0) {
                adjMat[i+8][2] = 1; 
            }

            if (Y.compare("M") == 0) {
                adjMat[i+8][3] = 1;
            }

            if (Y.compare("S") == 0) {
                adjMat[i+8][4] = 1;
            }

            if (Y.compare("XS") == 0) {
                adjMat[i+8][5] = 1; 
            }

            adjMat[s][i+8] = 1;

        }

        for (int i=0; i<6; i++) {
            adjMat[i][t] = N/6;       
        }

        edmond_karp();

        if (maxFlow == M) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
