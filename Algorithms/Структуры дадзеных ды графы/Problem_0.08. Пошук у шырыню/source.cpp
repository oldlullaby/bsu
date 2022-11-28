#include <fstream>
#include <iostream>
#include <vector>
#include <list>

int main() {

    std::ifstream in("input.txt"); std::ofstream out("output.txt"); int n; in >> n;

    std::vector <int> kz(n), v(n);
    std::vector <std::vector <int> > a(n);
    for (auto &i:a) i = std::vector<int>(n);

    int nz;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            in >> a[i][j];

    std::vector <int> krw;

    for (int k = 0; k < n; ++k) {

        if (!v[k]) {

            nz++; kz[k] = nz; v[k] = true;

            krw.emplace_back(k);
            while(!krw.empty()) {

                int zv = *krw.begin();
                krw.erase(krw.begin());

                for (int i = 0; i < n; ++i) {

                    if (a[zv][i] == 1) {
                        if (!v[i]) {
                            nz++; kz[i] = nz;
                            v[i] = true;
                            krw.emplace_back(i);
                        }
                    }

                }

            }

        }

    }


    for (const auto &i:kz) out << i << " ";


    in.close(); out.close();
    return 0;
}
