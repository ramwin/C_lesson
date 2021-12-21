int square(int x) {
    return x * 7;
};

int main() {
    int b = 14;
    int c = b + 1;
    b += square(c);
    return c;
}
