#include <iostream>
using namespace std;
int main(){
    int n, n100, n50, n20, n10, n5, n1;
    cin >> n;
    n100= (n-n%100)/100;
    n50 = (n%100 >=50 );
    n20 = (n%100-50*n50)/20;
    n10 = (n%100 - n50*50 - n20*20)/10;
    n5  = n%10 >= 5;
    n1  = n%5;
    cout << n100 << endl;
    cout << n50 << endl;
    cout << n20 << endl;
    cout << n10 << endl;
    cout << n5 << endl;
    cout << n1 << endl;
    return 0;
}
