#include <iostream>
using namespace std;
int main(){
    int mid[15000];
    int n;
    cin >> n;
    int count=0;
    while (n!=0) {
        count += 1;
        int array[n];
        for (int i=0; i<n; i++){
            cin >> array[i];
            for (int j=i; j>=1; j--){
                if ( array[j] <= array[j-1] ) {
                    int tmp = array[j];
                    array[j] = array[j-1];
                    array[j-1] = tmp;
                }
            }
        }
        if (n%2==1){
            mid[count-1] = array[(n-1)/2];
        }
        else {
            mid[count-1] = (array[n/2] + array[(n-2)/2] )/2;
        }
        cin >> n;
    }
    for (int i =0; i<count; i++){
        cout << mid[i] << endl;
    }
    return 0;
}
