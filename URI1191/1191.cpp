#include <bits/stdc++.h>

#define TREESIZE 5000

using namespace std;

vector<string> tree;
string prefix, postfix;

int p;

void postfixTransversal(int actual) {
    if (!tree[ 2*actual ].empty())
        postfixTransversal(2*actual);
    if (!tree[2*actual+1].empty())
        postfixTransversal(2*actual + 1);

    postfix += tree[actual];
}

void buildTree(string infix, int treeIndex) {
    char root = prefix[p++];
    string l, r;
    
    for (int j=0; j<infix.size(); j++) 
        if (infix[j] == root) {
            l = infix.substr(0, j);
            r = infix.substr(j+1, infix.size());
        }

    tree[treeIndex] = root;

    if (l.size() > 0) buildTree(l, 2*treeIndex  );
    if (r.size() > 0) buildTree(r, 2*treeIndex+1);

}

int main() {
    string line, infix;

    while(getline(cin, line)) {
        tree.assign(TREESIZE, "");
        
        stringstream ss(line);

        ss >> prefix >> infix;

        buildTree(infix, 1);
        postfixTransversal(1);

        cout << postfix << endl;

        postfix.clear();
        prefix.clear();
        p = 0;
    }

    return 0;
}
