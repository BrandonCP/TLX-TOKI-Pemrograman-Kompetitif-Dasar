#include <bits/stdc++.h>
using namespace std;

long long N, Q;

void binarysearch(string h[], string X, string b[]){
    string hasil ="";
    int kiri = 1;
    int kanan = N;
    while((kiri<=kanan) && (hasil=="")){
        int tengah = (kiri+kanan) / 2;
        if(X<h[tengah]){
            kanan = tengah-1;
        }else if(X>h[tengah]){
            kiri = tengah+1;
        }else{
            hasil = b[tengah];
        }
    }
    if(hasil==""){
        cout << "NIHIL\n";
    }else{
        cout << hasil << "\n";
    }
}

int main(){
    cin >> N >> Q;
    string A[N+1];
    string B[N+1];
    string C;
    for(int i=1;i<=N;i++){
        cin >> A[i] >> B[i];
    }
    for(int j=1;j<=Q;j++){
        cin >> C;
        binarysearch(A, C, B);
    }
}