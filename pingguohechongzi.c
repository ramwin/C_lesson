#include <iostream>
using namespace std;
int main(){
    //输入苹果数n，虫子x小时吃一个苹果，经过的时间y
    int n,x,y,remain;
    cin >> n >> x >> y;
    if (y>=n*x) remain=0;
    else {
        if (y%x ==0 ) remain = n -y/x;
        else remain = n - (y-y%x)/x -1;
    }
    cout << remain;
    return 0;
}
