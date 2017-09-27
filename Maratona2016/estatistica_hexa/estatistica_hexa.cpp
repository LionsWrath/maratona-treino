#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

#define INF 99999999999999

typedef vector<bool> bits;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<bits, int> bi;
typedef unsigned long long int ll;

vc p = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

unordered_map< bits, vector<bi> > adjList;
unordered_map< bits, vs > allWords;

unordered_map< bits, ll> dist;
unordered_map< bits, bool> visited;

vs numbers;
vector<bits> tsort;

void printBitmask(bits bitmask) {
    for (int i=0; i<bitmask.size(); i++) {
        cout << bitmask[i] << " ";
    }
    cout << endl;
}

void setWords(vs old, bits next, int pos) {
    if (allWords.find(next) != allWords.end()) return;
   
    for (int i=0; i<old.size(); i++) {
        for (int j=0; j<old[i].size(); j++) {
            if (old[i][j] == p[pos]) {
                old[i].erase(j,1);           
            }
        }
    }

    allWords[next] = old;
}

ll sum(bits bitmask) {
    vs words = allWords[bitmask];
    ll values = 0;

    for (int i=0; i<words.size(); i++) {
        values = stoll("0x" + words[i], nullptr, 0);
    }

    return values;
}

void topological_sort(bits node) {
    if (visited.find(node) == visited.end()) {
        for (int i=0; i<adjList[node].size(); i++) {
            topological_sort(adjList[node][i].first);
        }
        visited[node] = true;
        tsort.push_back(node);
    }
}

void shortest_path(bits initial) {
    dist[initial] = 0;

    for (int i=tsort.size()-1; i>=0; i--) {
        bits u = tsort[i]; 
        for (int i=0; i<adjList[u].size(); i++) {
            bi v = adjList[u][i];
            
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second; 
            }
        }
    }
}

//Nao verificar quando palavra vazia
//Adicionar somente quando muda
void createGraph(bits bitmask) {
    bits next;
    stack<bits> stk;

    stk.push(bitmask);
    allWords[bitmask] = numbers;

    while (!stk.empty()) {
        bitmask = stk.top(); stk.pop();

        if (adjList.find(bitmask) == adjList.end()) {
            for (int i=0; i<p.size(); i++) {
                if (bitmask[i]) {
                    next = bitmask; next[i] = 0;

                    setWords(allWords[bitmask], next, i);
                    adjList[bitmask].push_back(bi(next, sum(next))); 
                    dist[bitmask] = INF;
                   
                    stk.push(next);
                }
            }
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(false);cin.tie(NULL);
    bits bitmask(p.size(), 1);
    string aux;
    int N;

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> aux; 
        numbers.push_back(aux);
    }

    createGraph(bitmask);
    topological_sort(bitmask);
    shortest_path(bitmask);

    ll best = 0, worst = INF;
    for (int i=0; i<p.size(); i++) {
        bits verifier(p.size(), 0);
        verifier[i] = 1;

        if (dist.find(verifier) != dist.end()) {
            cout << p[i] << ": " << hex << dist[verifier] << endl;
            if (dist[verifier] > best) best = dist[verifier];
            else if (dist[verifier] < worst) worst = dist[verifier];
        }
    }

    cout << hex << best << " " << worst << " " << best + worst << endl;

    return 0;
}
