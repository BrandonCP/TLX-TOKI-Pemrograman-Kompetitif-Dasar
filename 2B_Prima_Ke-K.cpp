#include <bits/stdc++.h>
using namespace std;

vector<long long> primelist = {};
long long a = 990000;

void SieveOfErathosthenes(){
    bool eliminated[a+1]={false};
    primelist.push_back(1);
    for(long long i=2;i<a;i++){
        if(!eliminated[i]){
            primelist.push_back(i);
            long long j = i*i;
            while(j<=a){
                eliminated[j] = true;
                j = j+i;
            }
        }
    }
}

int main(){
    int T;
    long long K;
    cin >> T;
    SieveOfErathosthenes();
    while(T--){
        cin >> K;
        cout << primelist[K] << "\n";
    }

    return 0;
}