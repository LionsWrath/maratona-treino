#include <bits/stdc++.h>

using namespace std;

int getDecimal(string str) {
    string aux;
    if (str.size() >= 2) {
        aux = str.substr(str.size() - 2, str.size()); 
    } else {
        aux = str.substr(0,1); 
    }
    return stoi(aux);
}

int getGroup(int value) {
    if (value == 0) return 25;

    return ceil(float(value)/4.0f);
}

int main() {
    double V;
    string N, M;

    cin >> V >> N >> M;

    while(V != 0 || N[0] != '0' || M[0] != '0') {
        int max_equal = 0;

        int N_size = N.size();
        int M_size = M.size();

        int pos = 1;
        while (pos < max(max(N_size, M_size), 5)) {
            int N_pos = N_size - pos;
            int M_pos = M_size - pos;

//            cout << N_pos << " " << M_pos << " - ";

            if (N_pos >= 0 && M_pos >= 0) {
//                cout << N[N_pos] << "==" << M[M_pos] << endl;
                if (N[N_pos] == M[M_pos]) max_equal++;
                else break;
            } else if (N_pos < 0 && M_pos >= 0) {
//                cout << 0 << "==" << M[M_pos] << endl;
                if ('0' == M[M_pos]) max_equal++;
                else break;
            } else if (N_pos >= 0 && M_pos < 0) { 
//                cout << N[N_pos] << "==" << 0 << endl;
                if (N[N_pos] == '0') max_equal++;
                else break;
            } else {
                max_equal++;
            }

            pos++;
        }

//        cout << max_equal << endl;

        cout.precision(2);
        if (max_equal >= 4) cout << fixed << V*float(3000) << endl;
        else if (max_equal == 3) cout << fixed << V*float(500) << endl;
        else if (max_equal == 2) cout << fixed << V*float(50) << endl;
        else {
           if (getGroup(getDecimal(N)) == getGroup(getDecimal(M))) {
                cout << fixed << V*float(16) << endl;
           } else {
                cout << fixed << 0.00 << endl;
           }
        }

        cin >> V >> N >> M;
    }

    return 0;
}
