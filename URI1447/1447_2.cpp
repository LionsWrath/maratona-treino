#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <limits>
#include <string.h>
#include <iomanip>

using namespace std;

#define INF 999999
#define MAXV 101

typedef pair<int, int>  ii;
typedef vector<ii>      vii;
typedef vector<int>     vi;

int adjMatrix[MAXV][MAXV];
int res[MAXV][MAXV];

int mf, f, s, t; //max_flow, actual flow, initial, final

vi p;
vi dist;

int N, MF;
int totalPrice;

void printMatrix() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << setw(3) << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void augment(int v, int minEdge) {
    if (v == s) {
        f = min(minEdge, MF);
        return;
    } else if (p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));

        cout << p[v] << "->" << v << endl;

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
                int v = adjMatrix[u][j];

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

        //for (int value : p) cout << value << " ";
        //cout << endl;

        //for (int value : dist) cout << value << " ";
        //cout << endl << endl;

        printMatrix();

        augment(t, INF);

        //cout << f << " " << f*dist[t] << endl;
        
        if (f == 0 || mf + f > MF ) break;

        cout << f << " " << dist[t] << endl;

        totalPrice += f * dist[t];
        mf += f;
    }
}

int main () {
    int M;
    int X, Y, Z, F;
    int I=0;

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
            res[Y-1][Y-1] = 1;
        }

        //printMatrix();

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
        memset(adjMatrix, 0, MAXV*MAXV*sizeof(int));
        memset(res, 0, MAXV*MAXV*sizeof(int));
    }
}
