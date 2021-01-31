#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<int> arr[1000];
bool visited[1000] = {false};

struct cows{
    char c;
    int x;
    int y;
    int endp = -1;
};
struct pos{
    int x;
    int y;
    int endp = -1;
    int orig;
};

int find(int node, int r){
    if(visited[node]){return 0;}
    visited[node] = true;
    for(vector<int>::iterator it = arr[node].begin(); it < arr[node].end(); it++){
        r++;
        r = max(r, find(*it, r));
    }
    return r;
}

bool compareN(pos p, pos q){
    return (p.x < q.x);
}

bool compareE(pos p, pos q){
    return (p.y < q.y);
}

int main(void) {
    int n;
    cin >> n;
    pos east[n];
    pos north[n];
    cows arra[n];
    
    int E = 0, N = 0;
    for(int i = 0; i < n; i++){
        cin >> arra[i].c;
        if(arra[i].c == 'E'){
            cin >> east[E].x >> east[E].y;
            arra[i].x = east[E].x;
            arra[i].y = east[E].y;
            E++;
        }
        else{
            cin >> north[N].x >> north[N].y;
            arra[i].x = north[N].x;
            arra[i].y = north[N].y;
            N++;
        }
    }
    sort(east, east+E, compareE);
    sort(north, north+N, compareN);
    int k;
    for(int i = 0; i < E; i++){
        for(k = 0; k < n; k++){
            if(arra[k].x == east[i].x && arra[k].y == east[i].y){
                east[i].orig = k;
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(k = 0; k < n; k++){
            if(arra[k].x == north[i].x && arra[k].y == north[i].y){
                north[i].orig = k;
            }
        }
    }
    
    for(int i = 0; i < E; i++){
        for(int z = i-1; z >=0; z--){
            if(east[i].y == east[z].y){
                east[i].endp = east[z].x - east[i].x;
            }
        }
        for(int j = 0; j < N && east[i].endp == -1; j++){
            if(north[j].x <= east[i].x || north[j].y >= east[i].y || north[j].endp != -1){continue;}
            if(east[i].y - north[j].y > north[j].x - east[i].x){
                north[j].endp = east[i].y - north[j].y;
                arr[east[i].orig].push_back(north[j].orig);
            }
            if(east[i].y - north[j].y < north[j].x - east[i].x){
                east[i].endp = north[j].x - east[i].x;
                arr[north[j].orig].push_back(east[i].orig);
            }
            for(int z = j-1; z >= 0; z--){
                if(north[j].x == north[z].x){
                    if(north[j].endp > north[z].x - north[j].x){
                        north[j].endp = north[z].x - north[j].x;
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        cout << find(i, 0) << endl;
        memset(visited, false, n);
    }
}
