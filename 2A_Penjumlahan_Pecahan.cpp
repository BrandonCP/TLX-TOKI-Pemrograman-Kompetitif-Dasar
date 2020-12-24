#include <bits/stdc++.h>
using namespace std;

int euclid(long long e, long long f){
    if(f==0)
        return e;
    else
        return euclid(f, e%f);
}

int main(){
    long long A,B,C,D;
    cin >> A >> B;
    cin >> C >> D;
    long long E=0,F=0;
    E = (A*D)+(C*B);
    F = B*D;
    
    int fpb = euclid(E,F);
    E /= fpb;
    F /= fpb;
    cout << E << " " << F << "\n";
    
    return 0;
}