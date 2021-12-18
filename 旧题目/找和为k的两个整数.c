#include <iostream>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int array[n];
    for (int i=0; i<n; i++){
        cin >> array[i];
    }
    bool yes=false;
    for (int i=0; i<n; i++){
        if (yes) break;
        for (int j=i+1; j<n; j++){
            if (yes) break;
            if (array[i]+array[j] == k){
                cout << "yes" <<endl;
                yes=true;
            }
        }
    }
    if (!yes) cout << "no";
    return 0;
}
