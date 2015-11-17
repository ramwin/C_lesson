#include <iostream>
using namespace std;
int main(){
    int L=0, M=0;
    cin >> L >> M;
    int trees[10000]={0};
    for (int i=L+1; i<10000; i++){
        trees[i] = 1;
    }
    int left, right;
    for (int i=0; i< M; i++){
        cin >> left >> right;
        for (int i=left ; i<=right; i++){
            trees[i] = 1;
        }
    }
    int sum=0; 
    for (int j=0; j<=L; j++){
        if (trees[j] == 0) sum +=1;
    }
    cout << sum << endl;
    return 0;
}
