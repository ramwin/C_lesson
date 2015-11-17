# include <iostream>
using namespace std;

int main() {
    int n;
    for (cin >> n; n > 0; n--) {
        int x, ans = 0;
        cin >> x;
        while (x > 0) {
            ans += x % 2;
            x /= 2;
        }
        cout << ans << endl;
    }
    return 0;
}
