#include <iostream>
using namespace std;

const int MOD = 1000000007;

long long digitSum(long long n) {
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

long long calculateSum(long long L, long long R) {
    long long sum = 0;
    for (long long i = L; i <= R; i++) {
        sum += digitSum(i);
        sum %= MOD;
    }
    return sum;
}

int main() {
    long long L, R;
    while (cin >> L >> R) {
        cout << calculateSum(L, R) << endl;
    }
    return 0;
}
