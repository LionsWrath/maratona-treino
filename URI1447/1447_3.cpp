#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <limits>
#include <string.h>
#include <iomanip>

using namespace std;

#define INF 99999999999999
#define MAXV 101

typedef pair<int64_t, int64_t>  ii;
typedef vector<ii>      vii;
typedef vector<int64_t>     vi;

int64_t adjMatrix[MAXV][MAXV];
int64_t res[MAXV][MAXV];

int64_t mf, f, s, t; 

vi p;
vi dist;

int64_t N, MF;
int64_t totalPrice;

void augment(int v, int64_t minEdge) {
    if (v == s) {
        f = min(minEdge, MF-mf);
        return;
    } else if (p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));

        res[p[v]][v] -= f;
        res[v][p[v]] += f;

        if (adjMatrix[p[v]][v] > 0) {
            adjMatrix[v][p[v]] = -adjMatrix[v][p[v]];
        } else {
            adjMatrix[p[v]][v] = -adjMatrix[p[v]][v];
        }
    }
}

void bellman_ford() {
    p.assign(N, -1);
    dist.assign(N, INF);

    dist[s] = 0;
    for (int i=0; i<N-1; i++) {
        for (int u=0; u<N; u++) {
            for(int j=0; j<N; j++) {
                int64_t v = adjMatrix[u][j];

                if ((dist[u] + v < dist[j]) && res[u][j] != 0) { 
                    dist[j] = dist[u] + v;
                    p[j] = u;
                } 
            }
        }
    }
}

void edmond_karp() {
    mf = 0;
    totalPrice = 0;
    while (1) {
        f = 0;
        
        bellman_ford();
        augment(t, INF);

        if (f == 0) break;

        totalPrice += f * dist[t];
        mf += f;
    }
}

int main () {
    int64_t M;
    int64_t X, Y, Z, F;
    int64_t I=0;

    string line;
    while (getline(cin, line)) {
        I++;
        istringstream iss(line);
        iss >> N >> M;

        for (int i=0; i<M; i++) {
            cin >> X >> Y >> Z;

            adjMatrix[X-1][Y-1] = Z;
            adjMatrix[Y-1][X-1] = Z;
            
            res[X-1][Y-1] = 1;
            res[Y-1][X-1] = 1;
        }

        cin >> MF >> F;

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (res[i][j]) res[i][j] = F;
            }
        }

        s = 0;
        t = N-1;

        edmond_karp();

        cout << "Instancia " << I << endl;
        if (mf < MF) cout << "impossivel" << endl;
        else cout << totalPrice << endl;
        cout << endl;

        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        memset(adjMatrix, 0, MAXV*MAXV*sizeof(int64_t));
        memset(res, 0, MAXV*MAXV*sizeof(int64_t));
    }
}
