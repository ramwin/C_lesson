#include <iostream>
using namespace std;
int main(){
    int n, a[1000]; //一共 n 个数字， 不超过1000个数字。
    cin >> n;
    // 输入 n 个数字
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    // 冒泡排序
    for ( int i=0; i<n-1; i++){
        for (int j=1; j<n; j++){
            if (a[j-1] > a[j]) {
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
    // 依次输出
    for (int i=0; i<n; i++){
        cout << a[i] << endl;
    }
    return 0;
}
