#include <fstream>
#include <iostream>
#include <vector>
#include <list>

int main() {

    std::ifstream in("input.txt"); std::ofstream out("output.txt");

    int n, m; in >> n >> m;
    std::vector <std::list <int> > a(n);
    for (auto &i:a) i = std::list <int>();

    for (int k = 0; k < m; ++k) {

        int i; in >> i;
        int j; in >> j;

        a[i-1].emplace_front(j);
        a[j-1].emplace_front(i);

    }

    for (int i = 0; i < n; ++i) {

        out << a[i].size() << " ";
        for (const auto &j:a[i]) out << j << " ";
        out << std::endl;

    }

    in.close(); out.close();
    return 0;
}
