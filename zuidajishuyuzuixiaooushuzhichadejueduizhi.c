#include <iostream>
using namespace std;
int main(){
    int array[6];
    int max=0, min=0;
    for (int i=0; i<6;i++){
        cin >> array[i];
        if (array[i]%2==0) {
            if (min==0) min=array[i];
            else {
                if (min>array[i]) min=array[i];
            }
        }
        else {
            if (array[i]>max) max=array[i];
        }
    }
    int minux;
    minux = max-min;
    if (minux<0) minux=0-minux;
    cout << minux;
    return 0;
}
