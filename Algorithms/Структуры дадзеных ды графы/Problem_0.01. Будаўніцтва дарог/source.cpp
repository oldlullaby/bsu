#include <fstream>
#include <iostream>
#include <vector>

struct qp {

    long long int t;
    std::vector <long long int> s, p;

    explicit qp(const long long int &n) {

        s.resize(n + 1);
        p.resize(n + 1);
        for (auto i = 1; i < n + 1; ++i) {

            s[i] = 1;
            p[i] = i;

        }
        t = n;
    }

    [[nodiscard]] long long int fnc(const long long int &x) const{

        if (x == p[x]) return x;
        return fnc(p[x]);

    }

    void problem_road(const long long int &x, const long long int &y) {

        if (fnc(x) != fnc(y)) {

            long long int a, b;
            a = fnc(x); b = fnc(y);
            if (s[fnc(x)] < s[fnc(y)]) std::swap(a, b);

            t = t - 1;
            p[b] = a;
            s[a] = s[a] + s[b];
        }
    }
};

int main() {

    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    long long int n_1, n_2, tmp_1, tmp_2;

    in >> n_1 >> n_2;
    qp ala(n_1);

    for (auto i = 0; i < n_2; ++i){

        in >> tmp_1 >> tmp_2;
        ala.problem_road(tmp_1, tmp_2);
        out << ala.t << std::endl;

    }

    return 0;
}
