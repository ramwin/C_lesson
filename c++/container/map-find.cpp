#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;


map<int, tuple<int, string>> scores;


int main() {
  scores[3] = {1, "第1名"};
  scores[6] = {2, "第2名"};
  scores[9] = {3, "第3名"};
  cout << scores.find(9)->first << endl;
  cout << get<1>(scores.find(3)->second) << endl;
  cout << get<1>(scores[9]) << endl;
  cout << "直接用[]的地址是\t" << &scores[9] << endl;
  cout << "find后的地址是一致的\t" << &(scores.find(9)->second) << endl;
  // 为什么0的地址反而小
  cout << "find后的tuple的地址\t" << &get<0>(scores[9]) << endl;
  cout << "find后的tuple的地址\t" << &get<1>(scores[9]) << endl;
};
