#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    int N;
    int C;
    vector<int> codes;

    while(cin >> N){
        for (int i=0; i<N; i++) {
            cin >> C;

            codes.push_back(C);
        }

        sort(codes.begin(), codes.end());

        for (int c : codes) 
            cout << setfill('0') << setw(4) << c << endl;

        codes.clear();
    }
    
    return 0;
}
