#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i=0; i<n; i++){
        cin >> a[n-i-1];
    }
    for (int i=0; i<n; i++){
        cout << a[i] << endl;
    }
    return 0;
}
