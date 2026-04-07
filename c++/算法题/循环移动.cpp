#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin >> n >>m;
    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int j=n-m;j<n;j++){
        cout << a[j] << ' ';
    }
    for (int j=0; j<n-m-1; j++){
        cout << a[j] << ' ';
    }
    cout << a[n-m-1];
    return 0;
}

