//
//  main.cpp
//  jan2
//
//  Created by Sophia Chen on 1/24/21.
//

#include <iostream>
#include <set>
using namespace std;

struct area{
    int start;
    int end;
};

int main(void) {
    int n, k;
    cin >> n >> k;
    
    int psum[n+1]; psum[0] = 0; //n+1
    int rpsum[n+1]; rpsum[0] = 0;
    char str[n];
    for(int i = 0; i < n; i++){
        cin >> str[i];
    }
    char prev, c;
    prev = str[0];
    set<char> low;
    low.insert(str[0]);
    psum[1] = 1;
    for(int i = 1; i < n; i++){
        c = str[i];
        if(c == prev){
            psum[i+1] = psum[i];
        }
        else{
            if(c > prev){
                psum[i+1] = psum[i] + 1;
                low.insert(c);
            }
            if(c < prev){
                if(low.find(c) != low.end()){
                    psum[i+1] = psum[i];
                }
                else{
                    psum[i+1] = psum[i]+1;
                    low.insert(c);
                }
                set<char>::iterator it = low.find(c);
                if(it != low.end()){
                    it++;
                    for(; it != low.end(); it++){
                        low.erase(*it);
                        it = low.find(c);
                    }
                }
            }
        }
        prev = c;
    }
    
    low.clear();
    prev = str[n-1];
    low.insert(prev);
    rpsum[1] = 1;
    for(int i = 1; i < n; i++){
        c = str[n-i-1];
        if(c == prev){
            rpsum[i+1] = rpsum[i];
        }
        else{
            if(c > prev){
                rpsum[i+1] = rpsum[i] + 1;
                low.insert(c);
            }
            if(c < prev){
                if(low.find(c) != low.end()){
                    rpsum[i+1] = rpsum[i];
                }
                else{
                    rpsum[i+1] = rpsum[i]+1;
                    low.insert(c);
                }
                set<char>::iterator it = low.find(c);
                if(it != low.end()){
                    it++;
                    for(; it != low.end(); it++){
                        low.erase(*it);
                        it = low.find(c);
                    }
                }
            }
        }
        prev = c;
    }
    
    area inp[k];
    for(int i = 0; i < k; i++){
        cin >> inp[i].start >> inp[i].end;
        inp[i].start--;
        inp[i].end--;
    }

    int a, b, sum;
    for(int i = 0; i < k; i++){
        sum = 0;
        a = inp[i].start;
        b = inp[i].end;
        if(a > 0){
            sum += psum[a];
            if(b < n-1){
                sum += rpsum[n-b-1];
            }
        }
        else{
            sum += rpsum[n-b-1];
        }
        cout << sum << endl;
    }
}
