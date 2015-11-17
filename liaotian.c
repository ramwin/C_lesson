#include <iostream>
using namespace std;
int main(){
    // 输入p, q, l, r
    int p,q,l,r;
    cin >> p >> q >> l >>  r;
    // 获取小蘑的作息时间
    int xiaomo[1000];
    int xiaogu[1000];
    int suoyin1=0; // 定义从哪开始输入数据
    // 获得小蘑的数据
    for (int ia=0; ia<p; ia++){
        int xiaomozuo, xiaomoyou; 
        cin >> xiaomozuo >> xiaomoyou;
        for (int ib=xiaomozuo; ib<=xiaomoyou; ib++){
            xiaomo[suoyin1] = ib;
            suoyin1 = suoyin1+1;
        }
    }
    int suoyin2 = 0;
    // 获得小姑的数据
    for (int ic=0; ic<q; ic++){
        int xiaoguzuo,xiaoguyou;
        cin >> xiaoguzuo >> xiaoguyou;
        for (int id=xiaoguzuo; id<=xiaoguyou; id++){
            xiaogu[suoyin2] = id;
            suoyin2 = suoyin2+1;
        }
    }
    int sum = 0;    //所有可以起床的时间
    for (int ie=l; ie<=r; ie++){ //每个循环代表什么时候起床
        int liaotian;
        liaotian = 0;    // 是否有聊天时间
        // 生成小菇的起床时间
        int xiaoguzhen[1000];
        for (int ig=0; ig<suoyin2; ig++){
            xiaoguzhen[ig] = xiaogu[ig]+ie;
            // 看这个时间是不是在小蘑休闲时间
            for (int ih=0; ih<suoyin1; ih++){
                if (xiaomo[ih] == xiaoguzhen[ig]){
                    liaotian=1;
                }
            }
        }
        sum = sum+liaotian;
    }
    cout << sum <<endl;
    return 0;
}
