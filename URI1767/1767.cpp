#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>

using namespace std;

vector<int> quantidade;
vector<int> peso;
vector<bool> sacksUsed;

int matrix[101][54];

int P;

void printMatrix(int P) {
    cout << endl;
    for (int i=0; i<P; i++) {
        for (int j=0; j<=50; j++) {
            cout << setw(2) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int booleanKnapsack() {
    int beforeValue, afterValue;

    for (int i=0; i<=50; i++) {
        for (int j=1; j<P+1; j++) {
            beforeValue = matrix[j-1][i];
            
            if (peso[j] > i) afterValue = 0;   
            else afterValue = matrix[j-1][i-peso[j]] + quantidade[j];
            
            matrix[j][i] = max(beforeValue, afterValue);
        }
    }
  
    int weight = 50;
    for (int i=P; i>0; i--) {

        if (matrix[i][weight] == matrix[i-1][weight]) {
            sacksUsed[i] = false;            
        } else {
            sacksUsed[i] = true;
            weight -= peso[i];
        }
    }

    return weight;
}

int main() {
    int N;
    int Q, W;

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> P;

        quantidade.assign(P+1, 0);
        peso.assign(P+1, 0);
        sacksUsed.assign(P+1, false);

        for (int j=1; j<=P; j++) {
            cin >> Q >> W;

            quantidade[j] = Q;
            peso[j] = W;
        }

        int totalWeight = 50 - booleanKnapsack();

        int totalToys = 0;
        int totalLeft = 0;
        for (int j=1; j<=P; j++) {
            if (sacksUsed[j]) totalToys += quantidade[j]; 
            else totalLeft++;
        }

        cout << totalToys << " brinquedos" << endl;
        cout << "Peso: " << totalWeight << " kg" << endl;
        cout << "sobra(m) " << totalLeft << " pacote(s)" << endl;
        cout << endl;

        memset(matrix, 0, 101*51*sizeof(int));
    }
    return 0;
}
