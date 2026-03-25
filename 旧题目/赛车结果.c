#include <iostream>
/*
 * 题目描述（类似蓝桥杯/NOIP 入门题或公务员逻辑题）：
某比赛有 4 名选手（编号 1、2、3、4）参加，四人 A、B、C、D 对比赛结果进行预测：
A 说：冠军是 2 号
B 说：冠军是 4 号
C 说：冠军不是 3 号
D 说：冠军不是 4 号
已知条件：只有一个人说了真话，其他三人都在说假话。
问：冠军是几号？谁说了真话？
*/

using namespace std;
int A(int n){
    if (n==2) return 1;
    else return 0;
}
int B(int n){
    return n==4;
}
int C(int n){
    return n!=3;
}
int D(int n){
    return n!=4;
}
int main(){
    int saiche[4];
    int n;
    for (int i=1;i<=4;i++){
        if (A(i) + B(i) + C(i) + D(i) == 1){
            cout << i << endl;
            if (A(i)==1) cout <<'A' << endl;
            if (B(i)==1) cout <<'B' << endl;
            if (C(i)==1) cout <<'C' << endl;
            if (D(i)==1) cout <<'D' << endl;

        }
    }
    return 0;
}    
