#include <iostream>
using namespace std;
int main(){
    int k;
    cout<< "第一组" <<endl;
    cin >> k ;  
    int a[k];
    cout << "开始输入数组" <<endl ;
    for (int i=0;i<k;i++){
        cin >> a[i];
    }
    int num5 = 0,  num10 = 0, num1 = 0;
    for (int i=0;i<k;i++){
        if (a[i]==1) {
            num1++;
        } else if (a[i]==5) {
            num5++;
        } else if (a[i]==10){
            num10++;
        }
    }
    cout << num1 << endl << num5 << endl << num10 <<endl;
    return 0;
}

