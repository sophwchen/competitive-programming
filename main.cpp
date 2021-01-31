//
//  main.cpp
//  jan1
//
//  Created by Sophia Chen on 1/24/21.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(void) {
    
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = i;
    }
    int a, b, med;
    
    vector<int> arra[n];
    
    unordered_set<int> count[n];
    
    for(int i = 0; i < k; i++){
        cin >> a >> b; a--; b--;
        arra[arr[a]].push_back(b);
        count[arr[a]].insert(b);
        arra[arr[b]].push_back(a);
        count[arr[b]].insert(a);
        med = arr[a];
        arr[a] = arr[b];
        arr[b] = med;
    }
    
    int ans[n];
    for(int i = 0; i < n; i++){
        int x;
        if(arra[i].empty()){
            cout << 1 << endl;
        }
        else{
            if(arra[i].back() != i && arra[i].back() < i){
                ans[i] = ans[arra[i].back()];
                cout << ans[arra[i].back()] << endl;
            }
            else{
                for(x = i; arra[x].back() != i;){
                    x = arra[x].back();
                    if(arra[x].empty()){break;}
                    if(count[i].size() == n){break;}
                    count[i].insert(arra[x].begin(), arra[x].end());
                }
                ans[i] = count[i].size();
                cout << count[i].size() << endl;
            }
        }
    }
}

