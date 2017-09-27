#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef struct Node {
    string letter;
    struct Node *l, *r;
    Node(): l(NULL), r(NULL) {}
} Node;

string prefix;
int pos;

void postfixTransversal(Node * actual) {
    if (actual == NULL) return;
    
    postfixTransversal(actual->l);
    postfixTransversal(actual->r);

    cout << actual->letter;
}

void buildTree(string infix, Node * actual) {
    actual->letter = prefix[pos++];
    string l(""), r("");
    
    int j = infix.find(actual->letter);
    
    l = infix.substr(0, j); 
    
    if (j+1 < infix.size()) 
        r = infix.substr(j + 1);

    if (l.size() > 0) {
        actual->l = new Node;
        buildTree(l, actual->l);
    }

    if (r.size() > 0) {
        actual->r = new Node;
        buildTree(r, actual->r);
    }

}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string line, infix;

    while(getline(cin, line)) {    
        stringstream ss(line);

        ss >> prefix >> infix;

        Node root;

        buildTree(infix, &root);
        
        postfixTransversal(&root);

        cout << endl;

        infix.clear();
        prefix.clear();
        pos = 0;
    }

    return 0;
}
