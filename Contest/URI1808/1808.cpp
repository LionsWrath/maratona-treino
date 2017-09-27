#include <bits/stdc++.h>

using namespace std;

int main() {
    string linha;
    int soma=0, qtd=0,i=0;
    
    cin >> linha;
    
    while(linha[i] != '\0'){
        qtd++;
        if(linha[i] == '1'){
            i++;
            if(linha[i] == '0'){
                soma += 10;
                i++;
            }else{
                soma += 1;
            }
        } else {
            soma += linha[i] - '0';
            i++;
        }
    }


    cout << setprecision(2) << fixed << float(soma)/float(qtd) << endl;

    return 0;
}
