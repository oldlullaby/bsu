#include <fstream>
#include <iostream>
#include <vector>

int main() {

    std::ifstream in("input.txt"); std::ofstream out("output.txt");

    int n, m; in >> n >> m;
    std::vector <std::vector <int> > A(n);
    for (auto &i:A) i = std::vector <int> (n);

    for (int k = 0; k < m; ++k) {
        
        int i; in >> i; i--;
        int j; in >> j; j--;
        
        A[i][j] = 1;
        A[j][i] = 1;
        
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            out << A[i][j] << " ";
        }
        out << std::endl;
    }
    
    in.close(); out.close();
    return 0;
}
