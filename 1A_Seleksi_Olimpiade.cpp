#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; //T = banyaknya seleksi yang diadakan
    cin >> T;
     
    bool ada[T] = {false};
    for(int i=0;i<T;i++){
        int N, M; //N = jumlah peserta seleksi, M = jumlah peserta lulus   
        cin >> N >> M;
        string id_cek, id[N];
        int nilai[N][N];
        cin >> id_cek;
        for(int j=0;j<N;j++){
            cin >> id[j];
            for(int k=0;k<3;k++){
                cin >> nilai[j][k];
            }
        }        
        int rank=0;
        for(int j=1;j<N;j++){
            if(nilai[j][2]>nilai[rank][2]){
                swap(id[rank], id[j]);
                rank++;
            } else if(nilai[j][2]==nilai[rank][2]){
                if(nilai[j][1]>nilai[rank][1]){
                    swap(id[rank], id[j]);
                    rank++;
                } else if(nilai[j][1]==nilai[rank][1]){
                    if(nilai[j][0]>nilai[rank][0]){
                        swap(id[rank], id[j]);
                        rank++;
                    }
                }
            }
        }

        for(int l=0;l<M;l++){
            if(id[l]==id_cek){
                ada[i] = true;
            }
        }
    }

    for(int i=0;i<T;i++){
        if(ada[i]==true){
            cout << "YA\n";
        } else{
            cout << "TIDAK\n";
        }
    }
    
    return 0;
}