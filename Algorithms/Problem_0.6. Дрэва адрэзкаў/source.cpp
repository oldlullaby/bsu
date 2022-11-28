#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

std::vector <long long int> v_1(300000), v_2(300000), v_3(300000), v_4(300000);
long long int func_min(const long long int &v, const long long int &ll, const long long int &rr,
                       const long long int &l_r, const long long int &r_r) {

    if (rr < ll) return std::numeric_limits<long long int>::max();
    if (rr == r_r && ll == l_r) return v_2[v];

    return v_4[v] + std::min(func_min(1 + 2 * v, ll, std::min((r_r - l_r) / 2 + l_r, rr), l_r, (r_r - l_r) / 2 + l_r),
                    func_min(2 + 2 * v, std::max((r_r - l_r) / 2 + l_r + 1, ll), rr,(r_r - l_r) / 2 + l_r + 1, r_r));

}

long long int func_max(const long long int &kmp, const long long int &ll,
                       const long long int &rr, const long long int &l_r, const long long int &r_r) {
    if (rr < ll) return (-1) * std::numeric_limits<long long int>::max();
    if (rr == r_r && ll == l_r) return v_3[kmp];

    return v_4[kmp] + std::max(func_max(1 + 2 * kmp, ll, std::min((r_r - l_r) / 2 + l_r, rr), l_r, (r_r - l_r) / 2 + l_r),
                               func_max(2 + 2 * kmp, std::max((r_r - l_r) / 2 + 1 + l_r, ll), rr, (r_r - l_r) / 2 + l_r + 1, r_r));
}

long long int atrymac(const long long int &tmp, const long long int &nr,
                      const long long int &lz, const long long int &rz, const long long int &xjc) {

    if (nr == rz && nr == lz) return xjc + v_4[tmp] + v_1[tmp];
    if (lz + (rz - lz) / 2 >= nr) return atrymac(1 + 2 * tmp, nr, lz, (rz - lz) / 2 + lz, v_4[tmp] + xjc);
    else return atrymac(2 + 2 * tmp, nr, lz + 1 + (rz - lz) / 2, rz, v_4[tmp] + xjc);

}

long long int padlik(const long long int &k, const long long int &l_l, const long long int &r_r,
                     const long long int &ll, const long long int &rr, const long long int &fd) {
    if (r_r < l_l) return 0;
    if (r_r == rr && l_l == ll) return (v_4[k] + fd) * (r_r + 1 - l_l) + v_1[k];

    return padlik(1 + 2 * k, l_l, std::min((rr - ll) / 2 + ll, r_r), ll, (rr - ll) / 2 + ll, v_4[k] + fd) +
           padlik(2 + 2 * k, std::max((rr - ll) / 2 + ll + 1, l_l), r_r, ll + 1 + (rr - ll) / 2, rr, v_4[k] + fd);
}

void func_add(const long long int &i, const long long int &l,
              const long long int &r, const long long int &l_l,
              const long long int &r_r, const long long &tmp) {

    if (l > r) return;
    if (l == l_l && r == r_r) {
        v_2[i] = v_2[i] + tmp; v_3[i] = v_3[i] + tmp; v_4[i] = v_4[i] + tmp; return;
    }

    func_add( 1 + 2 * i, l, std::min(r, (r_r - l_l) / 2 + l_l), l_l, (r_r - l_l) / 2 + l_l, tmp);
    func_add(2 + i * 2, std::max(1 + l_l + (r_r - l_l) / 2, l), r, 1 + (r_r - l_l) / 2 + l_l, r_r, tmp);

    v_1[i] = tmp * (r + 1 - l) + v_1[i];
    v_2[i] = v_4[i] + std::min(v_2[1 + 2 * i], v_2[2 + 2 * i]);
    v_3[i] = v_4[i] + std::max(v_3[1 + 2 * i], v_3[2 + 2 * i]);
}

void ed(const long long int &i, const long long int &index,
        const long long int &vi, const long long int &l_r,
        const long long int &r_r) {

    long long int p = atrymac(0, index, l_r, r_r, 0);
    func_add(0, index, index, l_r, r_r, p * (-1));
    func_add(0, index, index, l_r, r_r, vi);

}

int main() {

    std::ifstream in ("input.txt");
    std::ofstream out ("output.txt");

    int n; in >> n;

    int krw = std::numeric_limits<int>::min();
    while (krw) {
        in >> krw;
        long long int v, x, y, z;
        switch (krw) {

            case 1: in >> z >> v; ed(0, z, v, 0, n - 1); break;
            case 2: in >> x >> y >> v; func_add(0, x, y, 0, n - 1, v); break;
            case 3: in >> x >> y; out << padlik(0, x, y, 0, n - 1, 0) << std::endl; break;
            case 4: in >> x >> y; out << func_min(0, x, y, 0, n - 1) << std::endl; break;
            case 5: in >> x >> y; out << func_max(0, x, y, 0, n - 1) << std::endl; break;
            default: break;

        }
    }
    in.close(); out.close(); return 0;

}
