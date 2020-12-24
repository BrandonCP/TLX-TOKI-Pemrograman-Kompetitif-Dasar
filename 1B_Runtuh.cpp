#include <bits/stdc++.h>
using namespace std;

int R, C;
char m[20][8];
int terbawah = -1;
bool penuh;

bool cekbaris(){
    bool runtuh = false;
    for(int i=0;i<R;i++){
        penuh = true;
        for(int j=0;j<C;j++){
            if(m[i][j]=='0'){
                penuh = false;
            }
        }
        if(penuh){
            runtuh = true;
            if(terbawah<i){
                terbawah = i;
            }
            for(int k=0;k<C;k++){
                m[i][k] = '0';
            }
        }
    }
    return runtuh;
}

int main(){
    cin >> R >> C;    

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> m[i][j];
        }
    }

    while(cekbaris()){
        for(int i=0;i<C;i++){
            int k = terbawah;
            int jumlah=0;
            for(int j=0;j<terbawah;j++){
                if(m[j][i]=='1'){
                    jumlah++;
                    m[j][i]='0';
                }
                if(m[k+1][i]=='0'){
                    k++;
                }
            }
            while(jumlah--){
                m[k][i] = '1';
                k--;
            }
        }
    }

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout << m[i][j]; 
        }
        cout << "\n";
    }
    
    return 0;
}