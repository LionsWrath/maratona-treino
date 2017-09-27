#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

#define MAXV 500
#define INF -1
#define INFI 99999

typedef pair<int, int> ii;
typedef vector<int> vi;

int adjMatrix[MAXV][MAXV];
vi dist;

int N;

void print() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printDist() {
    for (int i=0; i<N; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

void dijkstra(int s) {
    dist[s] = 0;
    priority_queue< ii, vector<ii>, greater<ii> > pq;
   
    pq.push(ii(0, s));
    
    while(!pq.empty()) {
        ii front = pq.top();
        pq.pop();

        int d = front.first;
        int u = front.second;

        if (d > dist[u]) continue;

        for (int i=0; i<N; i++) {
            int weight = adjMatrix[u][i];
            
            if (weight != INF) {
                if (dist[u] + weight < dist[i]) {
                    dist[i] = dist[u] + weight;

                    pq.push(ii(dist[i], i)); 
                }
            }
        }
    }
}

int main() {
    int E;
    int X, Y, Z;

    int O, D;

    int numberOfCases;

    cin >> N >> E;
    while (N != 0 && E != 0) {
        memset(adjMatrix, INF, MAXV*MAXV*sizeof(int));


        for (int i=0; i<E; i++) {
            cin >> X >> Y >> Z;

            if (adjMatrix[Y-1][X-1] != INF) { 
                adjMatrix[X-1][Y-1] = 0;
                adjMatrix[Y-1][X-1] = 0;
            } else { 
                adjMatrix[X-1][Y-1] = Z;
            }
        }
        
        cin >> numberOfCases;

        for (int i=0; i<numberOfCases; i++) {
            cin >> O >> D;
            
            dist.assign(N, INFI);

            dijkstra(O-1);
         
            int distance = dist[D-1];
            if (distance != INFI) cout << distance << endl;
            else cout << "Nao e possivel entregar a carta" << endl;
        }

        cout << endl;

        cin >> N >> E;
    }

    return 0;
}
