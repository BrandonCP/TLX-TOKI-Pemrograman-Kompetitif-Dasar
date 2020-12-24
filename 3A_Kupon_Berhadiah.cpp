#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, X, minval=200000;
    scanf("%d %d", &N, &X);

    int a[N], indeks_hasil; 
    for(int i=0;i<N;i++){
        cin >> a[i];
        if(abs(a[i]-X)<minval){
            indeks_hasil = i;
            minval = abs(a[i]-X);
        }
        if(abs(a[i]-X)==minval){
            if(a[i]<a[indeks_hasil]){
                indeks_hasil = i;
            }
        }
    }

    cout << a[indeks_hasil] << "\n";
    return 0;
}