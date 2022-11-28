#include <algorithm>
#include <fstream>
#include <vector>

int main() {

    std::ifstream in("input.txt"); std::ofstream out("output.txt");

    int n; in >> n;
    std::vector<long long int> leNta;
    std::vector <std::vector<long long int>> aus(n);
    std::vector <long long int> s(n + 1);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            aus[i].emplace_back(0);

    while (in) {
        int tmp; in >> tmp;
        leNta.push_back(tmp);
    }

    // ******* ******* ******* ******* ******* ******* ******* ******* *******

    s[0] = 0;
    for (int i = 0; i < n; ++i) s[i + 1] = s[i] + leNta[i];
    
    for (int i = 0; i < n; ++i)
        aus[i][i] = leNta[i];

    for (int i = 1; i < n; ++i)
        for (int j = 0; j < n - i; ++j) {

            if ( (leNta[i + j] + s[i + j] - s[j] - aus[j][i + j - 1]) <= (leNta[j] + s[i + j + 1] - s[j + 1] - aus[j + 1][i + j]) - 1)
                aus[j][i + j] = s[i + j + 1] + leNta[j] - s[j + 1] - aus[j + 1][i + j];
            
            else aus[j][i + j] = s[i + j] + leNta[i + j] - s[j] - aus[j][i + j - 1];
        
        }

    out << aus[0][n - 1];
    return 0;
}
