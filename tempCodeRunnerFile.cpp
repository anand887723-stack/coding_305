#include <iostream>
using namespace std;
long long int  d(long long int  S, long long int  K, long long int  child) {
    if (S == 0 && child == 3) {
        return 1;
    }
    
    if (S < 0 || child == 3) {
        return 0;
    }
    
    long long int  ways = 0;
    for (long long int  i = 0; i <= K; ++i) {
        ways += d(S - i, K, child + 1);
    }

    return ways;
}

int   main() {
  
    
    // Start distributing toy cars to the first child
    long long int  ways = d(2,2, 0);
    
cout<<ways<<endl;
}