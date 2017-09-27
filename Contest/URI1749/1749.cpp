#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> planes;
int N, minimum;

bool isSamePlane(int x1, int y1, int x2, int y2) {
    double distance = sqrt( pow(x2 - x1, 2) + pow(y2 - y1, 2) );

    if (distance > 5.0f) return true;
    else return false;
}

bool isValid(int next, vector<int> set) {
    for (int value : set) {
        if (!planes[next][value]) {
            return false;
        }
    }
    return true;
}

int search(int actual, vector<bool> used, vector<int> andromeda, vector<int> lactea, bool choosen) {
    bool isLast = true;

    if (choosen) andromeda.push_back(actual);
    else lactea.push_back(actual);

    used[actual] = true;
    for (int i=0; i<N; i++) {
        if (!used[i]) {
            if (isValid(i, andromeda)) {
                isLast = false;
                
                search(i, used, andromeda, lactea, true);
            }
            if (isValid(i, lactea)) {
                isLast = false;
                
                search(i, used, andromeda, lactea, false);
            }
        }
    }

    if (isLast) {
        minimum = min(int(andromeda.size()), minimum);
        minimum = min(int(lactea.size()), minimum);
    }
}

int main() {
    cin >> N;
   
    minimum = N;

    planes.assign(N, vector<bool>());
    for (int i = 0; i<N; i++)
        planes[i].assign(N, false);

    vector<int> X, Y;

    int x, y;
    for (int i=0; i<N; i++) {
        cin >> x >> y;

        X.push_back(x);
        Y.push_back(y);
    }

    for (int i=0; i<N-1; i++) {
        for (int j=i+1; j<N; j++) {
            bool value = isSamePlane(X[i], Y[i], X[j], Y[j]);

            planes[i][j] = value;
            planes[j][i] = value;
        }
    }

    vector<bool> used;
    used.assign(N, false);

    vector<int> andromeda, lactea;

    search(0, used, andromeda, lactea, true);

    cout << minimum << endl;

    return 0;
}
