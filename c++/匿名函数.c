#include <iostream>

int main() {
    int a = 1;
    int b = 2;
    int c;
    c = [](int x, int y){ return x+y; }(a, b);
    std::cout << "c=" << c << std::endl;
}
