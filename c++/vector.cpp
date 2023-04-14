#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void print(const vector<char>& vec) {
  for (auto x: vec) {
    cout << ' ' << x;
  }
  cout << '\n';
};

void test1() {
  cout << "反向迭代" << endl;
  vector<char> a { 'a', 'b', 'c', 'd'};
  // a.push_back('a');
  // a.push_back('b');
  // a.push_back('c');
  for (auto i=a.rbegin(); i!=a.rend(); i++) {
    cout << *i;
  }
  cout << "\n";
};

void test_modify() {
  vector<char>::iterator pointer;
  vector<char> array {'a', 'b', 'c', 'd'};
  for (pointer=array.begin(); pointer!=array.end(); pointer++) {
    if (*pointer == 'b') {
      cout << "找到B\n";
      break;
    } else {
      cout << "找到了" << *pointer << "\n";
    }
  }
  cout << "插入1之前: pointer=" << *pointer << endl;
  print(array);
  pointer = array.insert(pointer, '1');
  cout << "%p\n" << &pointer << endl;
  cout << "插入1之后: pointer=" << *pointer << endl;
  print(array);
  cout << "size: " << array.size() << endl;
}

void test_iterator() {
  /*
  测试vector增加的时候, iterator会怎么样
  设想一:
    iterator保存的是距离index=0的距离和vector的变量地址. 所以vector变长时, iterator仍然可以用
  设想二:
    iterator保存的是真的元素所在的物理地址, 所以vector变长时, iterator不可以用. 但是这样性能好, iterator获取属性时, 不必做第二次的计算.

  结果, array变长的时候, *index数据不可知, &(*index)保持不变, 猜想二时正确的
  如果要保持vector不变, 可以考虑先reverse(比较大的数字), 或者通过保存数字的形式来保存iterator
  我猜为什么不用设想一, 也有可能是个人实现设想二比较困难, 实现设想一只要 for (int i=0; i<vector.size(); i++) 就可以, 比较简单
  查看资料的确如此: https://stackoverflow.com/questions/1624803/does-resizing-a-vector-invalidate-iterators
  */
  vector<int> array {1, 2, 3};
  vector<int>::iterator index = array.begin();
  index++;
  printf("array增长之前, &index=%p, *index=%d\n, &(*index)=%p\n", &index, *index, &(*index));
  printf("距离是: %lu\n", std::distance(array.begin(), index));
  for (int i=0; i<=100; i++) {
    array.push_back(i);
  }
  printf("array增长之后, &index=%p, *index=%d\n, &(*index)=%p\n", &index, *index, &(*index));
  printf("距离是: %lu\n", std::distance(array.begin(), index));
}


int main() {
    // test_modify();
    test_iterator();
};
