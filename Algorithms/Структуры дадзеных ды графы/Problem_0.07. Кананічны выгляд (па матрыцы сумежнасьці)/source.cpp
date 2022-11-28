#include <fstream>
#include <iostream>
#include <vector>

int main() {

    std::ifstream in("input.txt"); std::ofstream out("output.txt"); int n; in >> n;
    std::vector <std::vector <int> > a(n);
    
    
    for (auto &i:a) i = std::vector<int>(n);

    for (auto &i:a) for (auto &j:i) in >> j;

    std::vector <int> tmp (n);

    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (a[j][i]) tmp[i] = j+1;
    for (auto &i:tmp) out << i << " ";

    in.close(); out.close();
    return 0;
}
