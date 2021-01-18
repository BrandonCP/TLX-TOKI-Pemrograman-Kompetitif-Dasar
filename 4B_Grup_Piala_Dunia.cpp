#include <bits/stdc++.h>
using namespace std;

bool mungkin;

void bruteforce(int a, int b, int n, int A[], int B[]){
    if(a==n-1){
        bool cek = true;
        for(int i=0;i<n;i++){
            if(A[i] != B[i]){
                cek = false;
            }
        }
        if(cek){
            mungkin = true;
        }
    }else if(b==n){
        bruteforce(a+1, a+2, n, A, B);
    }else{
        B[a] += 3;
        bruteforce(a, b+1, n, A, B);
        B[a] -= 3;
        
        B[b] += 3;
        bruteforce(a, b+1, n, A, B);
        B[b] -= 3;

        B[a] += 1;
        B[b] += 1;
        bruteforce(a, b+1, n, A, B);
        B[a] -= 1;
        B[b] -= 1;
    }
}

int main(){
    int T, N;
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> N;
        int A[N];
        for(int j=0;j<N;j++){
            cin >> A[j];
        }
        int B[N];
        memset(B, 0, sizeof(B));
        mungkin = false;
        bruteforce(0, 1, N, A, B);
        if(mungkin){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}