#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

#define INF 9999999

typedef pair<string, int> si;

map<string, int> dist;
map<string, vector< si > > adjList;

class Comparator {
    bool reverse;
    public:
        bool operator() (const si& lhs, const si& rhs) const {
            return (lhs.second < rhs.second);
        }
};

string toString(int value, int digits = 4) {
    string result;
    while (digits-- > 0) {
        result += ('0' + value % 10);
        value /= 10;
    }
    
    reverse(result.begin(), result.end());
    return result;
}

string getID(int container[2][4]) {
    string id = "";
    
    for (int i=0; i<2; i++) {
        for (int j=0; j<4; j++) {
           id += toString(container[i][j]); 
        }
    }

    return id;
}

void getMatrix(string id, int matrix[][4]) {
    int begin = 0;
    for (int i=0; i<2; i++) {
        for (int j=0; j<4; j++) {
           matrix[i][j] = stol(id.substr(begin, 4));
           begin += 4;
        }
    }
}

void printMatrix(string id) {
    int matrix[2][4];

    getMatrix(id, matrix);
    for (int i=0; i<2; i++) {
        for (int j=0; j<4; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

string createMove(int matrix[2][4], int x1, int y1, int x2, int y2) {
    int newMatrix[2][4];
    memcpy(newMatrix, matrix, sizeof(newMatrix));

    newMatrix[x1][y1] = matrix[x2][y2];
    newMatrix[x2][y2] = matrix[x1][y1];

//    printMatrix(getID(newMatrix));
    cout << getID(newMatrix) << endl;

    return getID(newMatrix);
}

void populateNode(string id) {
    int matrix[2][4];
    string created;

    cout << adjList.size() << endl;

    getMatrix(id, matrix);

    vector< pair<int, int> > d1 = { {0,0}, {0,0}, {1,0}, {0,1}, {0,1}, {1,1}, {0,2}, {1,2}, {0,2}, {0,3} };
    vector< pair<int, int> > d2 = { {0,1}, {1,0}, {1,1}, {1,1}, {0,2}, {1,2}, {1,2}, {1,3}, {0,3}, {1,3} };

    for (int i=0; i<10; i++) {
        created = createMove(matrix, d1[i].first, d1[i].second, d2[i].first, d2[i].second);
        adjList[id].push_back(si(created, matrix[d1[i].first][d1[i].second] + matrix[d2[i].first][d2[i].second])); 
        if (dist.find(created) == dist.end()) dist[created] = INF;
    }
}

void dijkstra(string initial) {
    dist[initial] = 0;
    priority_queue< si, vector<si>, Comparator > pq; 
    pq.push(si(initial,0));

    while(!pq.empty()) {
        si top = pq.top();
        pq.pop();

        string d = top.first;
        int u = top.second;

        if (u == dist[d]) {
            if (adjList.find(d) == adjList.end()) populateNode(d);
            for(int i=0; i<adjList[d].size(); i++) {
                si v = adjList[d][i];

                if (dist[d] + v.second < dist[v.first]) {
                    dist[v.first] = dist[d] + v.second;
                    pq.push(si(v.first,dist[v.first]));
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int begin[2][4], end[2][4];

    for (int i=0; i<2; i++) {
        for (int j=0; j<4; j++) {
           cin >> begin[i][j];
        }
    }

    for (int i=0; i<2; i++) {
        for (int j=0; j<4; j++) {
           cin >> end[i][j];
        }
    }

    dijkstra(getID(begin));
   
    cout << dist[getID(end)] << endl;

    return 0;
}
