#include <iostream>
using namespace std;
int main(){
    int N, k, deposit,can;
    while(cin >> N>>k){
    float price;
    price = 200;
    deposit = 0;
    can = 0;
    for (int i=1; i<=20; i++){
        deposit += N;
        if (deposit >= price){
            cout << i<<endl;
            can = 1;
            break;
        }
        price *=(1+k/100.0);
    }
    if (!can) {
        cout << "Impossible" << endl;
    }
    }
    return 0;
}

