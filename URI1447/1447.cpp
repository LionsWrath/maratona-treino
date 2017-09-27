#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <limits>

using namespace std;

#define INF 999999
#define MAXV 101

typedef pair<int, int>  ii;
typedef vector<ii>      vii;
typedef vector<int>     vi;

vector<vii> adjList;

int res[MAXV][MAXV];
int mf, f, s, t; //max_flow, actual flow, initial, final

vi p;
vi dist;

int N, MF;
int totalPrice;

void augment(int v, int minEdge) {
    if (v == s) {
        f = min(minEdge, MF);
        return;
    } else if (p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));

            cout << p[v] << "->" << v << endl;

        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

void bellman_ford() {
    p.assign(N, -1);
    dist.assign(N, INF);

    dist[s] = 0;
    for (int i=0; i<N-1; i++) {
        for (int u=0; u<N; u++) {
            for(int j=0; j<adjList[u].size(); j++) {
                ii v = adjList[u][j];

                if (dist[u] + v.second < dist[v.first] && res[u][v.first] != 0) { 
                    dist[v.first] = dist[u] + v.second;
                    p[v.first] = u;
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

        augment(t, INF);

        //cout << f << " " << f*dist[t] << endl;
        
        if (f == 0 || mf + f > MF ) break;

        //cout << f << " " << f*dist[t] << endl;

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

        adjList.assign(N, vector<ii>());

        for (int i=0; i<M; i++) {
            cin >> X >> Y >> Z;

            adjList[X-1].push_back(ii(Y-1,Z));
            adjList[Y-1].push_back(ii(X-1,Z));
            
            res[X-1][Y-1] = 1;
            res[Y-1][Y-1] = 1;
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
    }
}
