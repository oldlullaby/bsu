#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>


int three_min(const int &x, const int &y, const int &z)
{
    int min;
    if (x > y) min = y;
    else min = x;

    if (z > min) return min;
    else return z;
}

int main() {
    
    std::ifstream in("in.txt"); std::ofstream out("out.txt");

    int deletion = 0, insertion = 0, replacement = 0;

    std::string ss_1, ss_2;

    in >> deletion >> insertion >> replacement >> ss_1 >> ss_2;
    

    if (replacement > deletion + insertion) replacement = deletion + insertion;

    auto rows = ss_1.length() + 1;
    auto cols = ss_2.length() + 1;
    std::vector<std::vector<int>> total(rows, std::vector<int>(cols, 0));

    for (int j = 1; j < cols; j++) total[0][j] = j * insertion;
    for (int i = 1; i < rows; i++) total[i][0] = i * deletion;
    

    int diff;
    for (int i = 1; i < rows; i++) {
        
        for (int j = 1; j < cols; j++) {
            
            if (ss_1[i - 1] == ss_2[j - 1]) diff = 0;
            else diff = 1;

            total[i][j] = three_min(total[i - 1][j] + deletion,
                                    total[i][j - 1] + insertion,
                                    total[i - 1][j - 1] + diff * replacement);
        }
        
    }

    out << total[ss_1.length()][ss_2.length()] << "\n";

    return 0;
}
