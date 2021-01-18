#include <bits/stdc++.h>
using namespace std;

int mod = 1000000;
bool digit;

unsigned long long power(unsigned long long a, unsigned long long b){
    unsigned long long temp;
    if(b==0) return 1;
    else if(b==1) return a;
    temp = power(a, b/2);
    if(b%2==0){
        if(temp*temp>999999)
            digit = true;
        return (temp*temp)%mod;
    }else{
        if(a*temp*temp>999999)
            digit = true;
        return (a*temp*temp)%mod;
    }
}

int main(){
    unsigned long long A, B, Z;
    cin >> A >> B;
    if(A>999999){
        A %= mod;
        digit = true;
    }
    Z = power(A, B);
    if(Z>999999 || digit || Z==0)
        cout << setw(6) << setfill('0') << Z%mod << "\n";
    else
        cout << Z%mod << "\n";
    return 0;
}