#include <bits/stdc++.h>
using namespace std;

int A[100][100];

void petakmenarik(int a, int b, int value){
    int hasil;
    int x=0, y=0;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            hasil = 1;
            if(i!=1)
                hasil *= A[i-1][j];
            if(j!=1)
                hasil *= A[i][j-1];
            if(i!=a)
                hasil *= A[i+1][j];
            if(j!=b)
                hasil *= A[i][j+1];
            if(hasil==value){
                if(x==0 && y==0){
                    x = i;
                    y = j;
                }else{
                    if(j<y){
                        x = i;
                        y = j;
                    }
                    else if(j==y){
                        x = min(x, i);
                    }
                }
            }
        }
    }
    cout << x << " " << y << "\n";
}

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> A[i][j];
        }
    }
    petakmenarik(N, M, K);

    return 0;
}