#include <iostream>
using namespace std;
int main(){
    int a;
    cin >> a;
    int num=0;
    while (a>0) {
        num += a%2;
        a = (a-a%2)/2;
    }
    cout << num << endl;
    return 0;
}
