#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <sstream>
#include <string.h>
#include <iomanip>

using namespace std;

#define BOARD_SIZE 8

typedef pair<int, int> ii;
typedef map<char, int> mci;

int boardMoves[BOARD_SIZE][BOARD_SIZE];

bool isSolution(int x, int y, ii destiny) {
    if (x == destiny.first && y == destiny.second) {
        return true;
    }
    return false;
}

bool isValid(int x, int y) {
    if (x < 0 || x > 7 || y < 0 || y > 7) return false;
    return true;
}

void printBoard() {
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++)
            cout << setw(2) << boardMoves[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int bfs(string origin, string destiny) {
    queue<ii> q;
    queue<int> qdist;
    int deep = 0;
    
    if (0 == origin.compare(destiny)) return deep;

    mci letterMappings = { {'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}, 
                           {'e', 4}, {'f', 5}, {'g', 6}, {'h', 7}  };

    mci numberMappings = { {'1', 7}, {'2', 6}, {'3', 5}, {'4', 4},
                           {'5', 3}, {'6', 2}, {'7', 1}, {'8', 0}  };
   
    ii o = make_pair(numberMappings[origin[1]], letterMappings[origin[0]]);
    ii d = make_pair(numberMappings[destiny[1]], letterMappings[destiny[0]]);

    int dx[] = {-2, -1, -2,  1,  2, -1,  2,  1};
    int dy[] = {-1, -2,  1, -2, -1,  2,  1,  2};

    boardMoves[o.first][o.second] = -1; 

    q.push(o);
    qdist.push(deep);
    while (!q.empty()) {
        ii u = q.front();
        deep = qdist.front();
        
        q.pop();
        qdist.pop();

        deep++;
        for (int i=0; i<8; i++) {
            int x = u.first + dx[i];
            int y = u.second + dy[i];

            if (isValid(x, y)) {
                if (!boardMoves[x][y]) {
                    boardMoves[x][y] = deep;

                    if (isSolution(x, y, d)) {
                        return deep;
                    } else { 
                        q.push(make_pair(x, y));
                        qdist.push(deep);
                    }
                }
            }
        }
    }
}

int main() {
    string origin, destiny;

    string line;
    while (getline(cin, line)) {
        istringstream iss(line);

        iss >> origin;
        iss >> destiny;

        int N = bfs(origin, destiny);
        cout << "To get from " << origin << " to " << destiny << " takes " << N << " knight moves." << endl;
        
        memset(boardMoves, 0, BOARD_SIZE*BOARD_SIZE*sizeof(int));
    }
    
    return 0;
}
