#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    long long kpk = 1;
    long long D;
    for(int i=0;i<N;i++){
        cin >> D;
        kpk = (kpk*D)/__gcd(kpk, D);
    }
    cout << kpk << "\n";
    
    return 0;
}