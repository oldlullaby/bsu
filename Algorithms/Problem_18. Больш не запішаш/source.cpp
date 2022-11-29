#include <fstream>
#include <iostream>
#include <vector>

void func (std::vector <long long int> &v_r, const long long int &n_r,
           const long long int &k_r, long long int &answ_r) {
    
    v_r[0] = k_r; v_r[1] = k_r * k_r;
    answ_r = v_r[1] + k_r;

    for (auto i = 2; i < n_r; ++i) {

        v_r[i] = k_r * (v_r[i - 1] + v_r[i - 2]);
        answ_r = answ_r + v_r[i];

    }

}

int main() {

    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    long long int n, k, answ;
    in >> k >> n;

    std::vector <long long int> v(n);
    func(v, n, k, answ);
    out << answ;

    return 0;

}
