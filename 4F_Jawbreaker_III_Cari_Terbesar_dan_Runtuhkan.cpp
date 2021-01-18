#include <bits/stdc++.h>
using namespace std;

int M, N;
bool visited[25][25];
int temp, hasil;
char angka, nilai;
int p, q;

void jawbreaker_cari_terbesar(int b, int k, char A[][25]){
    if(b>=0 && b<=M-1 && k>=0 && k<=N-1){
        if(A[b][k] == nilai){
            if(!visited[b][k]){
                visited[b][k] = true;
                temp++;
                jawbreaker_cari_terbesar(b-1, k, A);
                jawbreaker_cari_terbesar(b+1, k, A);
                jawbreaker_cari_terbesar(b, k-1, A);
                jawbreaker_cari_terbesar(b, k+1, A);
            }
        }
    }
}

void jawbreaker_hilangkan(int p, int q, char A[][25]){
    if(p>=0 && p<=M-1 && q>=0 && q<=N-1){
        if(A[p][q] == angka){
            if(visited[p][q]){
                A[p][q] = '.';
                int a = p-1;
                while(a>=0){
                    swap(A[a][q], A[a+1][q]);
                    a--;
                }
                jawbreaker_hilangkan(p-1, q, A);
                jawbreaker_hilangkan(p+1, q, A);
                jawbreaker_hilangkan(p, q-1, A);
                jawbreaker_hilangkan(p, q+1, A);
            }
        }
    }
}

int main(){
    cin >> M >> N;
    char A[M][25];
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin >> A[i][j];
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            nilai = A[i][j];
            jawbreaker_cari_terbesar(i, j, A);
            if(hasil<temp){
                hasil = temp;
                p = i;
                q = j;
                angka = A[i][j];
            }
            temp = 0;
        }
    }
    jawbreaker_hilangkan(p, q, A);
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cout << A[i][j];
            if(j<N-1){
                cout << " ";
            }else{
                cout << endl;
            }
        }
    }

    return 0;
}