#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    int n;
    cin >> n;
    double x[n], y[n];
    double maxLength=0;
    double tmp;
    double dx, dy;
    for (int i=0;i<n;i++){
        cin >> x[i] >> y[i];
        for (int j=0; j<i; j++){
            dx = x[j]-x[i];
            dy = y[j]-y[i];
            tmp = sqrt(dx*dx + dy*dy);
            if (tmp > maxLength){
                maxLength = tmp;
            }
        }
    }
    cout << fixed << setprecision(4) << maxLength<<endl;
    return 0;
}
