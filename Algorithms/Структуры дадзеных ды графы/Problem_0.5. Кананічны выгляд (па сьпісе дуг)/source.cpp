#include <fstream>
#include <iostream>
#include <vector>

int main() {

    std::ifstream in("input.txt"); std::ofstream out("output.txt");

    int n; in >> n; std::vector<int> v(n);
    
    for (int k = 0; k < n - 1; ++k) {
        int i; in >> i;
        int j; in >> j; j--;
        v[j] = i;
    }
    
    for (const auto &i:v) out << i << " ";

    in.close(); out.close();
    return 0;
}
