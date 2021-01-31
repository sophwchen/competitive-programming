#include <iostream>
#include <algorithm>
using namespace std;

struct position{
    int x;
    int y;
    int endpoint = -1;
};

struct cows{
    char c;
    int x; int y;
    int endpoint = -1;
};

bool compareE(position p, position q){
    return (p.y < q.y);
}

bool compareN(position p, position q){
    return (p.x < q.x);
}

int main(void) {
    int n;
    cin >> n;
    position east[n];
    position north[n];
    cows arr[n];
    
    int E = 0, N = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i].c;
        if(arr[i].c == 'E'){
            cin >> east[E].x >> east[E].y;
            arr[i].x = east[E].x;
            arr[i].y = east[E].y;
            E++;
        }
        else{
            cin >> north[N].x >> north[N].y;
            arr[i].x = north[N].x;
            arr[i].y = north[N].y;
            N++;
        }
    }
    sort(east, east+E, compareE);
    sort(north, north+N, compareN);
    
    for(int i = 0; i < E; i++){
        for(int z = i-1; z >=0; z--){
            if(east[i].y == east[z].y){
                east[i].endpoint = east[z].x - east[i].x;
            }
        }
        for(int j = 0; j < N && east[i].endpoint == -1; j++){
            if(north[j].x <= east[i].x || north[j].y >= east[i].y || north[j].endpoint != -1){continue;}
            if(east[i].y - north[j].y > north[j].x - east[i].x){
                north[j].endpoint = east[i].y - north[j].y;
            }
            if(east[i].y - north[j].y < north[j].x - east[i].x){
                east[i].endpoint = north[j].x - east[i].x;
            }
            for(int z = j-1; z >= 0; z--){
                if(north[j].x == north[z].x){
                    if(north[j].endpoint > north[z].x - north[j].x){
                        north[j].endpoint = north[z].x - north[j].x;
                    }
                }
            }
        }
    }
    int j;
    for(int i = 0; i < n; i++){
        if(arr[i].c == 'E'){
            for(j = 0; j < E; j++){
                if(arr[i].x == east[j].x && arr[i].y == east[j].y){
                    break;
                }
            }
            if(east[j].endpoint == -1){
                cout << "Infinity" << endl;
            }
            else{
                cout << east[j].endpoint << endl;
            }
        }
        else{
            for(j = 0; j < N; j++){
                if(arr[i].x == north[j].x && arr[i].y == north[j].y){
                    break;
                }
            }
            if(north[j].endpoint == -1){
                cout << "Infinity" << endl;
            }
            else{
                cout << north[j].endpoint << endl;
            }
        }
    }
