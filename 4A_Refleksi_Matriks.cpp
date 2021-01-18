#include <bits/stdc++.h>
using namespace std;

int N;
int A[75+1][75+1];
int B[75+1][75+1];
bool identik = true;
bool horisontal = true;
bool vertikal = true;
bool dkananbawah = true;
bool dkiribawah = true;

void cek_identik(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(A[i][j]!=B[i][j])
                identik = false;
            if((A[i][j]!=B[N-i+1][j]) || (A[N-i+1][j]!=B[i][j]))
                horisontal = false;
            if((A[i][j]!=B[i][N-j+1]) || (A[i][N-j+1]!=B[i][j]))
                vertikal = false;
            if((A[i][j]!=B[j][i] || A[j][i]!=B[i][j]))
                dkananbawah = false;
            if((A[i][j]!=B[N-j+1][N-i+1] || A[N-j+1][N-i+1]!=B[i][j]))
                dkiribawah = false;
        }
    }
}

int main(){
    cin >> N >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> A[i][j];
        }
    }

    cin >> N >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> B[i][j];
        }
    }
    cek_identik();
    if(identik){
        cout << "identik";
    }else if(horisontal){
        cout << "horisontal";
    }else if(vertikal){
        cout << "vertikal";
    }else if(dkananbawah){
        cout << "diagonal kanan bawah";
    }else if(dkiribawah){
        cout << "diagonal kiri bawah";
    }else{
        cout << "tidak identik";
    }
    cout << "\n";

    return 0;
}