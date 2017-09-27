#include <bits/stdc++.h>
#define endl '\n'

#define VERIFIED -1
#define INF 9999999

using namespace std;

typedef pair<int, int> ii;

int matrix[201][201];
int H, L, MIN = INF;

int dx[] = {1, 0, -1,  0};
int dy[] = {0, 1,  0, -1};

stack< ii, std::vector<ii> > news;
stack< int, std::vector<int> > color_news;

int flood_fill(int x, int y, int color) {
    if (x < 0 || x >= H || y < 0 || y >= L) return 0;
    if (matrix[x][y] != color) {
        news.push(ii(x,y));
        color_news.push(matrix[x][y]);
        return 0;
    }
   
    matrix[x][y] = VERIFIED;

    int ans = 1;
    for (int i=0; i<4; i++) 
        ans += flood_fill(x + dx[i], y + dy[i], color);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    cin >> H >> L;

    for (int i=0; i<H; i++) {
        for (int j=0; j<L; j++) {
            cin >> matrix[i][j];
        }
    }

    news.push(ii(0,0));
    color_news.push(matrix[0][0]);

    while (!news.empty()) {
        ii p = news.top();
        int color = color_news.top();
        
        color_news.pop(); news.pop();

        if (matrix[p.first][p.second] != -1) {
            int size = flood_fill(p.first, p.second, color);
            if (0 != size) MIN = min(MIN, size);
        }
    }

    cout << MIN << endl;

    return 0;
}
