#include <bits/stdc++.h>
#define loop1(i, M) for(int i=0;i<M;i++)
#define loop2(j, N) for(int j=0;j<N;j++)
using namespace std;

int M, N, hasil1, hasil2, hasil3, hasil4;
bool visited1[50][50], visited2[50][50];

bool cek1(int a, int b, char c, char A[50][50]){
    if(a>=0 && a<=M-1 && b>=0 && b<=N-1 && A[a][b] == c && A[a][b] != '.' && !visited1[a][b]){
        return true;
    }else{
        return false;
    }
}

bool cek2(int a, int b, char c, char A[50][50]){
    if(a>=0 && a<=M-1 && b>=0 && b<=N-1 && A[a][b]==c && !visited2[a][b]){
        return true;
    }else{
        return false;
    }
}

int jawbreaker_cari_terbesar(int a, int b, char ans, char A[50][50]){
    if(!cek1(a, b, ans, A)){
        return 0;
    }else{
        visited1[a][b] = true;
        int temp = 1;
        temp += jawbreaker_cari_terbesar(a-1, b, ans, A);
        temp += jawbreaker_cari_terbesar(a+1, b, ans, A);
        temp += jawbreaker_cari_terbesar(a, b-1, ans, A);
        temp += jawbreaker_cari_terbesar(a, b+1, ans, A);
        return temp;
    }
}

int jawbreaker_hilangkan(int p, int q, char angka, char C[50][50]){
    if(!cek2(p, q, angka, C)){
        return 0;
    }else{
        visited2[p][q] = true;
        C[p][q] = '.';
        int temp = 1;
        temp += jawbreaker_hilangkan(p-1, q, angka, C);
        temp += jawbreaker_hilangkan(p+1, q, angka, C);
        temp += jawbreaker_hilangkan(p, q-1, angka, C);
        temp += jawbreaker_hilangkan(p, q+1, angka, C);
        return temp;
    }
}

void runtuhkan(char b[50][50]){
    loop1(x, N){
        loop2(y, M){
            if(b[y][x]=='.'){
                if(y==0){
                    continue;
                }else{
                    int a = y;
                    while(a>0){
                        swap(b[a-1][x], b[a][x]);
                        a--;
                    }
                }
            }
        }
    }
}

int main(){
    cin >> M >> N;
    char A[50][50], B[50][50];
    char simpan;
    loop1(i, M){
        loop2(j, N){
            cin >> A[i][j];
        }
    }

    pair<int, int> point;
    memcpy(B, A, 50*50*sizeof(char));
    loop1(i, M){
        loop2(j, N){
            char angka = B[i][j];
            int z = jawbreaker_cari_terbesar(i, j, angka, B);
            z *= (z-1);
            if(hasil3<z){
                hasil3 = max(hasil3, z);
                point = make_pair(i, j);
                simpan = B[i][j];
            }
        }
    }
    jawbreaker_hilangkan(point.first, point.second, simpan, B);
    runtuhkan(B);
    memset(visited1, 0, 50*50*sizeof(bool));
    loop1(i, M){
        loop2(j, N){
            int z = jawbreaker_cari_terbesar(i, j, B[i][j], B);
            z *= (z-1);
            hasil4 = max(hasil4, z);
        }
    }
    memset(visited1, 0, 50*50*sizeof(bool));
    memset(visited2, 0, 50*50*sizeof(bool));
    loop1(i, M){
        loop2(j, N){
            if(!visited2[i][j]){
                memcpy(B, A, 50*50*sizeof(char));
                int z = jawbreaker_hilangkan(i, j, B[i][j], B);
                z *= (z-1);
                runtuhkan(B);   
                loop1(k, M){
                    loop2(l, N){
                        if(!visited1[k][l]){
                            int x = jawbreaker_cari_terbesar(k, l, B[k][l], B);
                            x *= (x-1);
                            if(hasil1<x){
                                hasil1 = x;
                                hasil2 = z;
                            }else if(hasil1==x){
                                hasil2 = max(z, hasil2);
                            }
                        }
                    }
                }
                memset(visited1, 0, 50*50*sizeof(bool));
            }
        }
    }
    
    if((hasil3+hasil4) < (hasil1+hasil2) && hasil2 !=0 && hasil1 != 0){
        cout << hasil1+hasil2 << endl;
    }else{
        cout << hasil3+hasil4 << endl;
    }

    return 0;
}