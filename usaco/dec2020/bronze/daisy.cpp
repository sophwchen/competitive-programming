#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans = n;
    float avg;
    for(int i = 2; i <= n; i++){
        for(int start = 0; start <= n-i; start++){
            avg = 0;
            for(int j = 0; j < i; j++){
                avg += float(arr[j+start]);
            }
            avg /= float(i);
            if(avg - int(avg) == 0){
                for(int j = 0; j < i; j++){
                    if(avg == arr[j+start]){
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
