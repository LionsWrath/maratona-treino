#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

#define INF 99999

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

vvii adjList;

vi dist;
vi parent;

void dijkstra(int s) {
    dist[s] = 0;
    priority_queue< ii, vector<ii>, greater<ii> > pq; 
    pq.push(ii(0,s));

    while(!pq.empty()) {
        ii top = pq.top();
        pq.pop();

        int d = top.first;
        int u = top.second;

        if (d == dist[u]) {
            for(int i=0; i<adjList[u].size(); i++) {
                ii v = adjList[u][i];

                if (dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second;
                    parent[v.first] = u;
                    pq.push(ii(dist[v.first], v.first));
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int V, E, X, Y, Z;
    int IN;

    cin >> V >> E;

    dist.assign(V, INF);
    parent.assign(V, -1);
    adjList.assign(V, vii()); 

    for (int i=0; i<E; i++) {
        cin >> X >> Y >> Z;

        adjList[X].push_back(ii(Y,Z));
    }

    cin >> IN;

    dijkstra(IN);

    return 0;
}
