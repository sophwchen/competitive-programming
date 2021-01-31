//
//  main.cpp
//  jan3
//
//

#include <iostream>
#include <set>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int x;
    int h1[1000] = {0}, h2[1000] = {0}, v1[1000] = {0}, v2[1000] = {0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> x;
            if(i%2 == 1) {h1[j] += x;}
            else{h2[j] += x;}
            if(j%2 == 1){v1[i] += x;}
            else{v2[i] += x;}
        }
    }
    
    int a1 = 0, a2 = 0;
    for(int i = 0; i < n; i++){
        a1 += max(h1[i], h2[i]);
        a2 += max(v1[i], v2[i]);
    }
    
    cout << max(a1, a2) << endl;
}
