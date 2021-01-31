#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
bool visited[100000] = {false};
vector<int> arr[100000];

int find(int node, int days){
    if(visited[node]){return 0;}
    visited[node] = true;
    int n = 0;
    for(vector<int>::iterator i = arr[node].begin(); i < arr[node].end(); i++){
        if(!visited[*i]){n++;}
    }
    int x;
    for(x = 1; x <= n; x*= 2, days++);
    for(vector<int>::iterator it = arr[node].begin(); it < arr[node].end(); it++){
        if(!visited[*it]){days++;}
        days += find(*it, 0);
    }
    return days;
}

int main(void) {
    int n;
    cin >> n;
    
    int a, b, m = 0, s;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b; a--; b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
        if(arr[a].size() < arr[b].size()){
            if(arr[b].size() > m){
                m = arr[b].size();
                s = b;
            }
        }
        else{
            if(arr[a].size() > m){
                m = arr[a].size();
                s = a;
            }
        }
    }
    
    int ans = find(s, 0);
    
    cout << ans << endl;
}
