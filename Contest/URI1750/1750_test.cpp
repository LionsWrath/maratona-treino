#include <bits/stdc++.h>

using namespace std;

int N;
int zonas[1010];
int ans = 0;

int main(){
    cin >> N;
    
    for (int i = 0; i < N; i++)
        cin >> zonas[i];

    sort(zonas, zonas + N);

    int value = 0;
    for (int i = 0; i < N/2; i++)
        value += min(zonas[2*i+1] - zonas[2*i], 24 - zonas[2*i+1] + zonas[2*i]);
    ans = value;

//    value = min(zonas[N-1] - zonas[0], 24 - zonas[N-1] + zonas[0]);
//    for (int i = 1; i < N/2; i++)
//        value += min(zonas[2*i] - zonas[2*i-1], 24 - zonas[2*i] + zonas[2*i-1]);
//    ans = min(value, ans);

    cout << ans << endl;
}
