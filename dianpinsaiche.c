#include <iostream>
using namespace std;
int A(int n){
    if (n==2) return 1;
    else return 0;
}
int B(int n){
    return n==4;
}
int C(int n){
    return n!=3;
}
int D(int n){
    return n!=4;
}
int main(){
    int saiche[4];
    int n;
    for (int i=1;i<=4;i++){
        if (A(i) + B(i) + C(i) + D(i) == 1){
            cout << i << endl;
            if (A(i)==1) cout <<'A' << endl;
            if (B(i)==1) cout <<'B' << endl;
            if (C(i)==1) cout <<'C' << endl;
            if (D(i)==1) cout <<'D' << endl;

        }
    }
    return 0;
}    
