#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <limits>

using namespace std;

vector<int> costs;

//maximum subarray string
int kadane() {
    int max_ending_here = 0;
    int max_so_far = 0;

    for (int i=0; i<costs.size(); i++) {
        max_ending_here = max(0, max_ending_here + costs[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int main() {
    int N, C;
    int R;

    string line;
    while (getline(cin, line)) {
        N = atoi(line.c_str());
        cin >> C;

        costs.clear();
        costs.assign(N, 0);

        for (int i=0; i<N; i++) {
           cin >> R;

           costs[i] = R - C;
        }

        cout << kadane() << endl;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    return 0;
}
