#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

#define UNVISITED 0
#define VISITED 2

typedef vector<int> vi;

vector<vi> adjList;
vi nodeColors;

map<string, int> charToInt = { {"a", 0}, {"b", 1}, {"c", 2}, {"d", 3}, {"e", 4}, {"f", 5}, {"g", 6}, 
                               {"h", 7}, {"i", 8}, {"j", 9}, {"k",10}, {"l",11}, {"m",12}, {"n",13}, 
                               {"o",14}, {"p",15}, {"q",16}, {"r",17}, {"s",18}, {"t",19}, {"u",20},
                               {"v",21}, {"w",22}, {"x",23}, {"y",24}, {"z",25}};

string intToChar = "abcdefghijklmnopqrstuvwxyz";

vector<int> componentMembers;

void dfs(int u) {
    nodeColors[u] = VISITED;
    componentMembers.push_back(u);
    for (int j = 0; j < adjList[u].size(); j++) {
        int v = adjList[u][j];
        if (nodeColors[v] == UNVISITED) {
            dfs(v);
        }
    }
}

int main() {
    int N, V, E;
    string X, Y;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> V >> E;
      
        adjList.assign(V, vector<int>());
        nodeColors.assign(V, UNVISITED);
        
        for (int j = 0; j < E; j++) {
            cin >> X >> Y;
           
            if (find(adjList[charToInt[X]].begin(), 
                        adjList[charToInt[X]].end(), 
                        charToInt[Y]) == adjList[charToInt[X]].end()) {
                adjList[charToInt[X]].push_back(charToInt[Y]);
                adjList[charToInt[Y]].push_back(charToInt[X]);
            }
        }

        for (int j = 0; j<V; j++) 
            sort(adjList[j].begin(), adjList[j].end());

        cout << "Case #" << i+1 << ":" << endl;

        int numberOfComponents = 0;
        for (int j = 0; j < V; j++) 
            if (nodeColors[j] == UNVISITED) {
                numberOfComponents++;
                dfs(j);

                sort(componentMembers.begin(), componentMembers.end());

                for (int i=0; i<componentMembers.size(); i++) 
                    cout << intToChar[componentMembers[i]] << ",";
                cout << endl;

                componentMembers.clear();
            }
        cout << numberOfComponents << " connected components" << endl << endl;

    }
    
    return 0;
}
