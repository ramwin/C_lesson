#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int array[n];
    for (int i=0; i<n; i++){
        cin >> array[i];
    }
    for (int i=0; i<n; i++){
        if ( (array[i]*5-array[i]*2) > 300) cout<< "Bike" << endl;
        if ( (array[i]*5-array[i]*2) < 300) cout<< "Walk" << endl;
        if ( (array[i]*5-array[i]*2) ==300) cout << "All" <<endl;
    }
    return 0;
}
