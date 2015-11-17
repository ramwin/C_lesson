#include <iostream>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    int max[K];
    // 生成最大的5个数的列表
    for (int i=0; i<K; i++){
        max[i]=0;
    }
    int array[N];
    // 获取所有的数，构成 array
    for (int i=0; i<N; i++){
        cin >> array[i];
        // 看输入的数字是否比5个数大, 并重新生成array
        if ( array[i] > max[0] ){
            max[0] = array[i];
        }
        for (int j=1; j<K; j++ ){
            if ( max[j] < array[i] ) {
                max[j-1] = max[j];
                max[j] = array[i];
            }
        }
    }
    cout << max[0] << endl;
    return 0;
}
