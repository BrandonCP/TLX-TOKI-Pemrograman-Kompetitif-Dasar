#include <bits/stdc++.h>
using namespace std;

int M, N;
int nilai, temp=0;
int hasil;
int A[25][25];
bool visited[25][25];

void jawbreaker_cari_terbesar(int b, int k, int value){
    if(b>=0 && b<=M-1 && k>=0 && k<=N-1){
        if(A[b][k] == value){
            if(!visited[b][k]){
                visited[b][k] = true;
                temp++;
                jawbreaker_cari_terbesar(b-1, k, value);
                jawbreaker_cari_terbesar(b+1, k, value);
                jawbreaker_cari_terbesar(b, k+1, value);
                jawbreaker_cari_terbesar(b, k-1, value);
            }
        }
    }
}

int main(){
    cin >> M >> N;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin >> A[i][j];
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            nilai = A[i][j];
            jawbreaker_cari_terbesar(i, j, nilai);
            if(hasil<temp){
                hasil = temp;
            }
            temp = 0;
        }
        
    }
    cout << hasil*(hasil-1) << "\n";
    return 0;
}