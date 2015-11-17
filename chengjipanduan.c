#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    if (n<=60) cout <<7;
    if ( 60<=n && n<70 ) cout << 6;
    if ( 70<=n && n<80 ) cout << 5;
    if ( 80<=n && n<85 ) cout << 4;
    if ( 85<=n && n<90 ) cout << 3;
    if ( 90<=n && n<95 ) cout << 2;
    if ( 95<=n && n<=100 ) cout << 1;
    return 0;
}
