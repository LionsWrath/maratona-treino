#include <bits/stdc++.h>

using namespace std;

int main() {
    int plug[5], value;
    bool isCompatible = true;

    for (int i=0; i<5; i++) {
        cin >> value;
        plug[i] = value;
    }

    for (int i=0; i<5; i++) {
        cin >> value;

        if (value == plug[i]) isCompatible = false;
    }

    if (isCompatible) cout << "Y" << endl;
    else cout << "N" << endl;

    return 0;
}
