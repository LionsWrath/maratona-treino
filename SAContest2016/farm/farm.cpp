#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int turn(int actual, int last, int command) {
    if (command == 1) {
        if (actual == last) return 1;
        else return ++actual;
    }

    if (command == -1) {
        if (actual == 1) return last;
        else return --actual;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N, C, S, V;
    vector<int> commands;

    cin >> N >> C >> S;

    for (int i=0; i<C; i++) {
        cin >> V;
        commands.push_back(V);
    }

    V = 0;
    int actual = 1;
    for (int i=0; i<commands.size(); i++) {
        if (actual == S) V++;
        actual = turn(actual, N, commands[i]); 
    }
    if (actual == S) V++;
   
    cout << V << endl;

    return 0;
}
