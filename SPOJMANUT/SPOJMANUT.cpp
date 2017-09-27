#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

#define MAXV 500

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef map<int, int> mii;

vii adjList[MAXV];

mii dfs_num;
mii dfs_low;
mii dfs_parent;

int dfsNumberCounter;
int dfsRoot;
int rootChildren;

bool articulation_vertex[MAXV];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int N, M, X, Y;

    cin >> N >> M;

    for (int i=0; i<E; i++) {
        cin >> X >> Y;

        adjList[X-1].push_back(make_pair(Y-1,0));
        adjList[Y-1].push_back(make_pair(X-1,0));
    }

    return 0;
}
