#include <bits/stdc++.h>

using namespace std;

int main() {
    int qtd;


    int casos[10000];

    cin>>qtd;
    for(int i=0;i<qtd;i++){
        vector<int> x={0,0,0,0};
        vector<int> y={0,0,0,0};
        int rx;
        int ry;
        cin>>x[0];
        cin>>y[0];
        cin>>x[1];
        cin>>y[1];
        cin>>x[2];
        cin>>y[2];
        cin>>x[3];
        cin>>y[3];
        cin>>rx;
        cin>>ry;
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
       
        casos[i] = ( (*x.begin()<rx)&&(*x.rbegin()>rx) )&&((*y.begin()<ry)&&(*y.rbegin()>ry) );      
    }
    for(int i=0;i<qtd;i++){
        cout<<casos[i]<<endl;
    }

    return 0;
}
