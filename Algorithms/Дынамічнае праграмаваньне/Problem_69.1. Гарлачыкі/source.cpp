#include <algorithm>
#include <fstream>
#include <iostream>

int main() {

    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    int n; in >> n;

    if (n == 2) {
        out << "-1" << std::endl;
        return 0;
    }

    if (n == 1) {
        int a; in >> a; out << a << std::endl;
        return 0;
    }

    int* arr1 = new int[n];
    for (int i = 0; i < n; ++i)
        in >> arr1[i];

    int* arr2 = new int[n];

    arr2[0] = arr1[0]; arr2[1] = -1;
    arr2[2] = arr2[0] + arr1[2];

    for (int i = 3; i < n; ++i)
        arr2[i] = arr1[i] + std::max(arr2[i - 2], arr2[i - 3]);

    out << arr2[n - 1] << std::endl;
    delete []arr1; delete []arr2;
    return 0;
}
