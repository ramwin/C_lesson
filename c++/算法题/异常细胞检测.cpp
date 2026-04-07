#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    int n[N][N];
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> n[i][j];
        }
    }
    int sum=0;
    for (int i=1; i<N-1; i++){
        for (int j=0; j<N-1; j++){
            if (
                n[i][j]+50 <= n[i+1][j] &&
                n[i][j]+50 <= n[i-1][j] &&
                n[i][j]+50 <= n[i][j+1] &&
                n[i][j]+50 <= n[i][j-1]
                ) {
                sum += 1;
            }
        }
    }
    cout << sum <<endl;
    return 0;
}
