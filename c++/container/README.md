# Containers

## iterator
如果container的尺寸变化了, 旧的iterator都会失效
* std::distance

```
vector<int>::iterator index = std::find(a.begin(), a.end(), 3);
printf("4的位置是: %lu", std::distance(a.begin(), index));
```

## [Map](https://en.cppreference.com/w/cpp/container/map)
```
std::map<std::string, int>
std::map<int, int> dict;
dict[2] = 3;
dict.count(2) == 0

// 迭代
for (const auto& [key, value] : m) {
    cout << '[' << key << "] = " << value << "; ";
};
```

* find
也可以直接用[key]获取
find返回的是iterator. 如果没找到，返回`end()`; 找到了，就存在`->first`和`->second`
first: map里的key
second: map里的value,这个second直接就是
* at
获取某个元素,如果不存在会报错
* `[]`
获取某个元素,如果不存在会自动插入0

## [Array](https://en.cppreference.com/w/cpp/container/array)
保存固定长度
```
std:array<int, 10> list;
std:array<char, 10> list;
#include <algorithm>
std:sort(std:array.begin(), std:array.end());
```

## Vector
[官网](https://en.cppreference.com/w/cpp/container/vector.html)
* 保存动态长度的列表  
* push的时候会把整个值复制到vector,不是指针  
* 重新assign的时候会把内存复制过去，并且清空当前所有的元素  
```
std:vactor<int> list = {1, 2, 3}
list2 = list  // 复制是复制所有内存
#include <algorithm>
std:sort(list.begin(), list.end());  // 排序
```

* `iterator insert( iterator pos, value)`
注意, 插入的时候, 如果最后的size大于vector的capacity, 会导致重新申请内存. 所以iterator pos就会失效

```
pointer = array.insert(pointer, value)  // 通过重新赋值,得到插入后的位置(pointer的相对偏移维持不变)
