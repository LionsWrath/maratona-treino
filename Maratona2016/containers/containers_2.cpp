#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

#define INF 9999999

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<string, int> si;

unordered_map<string, int> dist;
unordered_map<string, vector< si > > adjList;

vector< pair<int, int> > d1 = { {0,0}, {0,0}, {1,0}, {0,1}, {0,1}, {1,1}, {0,2}, {1,2}, {0,2}, {0,3} };
vector< pair<int, int> > d2 = { {0,1}, {1,0}, {1,1}, {1,1}, {0,2}, {1,2}, {1,2}, {1,3}, {0,3}, {1,3} };

class Comparator {
    public:
        bool operator() (const si& lhs, const si& rhs) const {
            return (lhs.second > rhs.second);
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

string getID(vvi container) {
    string id = "";
    
    for (int i=0; i<2; i++) {
        for (int j=0; j<4; j++) {
           id += toString(container[i][j]); 
        }
    }

    return id;
}

vvi getMatrix(string id) {
    vvi matrix;

    matrix.assign(2, vi());
    
    int begin = 0;
    for (int i=0; i<2; i++) {
        for (int j=0; j<4; j++) {
           matrix[i].push_back(stol(id.substr(begin, 4)));
           begin += 4;
        }    
    }

    return matrix;
}

void printMatrix(vvi matrix) {
    for (int i=0; i<2; i++) {
        for (int j=0; j<4; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

string createMove(vvi matrix, int x1, int y1, int x2, int y2) {
    vvi newMatrix(matrix);

    newMatrix[x1][y1] = matrix[x2][y2];
    newMatrix[x2][y2] = matrix[x1][y1];

    return getID(newMatrix);
}

void createGraph(vvi matrix) {
    string created, actual;
    stack<string> stk;

    stk.push(getID(matrix));
    while (!stk.empty()) {
        actual = stk.top();
        stk.pop();
        
        if (adjList.find(actual) == adjList.end()) {
            adjList[actual] = vector<si>();
            dist[actual] = INF;

            matrix = getMatrix(actual);

            for (int i=0; i<10; i++) {
                created = createMove(matrix, d1[i].first, d1[i].second, d2[i].first, d2[i].second);
                
                adjList[actual].push_back(si(created, matrix[d1[i].first][d1[i].second] + matrix[d2[i].first][d2[i].second])); 

                stk.push(created);
            }
        } 
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

    vvi begin, end;
    begin.assign(2, vi());
    end.assign(2, vi());
    for (int i=0; i<2; i++) {
        begin[i].assign(4, 0);
        end[i].assign(4, 0);
    }

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
    
    createGraph(begin);

    dijkstra(getID(begin));
   
    cout << dist[getID(end)] << endl;

    return 0;
}
