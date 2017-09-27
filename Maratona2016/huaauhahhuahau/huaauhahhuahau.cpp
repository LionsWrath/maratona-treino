#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

char vogals[] = {'a', 'e', 'i', 'o', 'u'};

string laugh;
string cleaned;

bool isVogal(int index) {
    for (int i=0; i<5; i++) 
       if (laugh[index] == vogals[i]) return true; 
    return false;
}

void clean() {
    cleaned = "";
    for (int i=0; i<laugh.size(); i++) {
        if (isVogal(i)) cleaned += laugh[i];
    }
}

bool analyser(int begin, int end) {
    if (begin >= end) return true;
    if (cleaned[begin] != cleaned[end]) return false;
    else return analyser(++begin, --end);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    cin >> laugh;

    clean();
    if (analyser(0, cleaned.size() - 1)) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}
