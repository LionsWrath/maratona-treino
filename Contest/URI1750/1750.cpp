#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
   
using namespace std;

int zonas[1005], casado[1005];
int diff_min, min_val, min_id;  
int n;

int tempo(int i, int j){
   return (abs(i-j) < (24-abs(i-j))) ? abs(i-j) : (24-abs(i-j));
}

int main() {
    cin >> n;
    
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux; 
            
        zonas[i] = aux;
        casado[i] = 0;
    }

    sort(zonas, zonas + n);
    
    for(int i=0;i<n;i++){
        if(!casado[i]){
            int j;
            
            for(j=i+1;(j<n)&&(casado[j]);j++){}

            min_val = tempo(zonas[i],zonas[j]); 
            min_id  = j;     
            
            for(int z=i+1;(z<n)&&(!casado[z]);z++){
                if(tempo(zonas[i],zonas[z]) < min_val){
                    min_val = tempo(zonas[i],zonas[z]); 
                    min_id  = z;     
                }
            }
            
            diff_min += min_val;
            
            casado[min_id] = 1;
            casado[i] = 1;
        }
    }
    
    cout << diff_min << "\n";
    
    return 0;
}
