#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>

#define INF 999999999
#define MAXV 4000

using namespace std;

typedef pair<int, string> is;
typedef pair<int, int> ii;

typedef vector<is> vis;
typedef vector<int> vi;

typedef map<string, int> msi;

vector<vis> adjList;
msi languageList;
map<int, char> letterList; 

vi dist;

string initiaLetters = "abcdefghijklmnopqrstuvwxyz";

void printDist() {
    for (int i=0; i<languageList.size(); i++)
        cout << "V: " << i << " - " << dist[i] << endl;
}

void printAdjList(int V) {
    for (int i=0; i<V; i++) {
        cout << i << "  :  ";
        for (int j=0; j<adjList[i].size(); j++)  {
            cout << adjList[i][j].first << ":" << adjList[i][j].second << " -> ";
        }
        cout << " FIM" << endl;
    }
    cout << "-------" << endl;
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

        for (int i=0; i<adjList[u].size(); i++) {
            is v = adjList[u][i];

            if (dist[u] + v.second.size() < dist[v.first]) {
                dist[v.first] = dist[u] + v.second.size();

                pq.push(ii(dist[v.first], v.first));
            }
        }
    }
}

int main() {
    string origin, destiny;
    string X, Y, W;
    int M, V=0;

    cin >> M;
    while (M) {
        cin >> origin >> destiny;

        languageList[origin + 'a'] = V;
        letterList[V] = 'X';
        V++;

        languageList[destiny + 'a'] = V;
        letterList[V] = 'X';
        V++;

        adjList.assign(MAXV, vector<is>());
        dist.assign(MAXV, INF);

        for (int i=0; i<M; i++) {
            cin >> X >> Y >> W;

            if (!languageList.count(X + 'a')) {
                for (int j=0; j<initiaLetters.size(); j++) {
                    languageList[X + initiaLetters[j]] = V;
                    letterList[V] = initiaLetters[j];
                    V++;
                }
            }

            if (!languageList.count(Y + 'a')) {
                for (int j=0; j<initiaLetters.size(); j++) {
                    languageList[Y + initiaLetters[j]] = V;
                    letterList[V] = initiaLetters[j];
                    V++;
                }
            }

            if (origin.compare(X) != 0 && destiny.compare(X) != 0) {
                if (origin.compare(Y) != 0 && destiny.compare(Y) != 0) {
                    for (int j=0; j< initiaLetters.size(); j++) {
                        char letter = initiaLetters[j];
                        
                        if (W[0] != letter) {
                            adjList[languageList[X + letter]].push_back(is(languageList[Y + W[0]], W));
                        }
                        
                        if (W[0] != letterList[languageList[Y + letter]]) {
                            adjList[languageList[Y + W[0]]].push_back(is(languageList[X + letter], W));
                        }
                    }
                } else {
                    if (origin.compare(Y) == 0) {
                        adjList[languageList[Y + 'a']].push_back(is(languageList[X + W[0]], W));
                    }

                    if (destiny.compare(Y) == 0) {
                         for (int j=0; j<initiaLetters.size(); j++) {
                            char letter = initiaLetters[j];

                            if (W[0] != letter) {
                                adjList[languageList[X + letter]].push_back(is(languageList[Y + 'a'], W));
                            }
                         }
                    } 
                }
            } else {
                if (origin.compare(Y) != 0 && destiny.compare(Y) != 0) {
                    if (origin.compare(X) == 0) {
                        adjList[languageList[X + 'a']].push_back(is(languageList[Y + W[0]], W));
                    }
                    
                    if (destiny.compare(X) == 0) {
                        for (int j=0; j<initiaLetters.size(); j++) {
                            char letter = initiaLetters[j];

                            if (W[0] != letter) {
                                adjList[languageList[Y + letter]].push_back(is(languageList[X + 'a'], W));
                            }
                        }
                    }
                } else {
                    adjList[languageList[X + 'a']].push_back(is(languageList[Y + 'a'], W));
                    adjList[languageList[Y + 'a']].push_back(is(languageList[X + 'a'], W));
                }
            }
        }

        //printAdjList(V);

        adjList.resize(V);
        dist.resize(V);

        dijkstra(languageList[origin + 'a']);

        //printDist();

        int finalDist = dist[languageList[destiny + 'a']];
        if (finalDist == INF) 
            cout << "impossivel" << endl;
        else cout << finalDist << endl;

        letterList.clear();
        languageList.clear();
        V = 0;

        cin >> M;
    }
    
    return 0;
}
