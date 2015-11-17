#include <iostream>
using namespace std;
int main(){
    int h, r;
    cin >> h >> r;
    float onevolumn, num;
    int n;
    onevolumn = 3.14159*r*r*h;
    num = 20*1000/onevolumn;
    n=num+1;
    cout << n;
    return 0;
}
