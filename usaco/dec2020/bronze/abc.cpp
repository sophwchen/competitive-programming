#include <iostream>
#include <set>
using namespace std;

int main(void) {
    long a, b, c;
    multiset<long> input;
    
    long x;
    for(long i = 0; i < 7; i++){
        cin >> x;
        input.insert(x);
    }
    
    a = *input.begin();
    input.erase(input.find(a));
    b = *input.begin();
    input.erase(input.find(b));
    input.erase(input.find(a+b));
    c = *input.begin();
    
    cout << a << ' ' << b << ' ' << c << endl;
}
