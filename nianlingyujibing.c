#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n;
    cin >> n;
    int age[n];
    double nianlingduan[4]={0,0,0,0};
    for (int i=0 ; i<n; i++){
        cin >> age[i];
        if (      age[i] <= 18) nianlingduan[0] += 1;
        if (19 <= age[i] && age[i] <= 35) nianlingduan[1] += 1;
        if (36 <= age[i] && age[i] <= 60) nianlingduan[2] += 1;
        if (60 <  age[i]      ) nianlingduan[3] += 1; 
    }
    cout << "1-18: "  << fixed << setprecision(2) << nianlingduan[0]*100/n << '%' << endl;
    cout << "19-35: " << fixed << setprecision(2) << nianlingduan[1]*100/n << '%' << endl;
    cout << "36-60: " << fixed << setprecision(2) << nianlingduan[2]*100/n << '%' << endl;
    cout << "60-: "   << fixed << setprecision(2) << nianlingduan[3]*100/n << '%' << endl;
    return 0;
}    
