#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

int main() {
    int N;
    int M, Q;
    string P;
    double W;

    double p_total = 0.0f;

    map<string, double> feira;

    cin >> N;

    for (int i=0; i<N; i++) {
        cin >> M;

        for (int j=0; j<M; j++) {
            cin >> P >> W;

            feira[P] = W;
        }

        cin >> M;

        for(int j=0; j<M; j++) {
            cin >> P >> Q;

            p_total += feira[P] * Q;
        }

        cout << "R$ " << fixed << setprecision(2) << p_total << endl;

        p_total = 0.0f;
        feira.clear();
    }

    return 0;
}
