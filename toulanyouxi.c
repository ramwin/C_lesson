#include <iostream>
using namespace std;
int main(){
    int p, n;
    cin >> p >> n ;
    int lankuang[p];
    // 定义篮筐都是没有求
    for (int i=0; i<p; i++){
        lankuang[i]=0;
    }
    int lanqiu[n];
    // 定义篮球的数字
    for (int ia=0; ia<n ; ia++){
        cin >> lanqiu[ia];
    }
    int jieguo;
    jieguo = 0;
    for (int ib =0; ib<n; ib++){
        //  如果篮筐有求
        if (lankuang[lanqiu[ib]%p]==1) {
            jieguo = ib+1;
            break;
        }
        // 如果篮筐没秋
        else {
            lankuang[lanqiu[ib]%p]=1;
        }
        // 如果是最后一个求
        if (ib==n-1){
            jieguo = ib+1;
        }
    }
    cout << jieguo;
    return 0;
}
