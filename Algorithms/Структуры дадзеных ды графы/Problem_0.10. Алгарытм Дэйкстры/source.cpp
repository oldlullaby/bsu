#include <fstream>
#include <iostream>
#include <limits>
#include <queue>

int main() {

    std::ifstream in("input.txt"); std::ofstream out("output.txt");
    long long int n, m; in >> n >> m;

    std::vector<std::vector<std::pair<long long int, long long int>>> v(n);
    std::priority_queue<std::pair<long long int, long long int>, std::vector<std::pair<long long int, long long int>>, std::greater<>> hv;

    long long int a, b, c;
    auto* ww = new long long int[n];

    for (int i = 0; i < m; ++i) {
        in >> a >> b >> c;
        v[a - 1].emplace_back(std::make_pair(b - 1, c)); v[b - 1].emplace_back(std::make_pair(a - 1, c));
    }

    for (int i = 0; i < n; ++i) ww[i] = std::numeric_limits<long long int>::max();

    hv.push(std::make_pair(0l, 0l));
    ww[0] = 0;

    while (!hv.empty()) {

        std::pair<long long int, long long int> tmp = hv.top();
        hv.pop();

        long long int f_r = tmp.first; long long int s_r = tmp.second;

        if (f_r > ww[s_r]) continue;

        for (std::pair<long long int, long long int> j : v[s_r]) {

            long long int f = j.first; long long int s = j.second;
            long long int r = f_r + s;

            if (ww[f] > r) {

                ww[f] = r;
                hv.push(std::make_pair(r, f));

            }
        }
    }

    out << ww[n - 1];
    in.close(); out.close();
    return 0;
}
