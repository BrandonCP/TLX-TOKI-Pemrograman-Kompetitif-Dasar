#include <bits/stdc++.h>
using namespace std;

int main(){
    string A, B;
    getline(cin, A);
    getline(cin, B);
    bool bisa = false;
    for(int i=0;i<A.length();i++){
        string temp = A;
        temp.erase(i, 1);
        if(temp==B){
            bisa = true;
        }
    }

    if(bisa){
        cout << "Tentu saja bisa!";
    } else{
        cout << "Wah, tidak bisa :(";
    }
    cout << "\n";
    return 0;
}