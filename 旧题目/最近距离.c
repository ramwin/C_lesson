#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
int main(){
    int n=0;    // 点的个数
    cin >> n;
    double x[n];   // 横坐标构成的序列
    double y[n];   // 众坐标构成的序列，暂时不会c++ 的对象。要是可以用python就好了
    double distance=0;
    int result1 = 0;
    int result2 = 1;    // result1 和 2 储存序号
    double dx, dy, newdistance;
    for (int i=0; i<2; i++){
        cin >> x[i];
        cin >> y[i];    // 因为有唯一解，所以先算出一个最短路径
    }
    distance = sqrt( (x[0]-x[1])* (x[0]-x[1])+ (y[0]-y[1])*(y[0]-y[1]));
    for (int j=2; j<n; j++){
        // 之后输入更多的数据，每次判断是否更加短
        cin >> x[j];
        cin >> y[j];
        // 判断是否更短
        for (int k=0; k<j; k++){
            if ( (abs(x[k] - x[j]) >= distance) || (abs(y[k] - y[j]) >= distance) ){
                // 
                continue;
            }
            dx = x[k] - x[j];
//            cout << "dx " << dx << endl;
            dy = y[k] - y[j];
//            cout << "dy " << dy << endl;
            newdistance = sqrt( dx*dx + dy*dy  );
//            cout << "new" << newdistance<<endl;
            if (newdistance < distance ){
//                cout << "发现更小的" << endl;
//                cout << newdistance << endl;
                result1 = k;
                result2 = j;

                distance = newdistance;
            }
        }
    }
    cout << "Closest points:" << result1 << ',' << result2<<endl;
//    cout << distance;
    return 0;
}

