#include <iostream>
#include <fstream>
#include <vector>

int main() {

    std::ifstream in ("input.txt");
    std::ofstream out ("output.txt");

    int ZV; in >> ZV;
    std::vector <long long> VZ(ZV + 1);

    int c = 1;
    while (in) {
        in >> VZ[c];
        c++;
    }

    int k = 0;

    for (c = 1; c < ZV / 2 + 1; ++c){
        if ((2 * c < ZV + 1) && (VZ[2 * c] < VZ[ c])) {
            k = 1; break;
        }

        if ((2 * c < ZV) && (VZ[2 * c + 1] < VZ[c])) {
            k = 1; break;
        }
    }
    
    if (k == 1) out << "No";
    else out << "Yes";

    return 0;
}
