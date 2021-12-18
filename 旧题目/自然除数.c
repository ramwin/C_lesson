#include <iostream>
using namespace std;
int main(){
    int n, a, b;
    cin >> n;
    for(int i=10; i<=n; i++){
        // 判断是否是自然除数
        a = i%10;
        b = (i-i%10)/10;
        if ( i%(a+b)==0 ) {
            cout << i << endl;
        }
    }
    return 0;
}
