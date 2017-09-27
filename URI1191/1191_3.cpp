#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef struct Node {
    char letter;
    struct Node *l, *r;
    Node(char s):letter(s), l(NULL), r(NULL) {}
} Node;

string prefix;
int pos;

void postfixTransversal(Node * actual) {
    if (actual == NULL) return;
    
    postfixTransversal(actual->l);
    postfixTransversal(actual->r);

    cout << actual->letter;
}

Node* buildTree(string infix) {
    Node *actual = new Node(prefix[pos++]);
    string l(""), r("");
    
    int j = infix.find(actual->letter);
   
    if (j != string::npos) {
        l = infix.substr(0, j); 
        r = infix.substr(min(j+1, int(infix.size())));
    }

    if (l.size()) actual->l = buildTree(l);
    if (r.size()) actual->r = buildTree(r);
    
    return actual;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string line, infix;

    while(getline(cin, line)) {    
        stringstream ss(line);
        ss >> prefix >> infix;

        Node *root = buildTree(infix); 
        postfixTransversal(root);

        cout << endl;

        infix.clear(); prefix.clear();
        pos = 0;
    }

    return 0;
}
