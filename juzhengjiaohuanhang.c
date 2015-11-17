#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int array[5][5];
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            cin >> array[i][j];
        }
    }
    int n,m;
    cin >> n >> m;
    int temp;
    if (( n>4 or n<0 )  or ( m >4 or m < 0) ){
        cout << "error" << endl;
    }
    else {
        for (int k=0 ; k <5;k++){
            temp = array[n][k];
            array[n][k]=array[m][k];
            array[m][k]=temp;
        }
        for (int l=0; l<5;l++){
            for (int o=0;o<5;o++){
                cout << setw(4) << array[l][o];
            }
            cout << endl;
        }

    }
    return 0;
}
