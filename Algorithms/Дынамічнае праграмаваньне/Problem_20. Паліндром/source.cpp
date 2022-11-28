#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {

    auto arr = new long long int [7001][7001];

    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    std::string ss, arz;

    in >> ss; arz = ss;
    std::reverse(arz.begin(), arz.end());

    ss = " " + ss; arz = " " + arz;

    long long int len_r = ss.size();

    for (long long int i = 1; i < len_r; i++)
        for (long long int j = 1; j < len_r; j++)
            if (ss[i] == arz[j]) arr[i][j] = 1 + arr[i - 1][j - 1];
            else arr[i][j] = std::max(arr[i - 1][j], arr[i][j - 1]);


    long long int a = len_r - 1; long long int b = len_r - 1;
    std::string answ;

    while (arr[a][b] > 0) {
        if (ss[a] == arz[b]) {

            answ += ss[a];
            a--; b--;

        } else if (arr[a][b - 1] < arr[a - 1][b]) a--;
        else b--;

    }

    out << answ.size() << std::endl;
    out << answ << std::endl;

    return 0;
}
