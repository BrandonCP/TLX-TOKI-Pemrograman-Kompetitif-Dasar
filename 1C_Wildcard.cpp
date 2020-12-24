#include <bits/stdc++.h>
using namespace std;

int main(){
    string A="", B="";
    cin >> A;
    bool depan=false, tengah=false, belakang=false;
    int pos = A.find('*');
    if(pos==0 && A.length()!=1){
        depan = true;
    }
    if(pos!=0 && pos!=(A.length()-1)){
        tengah = true;
    }
    if(pos==A.length()-1){
        belakang = true;
    }

    int N;
    cin >> N;
    for(int a=0;a<N;a++){
        bool bisa = true;
        cin >> B;
        int k = pos+1;
        if(B.length() < A.length()-1){
            continue;
        }
        if(depan){
            for(int i=B.length()-(A.length()-k);i<B.length();i++){
                if(A[k]!=B[i]){
                    bisa = false;
                }
                k++;
            }
        }
        if(tengah){
            for(int i=0;i<pos;i++){
                if(A[i]!=B[i]){
                    bisa = false;
                }
            }
            for(int j=B.length()-(A.length()-k);j<B.length();j++){
                if(A[k]!=B[j] || B.length()<2){
                    bisa = false;
                }
                k++;
            }
        }
        if(belakang){
            for(int i=0;i<pos;i++){
                if(A[i]!=B[i]){
                    bisa = false;
                }
            }
        }
        if(bisa){
            cout << B << "\n";
        }
    }

    return 0;
}