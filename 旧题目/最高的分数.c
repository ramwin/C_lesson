#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int array[n];
    int max=0;
    for (int i=0;i<n;i++){
        cin >> array[i];
        if (array[i] >= max) max=array[i];            
    }
    cout << max;
    return 0;
}

