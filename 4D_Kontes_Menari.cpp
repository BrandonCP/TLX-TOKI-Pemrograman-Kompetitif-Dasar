#include <bits/stdc++.h>
#define loop1(i, N) for(int i=0;i<N;i++)
using namespace std;

int N, R, Y, J, K, Z, D[1001], jawaban[100002], H[1001];
bool yakin=false, chosen[1001];
char T[1001];

void permutation(int r, char A, int sum){
    if(r==0){
        jawaban[min(100001,sum)]++;
    }else{
        loop1(i, N){
            if(!chosen[i]){
                chosen[i] = true;
                K = D[i];
                if(A=='P') K *= 2;
                if(A=='L') K /= 2;
                if(A=='Y') yakin = true;
                if(yakin) K += Y;
                permutation(r-1, T[i], sum+K);
                chosen[i] = false;
            }
            if(chosen[Z]==false) yakin = false;
        }
    }
}

int main(){
    string S;
    getline(cin, S);
    cin >> N >> R >> Y >> J;
    loop1(i, N){
        scanf("%d %c", &D[i], &T[i]);
        if(T[i]=='Y') Z = i;
    }
    permutation(R, 'B', 0);
    for(int i=1;i<=100001;i++){
        jawaban[i] += jawaban[i-1];
    }
    loop1(i, J){
        scanf("%d", &H[i]);
        cout << (jawaban[100001]-jawaban[H[i]]) << "\n";
    }

    return 0;
}