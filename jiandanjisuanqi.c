#include <iostream>
using namespace std;
int main(){
    long int a,b;
    char act[100];
    // 获取输入
    cin >> a >> b;
    cin >> act;
    // 万一故意输入2个操作符号呢
    // 判断运算符是不是只有1位，如果输入的比较长直接报错
    if (act[1]!='\0') {
        cout<<"Invalid operator" <<endl;
        return 0;
    }
    // 运算符只有1位， 判断哪种情况
    switch(act[0]) {
        case '+' : cout << a + b << endl; break;  
        case '-' : cout << a - b << endl; break;
        case '*' : cout << a * b << endl; break;
        case '/' : {
            if (b==0) cout << "Divided by zero!" << endl;
            else cout << a/b << endl;
            } break;
        default: cout<< "Invalid operator!" <<endl; break;
    }
    return 0;
}
