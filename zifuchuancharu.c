#include <iostream>
using namespace std;
int main(){
    char str[11]={};
    char substr[4]={};
    char finalstr[14]={};
    // 代表了之后插入的位置
    int position=0;
    char strs[15];
    while (cin.getline(strs,15,'\n')){
        int i=0;
        while (strs[i]!=' '){
            str[i] = strs[i];
            i++;
        }
        str[i] = '\0';
        i++;
        int j=0;
        while ( strs[i+j]!='\0' ){
            substr[j] = strs[i+j];
            j++;
        }
        substr[j] = '\0';
        // 获取了 str substr, 对其进行比较
        int k;
        for (k=1; k<i; k++){
            if (str[k] > str[position]) position=k;
        }
        int l;
        int finalposition=0;
        for (l=0; l<=position ; l++){
            finalstr[finalposition] = str[l];
            finalposition += 1;
        }
        int m=0;
        while (substr[m] != '\0' ) {
            finalstr[finalposition] = substr[m];
            finalposition += 1;
            m += 1;
        }
        while (str[l] != '\0') {
            finalstr[finalposition] = str[l];
            finalposition++;
            l++;
        }
        cout <<finalstr <<  endl;
    }
    return 0;
}
