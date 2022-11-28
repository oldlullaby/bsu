#include <iostream>

unsigned long long int binary_vozv(unsigned long long int a, unsigned long long int n,
        const unsigned long long int &c_mod) {

    unsigned long long int result = 1;
    while (n != 0) {
        if (n & 1) result = result * a % c_mod;
        a = a * a % c_mod;
        n >>= 1;
    }
    return result;
}

int main() {

    const unsigned long long int const_mod = 1e9 + 7;
    unsigned long long int N, K;
    std::cin >> N >> K;
    auto *t = new unsigned long long [N+1];
    t[0] = 1;
    for (auto i = 1; i <= N; ++i)
        t[i] = t[i - 1] * i % const_mod;

    std::cout << t[N] * binary_vozv(t[K] * t[N - K] % const_mod, const_mod - 2, const_mod) % const_mod << std::endl;
    return 0;
}
