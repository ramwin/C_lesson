#include <iostream>
using namespace std;
int main(){
    int m, n;
    cin >> m >> n;
    int sum=0;
    for (int i=m; i<=n; i++){
        if ( i%2==0 ){
            int x=0;
        } else {
            sum = sum +i;
        }
    }
    cout << sum;
    return 0;
}
