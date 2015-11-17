#include <iostream>
using namespace std;
int main(){
    char s1[80];
    char s2[80];
    cin.getline(s1,80);
    cin.getline(s2,80);
    char result;
    int i=0;
    while (s1[i] != '\0'){
        if ( (s1[i] >= 97 ) and (s1[i] <=122)){
            s1[i] -= 32;
        }
        if ( (s2[i] >= 97 ) and (s2[i] <=122)){
            s2[i] -= 32;
        }
        i++;
    }
    i=0;
    while (s1[i] != '\0' && (s1[i] == s2[i])){
        i++;
    }
    if (s1[i] >s2[i]){
        result ='>';
    } else if (s1[i]<s2[i]){
        result = '<';
    } else{
        result = '=';
    }
    cout << result;
    return 0;
}
