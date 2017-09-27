#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 9000

typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

vector<vii> adjList;
vi nodeDistance;

int C;

struct CompareFirst{
    CompareFirst(int val) : val_(val) {}
    bool operator()(const std::pair<int, int>& elem) const {
        return val_ == elem.first;
    }
    
    private:
        int val_;
};

bool isOnRoute(int V) { 
    if (V < C-1) return true;
    return false;
}

void dijkstra(int s) {
    nodeDistance[s] = 0;
    priority_queue< ii, vector<ii>, greater<ii> > pq;
   
    pq.push(ii(0, s));
    
    while(!pq.empty()) {
        ii front = pq.top();
        pq.pop();

        int d = front.first;
        int u = front.second;

        if (d > nodeDistance[u]) continue;

        if (isOnRoute(u)) {
            auto value = find_if(adjList[u].begin(), adjList[u].end(), CompareFirst(u+1));
            ii v = *value;

            //cout << "V: " << u << " N: " << v.first << " W: " << v.second << endl;

            if (nodeDistance[u] + v.second < nodeDistance[v.first]) {
                nodeDistance[v.first] = nodeDistance[u] + v.second;

                pq.push(ii(nodeDistance[v.first], v.first));
            }
        } else {
            for (int i=0; i<adjList[u].size(); i++) {
                ii v = adjList[u][i];

                //cout << "V: " << u << " N: " << v.first << " W: " << v.second << endl;

                if (nodeDistance[u] + v.second < nodeDistance[v.first]) {
                    nodeDistance[v.first] = nodeDistance[u] + v.second;

                    pq.push(ii(nodeDistance[v.first], v.first));
                }
            }
        }
    }
}

int main() {
    int N, M, K;
    int U, V, P;

    cin >> N >> M >> C >> K;
    while (N != 0 && M != 0 && C != 0 && K != 0) {
        adjList.assign(N, vii());
        nodeDistance.assign(N, INF);

        for (int i=0; i<M; i++) {
            cin >> U >> V >> P;

            adjList[U].push_back(make_pair(V, P));
            adjList[V].push_back(make_pair(U, P));
        }

        dijkstra(K);

        cout << nodeDistance[C-1] << endl;
        
        cin >> N >> M >> C >> K;
    }
    return 0;
}
