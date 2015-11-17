#include <iostream>
using namespace std;
int main(){
    char s[500];
    // result 和 len 用于保留最长的单词以及其长度。
    int len=0;
    char result[500];
    int i=0;
    int templen=0;
    char tempresult[500];
    cin.getline(s,500);
    while ( s[i]!='\0' ) {
        if (s[i]=='.' || s[i]==' '){
            if ( templen > len) {
                len = templen;
                for (int j=0; j < templen; j++){
                    result[j] = tempresult[j];
                }
            }
            templen=0;
        }
        else {
            tempresult[templen] = s[i];
            templen += 1;
       } 
       i ++;
    }
    for (int k=0;k<len;k++){
        cout << result[k];
    }
    cout << endl;
    return 0;
}
