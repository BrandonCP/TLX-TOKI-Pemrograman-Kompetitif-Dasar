#include <bits/stdc++.h>
using namespace std;

int N;
int A[5+1];
int B[5+1];

bool bruteforce(int a, int b){
    if(a==N-1){
        bool cek = true;
        for(int i=0;i<N;i++){
            if(A[i] != B[i]){
                cek = false;
            }
        }
        return cek;
    }else if(b==N){
        return bruteforce(a+1, a+2);
    }
    B[a] += 3;
    bool option1 = bruteforce(a, b+1);
    B[a] -= 3;
    
    B[b] += 3;
    bool option2 = bruteforce(a, b+1);
    B[b] -= 3;

    B[a] += 1;
    B[b] += 1;
    bool option3 = bruteforce(a, b+1);
    B[a] -= 1;
    B[b] -= 1;
    return (option1 || option2 || option3);
}

int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> N;
        for(int j=0;j<N;j++){
            cin >> A[j];
        }
        if(bruteforce(0, 1)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}