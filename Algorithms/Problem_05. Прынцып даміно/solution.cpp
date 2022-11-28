#include <fstream>
#include <iostream>
#include <vector>

long long int func_domino(const int &nz, const std::vector<std::vector<int>>& nv, std::vector <bool> alr) {

    long long int res_time_r = 0, v_r= 0;
    alr[nz] = true;

    std::vector<int> v_tmp;
    v_tmp.emplace_back(nz);


    while (!v_tmp.empty()) {

        auto k = v_tmp.size();
        res_time_r++;
        v_r = (long long)k + v_r;

        for (int j = 0; j < k; j++) {

            int cm = v_tmp.front();
            v_tmp.erase(v_tmp.begin());
            for (int nxc : nv[cm]) {

                if (!alr[nxc]) {

                    alr[nxc] = true;
                    v_tmp.emplace_back(nxc);

                }

            }
        }

    }
    res_time_r--;

    if (nv.size() == v_r) return res_time_r;
    else return -1;
}

int main() {

    std::ifstream in("in.txt"); std::ofstream out("out.txt");

    int n, elm; in >> n;
    std::vector <std::vector<int>> vv(n);
    std::vector <bool> alr(vv.size(), false);

    for (int i = 0; i < n; ++i) {
        int tmp_; in >> tmp_;

        for (int j = 0; j < tmp_; ++j) {
            int _tmp; in >> _tmp; vv[i].emplace_back(_tmp - 1);
        }
    }

    auto res_time = -1;

    for (int i = 0; i < n; ++i) {

        auto tm_p = func_domino(i, vv, alr);
        if (tm_p >= res_time) {

            elm = i + 1;
            res_time = (int)tm_p;

        }

    }

    if (res_time != -1) {
        out << res_time << std::endl << elm;
        in.close(); out.close(); return 0;
    }

    out << "impossible";
    in.close(); out.close(); return 0;

}
