#include <iostream>

const int const_mod = 1e9 + 7;

unsigned long long int binary_vozv(unsigned long long int a, int n) {
    int result = 1;
    while (n != 0) {
        if (n & 1) result = result * a % const_mod;
        a = a * a % const_mod;
        n >>= 1;
    }
    return result;
}

unsigned long long int inverse(const unsigned long long int &x) {
    return binary_vozv(x, const_mod - 2);
}

unsigned long long int combinations(const int &n, const int &k, const unsigned long long int *t) {
    return t[n] * inverse(t[k] * t[n - k] % const_mod) % const_mod;
}

int main() {
    int N, K;
    std::cin >> N >> K;
    unsigned long long int t[N + 1]; t[0] = 1;
    for (auto i = 1; i <= N; ++i)
        t[i] = t[i - 1] * i % const_mod;

    std::cout << combinations(N, K, t) << std::endl;
    return 0;
}

