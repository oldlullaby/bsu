#include <iostream>
#include <fstream>
#include <vector>

int f(const int &k, const int &x, const int &a, const int &b) {
    return ((x % a) + b * k) % a;
}

int main(){

    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    int a, b, c;
    in >> a >> b >> c;

    std::vector <int> v(a);
    for (int i = 0; i < a; ++i) v[i] = -1;
    for (int j = 0; j < c; ++j) {
        int d; in >> d;
        for (int i = 0; i < a; i++) {
            int tmp = f(i, d, a, b);
            if (v[tmp] == d) break;
            if (v[tmp] == -1) {
                v[tmp] = d; break;
            }
        }
    }

    for (int i = 0; i < v.size() - 1; ++i)
        out << v[i] << " ";
    out << v[v.size() - 1];
    return 0;
}
