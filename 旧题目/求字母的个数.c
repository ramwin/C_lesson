#include <iostream>
using namespace std;
int main(){
    char s[80]={'w'};
    cin.getline(s,80);
    int result[5]={0,0,0,0,0};
    for (int i=0; i<80; i++){
        if (s[i]=='a') result[0]++;
        if (s[i]=='e') result[1]++;
        if (s[i]=='i') result[2]++;
        if (s[i]=='o') result[3]++;
        if (s[i]=='u') result[4]++;
    }
    for (int j=0; j<4;j++){
        cout << result[j]<<' ';
    }
    cout << result[4];
    return 0;
}
