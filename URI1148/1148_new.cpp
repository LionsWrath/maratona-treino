#include <iostream>
#include <vector>

using namespace std;

#define INF 1500

typedef vector<int> vi;

vector<vi> adjMatrix;
vector<vi> nodeParent;

//void printAdjacency(int N) {
//    for (int i=0; i<N; i++) {
//        for (int j=0; j<N; j++) {
//            cout << adjMatrix[i][j] << " ";
//        }
//        cout << endl;
//    }
//}

void floyd_warshall(int N) {
    for (int k=0; k<N; k++) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (adjMatrix[i][j] > adjMatrix[i][k] + adjMatrix[k][j]) {
                    adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
                    nodeParent[i][j] = nodeParent[k][j];
                }
            }
        }
    }
}

void setMatrix(int N) {
    adjMatrix.clear();
    nodeParent.clear();

    adjMatrix.assign(N, vector<int>());
    nodeParent.assign(N, vector<int>());
    for (int i=0; i<N; i++) {
        adjMatrix[i].assign(N, INF); 
        nodeParent[i].assign(N, -1);
    }

    for (int i=0, j=0; i<N && j<N; j++, i++) {
        adjMatrix[i][j] = 0;
    }
}

int main() {
    int N, E;
    int X, Y, H;
    int K, O, D;

    cin >> N >> E;

    while (N != 0 || E != 0) {
        setMatrix(N);

        for (int i=0; i<E; i++) {
            cin >> X >> Y >> H;

            adjMatrix[X-1][Y-1] = H;
            if (adjMatrix[Y-1][X-1] != INF) {
                adjMatrix[X-1][Y-1] = 0;
                adjMatrix[Y-1][X-1] = 0;
            }
        }

        floyd_warshall(N);

        cin >> K;

        for (int i=0; i<K; i++) {
            cin >> O >> D;

            int distance = adjMatrix[O-1][D-1];
            
            if (distance == INF)
                cout << "Nao e possivel entregar a carta" << endl;
            else cout << distance << endl;
        }


        cin >> N >> E;

        cout << endl;
    }
}

