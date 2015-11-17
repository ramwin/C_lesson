#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int array[5];
    int sum=0;
    for (int i=0; i<5; i++){
        cin >> array[i];
        if (array[i] < n) sum += array[i];
    }
    cout << sum;
    return 0;
}
